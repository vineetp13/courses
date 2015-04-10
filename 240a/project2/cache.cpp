#include "cache.h"
#include<cmath>

#define L1SIZE 4096 //16384//65536//32768//16384//4096
#define L1ASC 2
#define L1BLK 16

#define VICTIMSIZE 512//512//1024//8192//1024
#define VICTIMASC 2
#define VICTIMBLK 16

#define L2SIZE 204800//204800//262184//204800//200000//262144 //8192 
#define L2ASC 2
#define L2BLK 32

#define EVPOL 0

/* Fill this in with parameters that will give you the
   best CPI and AMAT. */
void tune_parameters(Core *c) {
	c->setL1Attributes(L1SIZE, L1ASC, L1BLK);
	c->setVictimAttributes(VICTIMSIZE, VICTIMASC, VICTIMBLK);
	c->setL2Attributes(L2SIZE, L2ASC, L2BLK);
	c->setEvictionPolicy(EVPOL);
}

/* Implement this function. 
 * Returns true if there is a cache hit.
 * Arguments: ldst - 0 if load, 1 if store.
 *            address - Memory address of the reference.
 *            cycle - Number of cycles executed so far.
 */
bool Cache::isHit(int ldst, int address, int cycle) {
    int numsets = (int) (size/(blockSize * assoc));
    int numtagbits = (int) (log2(size) - log2(numsets) - log2(blockSize));
    int addr_index = ((address >> ((int) log2(blockSize))) & (numsets-1));
    int addr_tag = (address >> (int) log2(blockSize * numsets)) & ((size-1) >> ((int) log2(blockSize * numsets)));

	printf("size=%d, blockSize=%d, assoc=%d\n",size, blockSize, assoc);
	printf("log2(size)=%f, log2(numsets)=%f, log2(blockSize)=%f \n",log2(size), log2(numsets), log2(blockSize));   
	printf("address=%x, cycle=%d, numsets=%d, numtagbits=%d, addr_index=%x, addr_tag=%x \n", address, cycle, numsets, numtagbits, addr_index,addr_tag);


 
    for (int i=0;i<assoc;i++){
        if(tag[addr_index][i] == addr_tag){
//Update cycle value
           accessed[addr_index][i] = cycle;
            return true;}
    }
//Not hit
printf("L1hit = FALSE \n");
    return false;
}

/* Implement this function.
 * Returns the number of cycles taken to perform the memory reference.
 * Arguments: ldst - 0 if load, 1 if store.
 *            address - Memory address of the reference.
 *            cycle - Number of cycles executed so far.
 * Function calls you might make: isHit, getters in Cache.
 * Data structures you might need to read and/or update: 
 *           tags and accessed arrays in Cache.
 */
int Core::accessCache(int ldst, int address, int cycles) {
//Set of values to be potentially used while moving data
//Using a class would have saved on all this redundant code
// Terrible code - Apologies
    int L1numsets = (int) (L1.getSize()/(L1.getBlockSize() * L1.getAssociativity()));
    int L1numtagbits = log2(L1.getSize()) - log2(L1numsets) - log2(L1.getBlockSize());
    int L1addr_index = ((address >> ((int) log2(L1.getBlockSize()))) & (L1numsets-1));
    int L1addr_tag = (address >> (int) log2(L1.getBlockSize() * L1numsets)) & ((L1.getSize()-1) >> ((int) log2(L1.getBlockSize() * L1numsets)));
    
    int L2numsets = (int) (L2.getSize()/(L2.getBlockSize() * L2.getAssociativity()));
    int L2numtagbits = log2(L2.getSize()) - log2(L2numsets) - log2(L2.getBlockSize());
    int L2addr_index = ((address >> ((int) log2(L2.getBlockSize()))) & (L2numsets-1));
    int L2addr_tag = (address >> (int) log2(L2.getBlockSize() * L2numsets)) & ((L2.getSize()-1) >> ((int) log2(L2.getBlockSize() * L2numsets)));

//Access L1
    l1Accesses++; 
    if ((L1.isHit(ldst,address,cycles)) == false){
        l1Misses++;
//Access Victim 
	victimAccesses++;
	if (Victim.isHit(ldst,address,cycles) == false){
		victimMisses++;
//Access L2
		l2Accesses++; 
        	if(L2.isHit(ldst,address,cycles) == false){
			l2Misses++;
//Access memory		
			totalMemRef++;            

//Insert in L2
			int L2_oldest_cycle = L2.accessed[L2addr_index][0];
			int L2_oldest_cycle_index = -1;

    			for (int i=0;i<L2.getAssociativity();i++){
//if there is an empty line, fill it
        			if(L2.accessed[L2addr_index][i] == 0){
					L2.accessed[L2addr_index][i] = cycles;
 					L2.tag[L2addr_index][i] = L2addr_tag;}
//otherwise, look for the oldest block in the set and rewrite it
				else{
					if(L2_oldest_cycle > L2.accessed[L2addr_index][i]){
						L2_oldest_cycle_index = i;
						L2_oldest_cycle = L2.accessed[L2addr_index][i];}}}
			if(L2_oldest_cycle_index!=-1){
				L2.accessed[L2addr_index][L2_oldest_cycle_index] = cycles;
 				L2.tag[L2addr_index][L2_oldest_cycle_index] = L2addr_tag;}

//Insert the same data in L1
			int L1_oldest_cycle_index = -1;
			int L1_oldest_cycle = L1.accessed[L1addr_index][0];
//Variables to keep note of the values which will be swapped out to victim cache
			int L1_swap_addr_index=0;
			int L1_swap_addr_tag=0;
			//int L1_swap_cycles=0;

    			for (int i=0;i<L1.getAssociativity();i++){
//if there is an empty line, fill it
//Nothing gets evicted, no writes to Victim
        			if(L1.accessed[L1addr_index][i] == 0){
					L1.accessed[L1addr_index][i] = cycles;
 					L1.tag[L1addr_index][i] = L1addr_tag;}
//otherwise, look for the oldest block and swap it out
				else{
					if(L1_oldest_cycle > L1.accessed[L1addr_index][i]){
						L1_oldest_cycle_index = i;
						L1_oldest_cycle = L1.accessed[L1addr_index][i];
						L1_swap_addr_index = L1addr_index;
						L1_swap_addr_tag = L1.tag[L1addr_index][i];
						}}}
			if(L1_oldest_cycle_index!=-1){
				L1.accessed[L1addr_index][L1_oldest_cycle_index] = cycles;
 				L1.tag[L1addr_index][L1_oldest_cycle_index] = L1addr_tag;
//Insert the swapped out data in Victim
//Recereate the original address information in the event that victim cache has different block size than L1 cache
			int swap_address = (((L1_swap_addr_tag << (int) (log2(L1numsets) + log2(L1.getBlockSize())))) + (L1_swap_addr_index << (int) (log2(L1.getBlockSize())))) ;
			int swap_cycles = L1_oldest_cycle;

    			int Victimnumsets = (int) (Victim.getSize()/(Victim.getBlockSize() * Victim.getAssociativity()));
    			int Victimnumtagbits = log2(Victim.getSize()) - log2(Victimnumsets) - log2(Victim.getBlockSize());
    			int Victimaddr_index = ((swap_address >> ((int) log2(Victim.getBlockSize()))) & (Victimnumsets-1));
    			int Victimaddr_tag = (swap_address >> (int) log2(Victim.getBlockSize() * Victimnumsets)) & ((Victim.getSize()-1) >> ((int) log2(Victim.getBlockSize() * Victimnumsets)));
    
			int Victim_oldest_cycle = Victim.accessed[Victimaddr_index][0];
			int Victim_oldest_cycle_index = -1;

    			for (int i=0;i<Victim.getAssociativity();i++){
//if there is an empty line, fill it
        			if(Victim.accessed[Victimaddr_index][i] == 0){
					Victim.accessed[Victimaddr_index][i] = swap_cycles;
 					Victim.tag[Victimaddr_index][i] = Victimaddr_tag;}
//otherwise, look for the oldest block and rewrite it
				else{
					if(Victim_oldest_cycle > Victim.accessed[Victimaddr_index][i]){
						Victim_oldest_cycle_index = i;
						Victim_oldest_cycle = Victim.accessed[Victimaddr_index][i];}}}
			if(Victim_oldest_cycle_index!=-1){
				Victim.accessed[Victimaddr_index][Victim_oldest_cycle_index] = swap_cycles; //cycles;
 				Victim.tag[Victimaddr_index][Victim_oldest_cycle_index] = Victimaddr_tag;}}
				
//Since memory has been accessed, the total cost is memoryAccessTime 
            		return (memoryAccessTime);}

//Pull data from L2 to L1, might swap page out from L1
//L2 value was updated in isHit()        	

//Insert in L1
			int L1_oldest_cycle_index = -1;
			int L1_oldest_cycle = L1.accessed[L1addr_index][0];
//Variables to keep note of the values which will be swapped out to victim cache
			int L1_swap_addr_index=0;
			int L1_swap_addr_tag=0;
			//int L1_swap_cycles=0;

    			for (int i=0;i<L1.getAssociativity();i++){
//if there is an empty line, fill it
//Nothing gets evicted, no writes to Victim
        			if(L1.accessed[L1addr_index][i] == 0){
					L1.accessed[L1addr_index][i] = cycles;
 					L1.tag[L1addr_index][i] = L1addr_tag;}
//otherwise, look for the oldest block and swap it out
				else{
					if(L1_oldest_cycle > L1.accessed[L1addr_index][i]){
						L1_oldest_cycle_index = i;
						L1_oldest_cycle = L1.accessed[L1addr_index][i];
						L1_swap_addr_index = L1addr_index;
						L1_swap_addr_tag = L1.tag[L1addr_index][i];
						//L1_swap_cycles = L1.accessed[L1addr_index][i];
						}}}
			if(L1_oldest_cycle_index!=-1){
				L1.accessed[L1addr_index][L1_oldest_cycle_index] = cycles;
 				L1.tag[L1addr_index][L1_oldest_cycle_index] = L1addr_tag;

 //Insert in Victim
//Recereate the original address information in the event that victim cache has different block size than L1 cache
			int swap_address = (((L1_swap_addr_tag << (int) (log2(L1numsets) + log2(L1.getBlockSize())))) + (L1_swap_addr_index << (int) (log2(L1.getBlockSize())))) ;
			int swap_cycles = L1_oldest_cycle;

    			int Victimnumsets = (int) (Victim.getSize()/(Victim.getBlockSize() * Victim.getAssociativity()));
    			int Victimnumtagbits = log2(Victim.getSize()) - log2(Victimnumsets) - log2(Victim.getBlockSize());
    			int Victimaddr_index = ((swap_address >> ((int) log2(Victim.getBlockSize()))) & (Victimnumsets-1));
    			int Victimaddr_tag = (swap_address >> (int) log2(Victim.getBlockSize() * Victimnumsets)) & ((Victim.getSize()-1) >> ((int) log2(Victim.getBlockSize() * Victimnumsets)));
    
			int Victim_oldest_cycle = Victim.accessed[Victimaddr_index][0];
			int Victim_oldest_cycle_index = -1;

    			for (int i=0;i<Victim.getAssociativity();i++){
//if there is an empty line, fill it
        			if(Victim.accessed[Victimaddr_index][i] == 0){
					Victim.accessed[Victimaddr_index][i] = swap_cycles;
 					Victim.tag[Victimaddr_index][i] = Victimaddr_tag;}
//otherwise, look for the oldest block and rewrite it
				else{
					if(Victim_oldest_cycle > Victim.accessed[Victimaddr_index][i]){
						Victim_oldest_cycle_index = i;
						Victim_oldest_cycle = Victim.accessed[Victimaddr_index][i];}}}
			if(Victim_oldest_cycle_index!=-1){	
				Victim.accessed[Victimaddr_index][Victim_oldest_cycle_index] = swap_cycles; //cycles;
 				Victim.tag[Victimaddr_index][Victim_oldest_cycle_index] = Victimaddr_tag;}}
				
//Since L2 gets a hit, total cost = L1L2Transfer + L2.latency
		return (L1L2Transfer + L2.getHitLatency());}

//Victim cache supplies the data, this value needs to be inserted in L1 now which might lead to swapping of data to victim
//Insert in L1
			int L1_oldest_cycle_index = -1;
			int L1_oldest_cycle = L1.accessed[L1addr_index][0];
//Variables to keep note of the values which will be swapped out to victim cache
			int L1_swap_addr_index=0;
			int L1_swap_addr_tag=0;
			//int L1_swap_cycles=0;

    			for (int i=0;i<L1.getAssociativity();i++){
//if there is an empty line, fill it
//Nothing gets evicted, no writes to Victim
// Realistically this case won't happen since the L1 will never have corresponding empty line when the victim cache has an entry
        			if(L1.accessed[L1addr_index][i] == 0){
					L1.accessed[L1addr_index][i] = cycles;
 					L1.tag[L1addr_index][i] = L1addr_tag;}
//otherwise, look for the oldest block and swap it out
				else{
					if(L1_oldest_cycle > L1.accessed[L1addr_index][i]){
						L1_oldest_cycle_index = i;
						L1_oldest_cycle = L1.accessed[L1addr_index][i];
						L1_swap_addr_index = L1addr_index;
						L1_swap_addr_tag = L1.tag[L1addr_index][i];
						//L1_swap_cycles = L1.accessed[L1addr_index][i];
						}}}
			if(L1_oldest_cycle_index!=-1){
				L1.accessed[L1addr_index][L1_oldest_cycle_index] = cycles;
 				L1.tag[L1addr_index][L1_oldest_cycle_index] = L1addr_tag;

 //Insert in Victim
//Recereate the original address information in the event that victim cache has different block size than L1 cache
			int swap_address = (((L1_swap_addr_tag << (int) (log2(L1numsets) + log2(L1.getBlockSize())))) + (L1_swap_addr_index << (int) (log2(L1.getBlockSize())))) ;
			int swap_cycles = L1_oldest_cycle;

    			int Victimnumsets = (int) (Victim.getSize()/(Victim.getBlockSize() * Victim.getAssociativity()));
    			int Victimnumtagbits = log2(Victim.getSize()) - log2(Victimnumsets) - log2(Victim.getBlockSize());
    			int Victimaddr_index = ((swap_address >> ((int) log2(Victim.getBlockSize()))) & (Victimnumsets-1));
    			int Victimaddr_tag = (swap_address >> (int) log2(Victim.getBlockSize() * Victimnumsets)) & ((Victim.getSize()-1) >> ((int) log2(Victim.getBlockSize() * Victimnumsets)));
    
			int Victim_oldest_cycle = Victim.accessed[Victimaddr_index][0];
			int Victim_oldest_cycle_index = -1;

    			for (int i=0;i<Victim.getAssociativity();i++){
//if there is an empty line, fill it
        			if(Victim.accessed[Victimaddr_index][i] == 0){
					Victim.accessed[Victimaddr_index][i] = swap_cycles;
 					Victim.tag[Victimaddr_index][i] = Victimaddr_tag;}
//otherwise, look for the oldest block and rewrite it
				else{
					if(Victim_oldest_cycle > Victim.accessed[Victimaddr_index][i]){
						Victim_oldest_cycle_index = i;
						Victim_oldest_cycle = Victim.accessed[Victimaddr_index][i];}}}
			if(Victim_oldest_cycle_index!=-1){
				Victim.accessed[Victimaddr_index][Victim_oldest_cycle_index] = swap_cycles; //cycles;
 				Victim.tag[Victimaddr_index][Victim_oldest_cycle_index] = Victimaddr_tag;}

}

//Update L2 accessed value 
			    for (int i=0;i<L2.getAssociativity();i++){
				if(L2.tag[L2addr_index][i] == L2addr_tag){
           				L2.accessed[L2addr_index][i] = cycles;
            				break;}}
    			
//Since Victim serves the hit, cost = victim.latency
	//int L1_victim_latency = (L1.getHitLatency() > Victim.getHitLatency())?Victim.getHitLatency():L1.getHitLatency();
	return Victim.getHitLatency();}	
//return L1_victim_latency;}

//Simplest case: L1 serves the data, nothing needs to be done except updating accessed, which happes in isHit and here
//Update L2 accessed value 
			    for (int i=0;i<L2.getAssociativity();i++){
				if(L2.tag[L2addr_index][i] == L2addr_tag){
           				L2.accessed[L2addr_index][i] = cycles;
            				break;}}
//Since L1 serves the hit, cost = L1.Latency
return L1.getHitLatency();
}

/* Implement the following functions. */
double Core::getL1MissRate() {
	printf("l1Misses %d \n l1Accesses %d \n", l1Misses, l1Accesses);
    return ((double)l1Misses/(double)l1Accesses);
}
double Core::getVictimLocalMissRate() {
 printf(" victimMisses %d \n victimAccesses %d \n",victimMisses, victimAccesses); 
   return (double)victimMisses/(double)victimAccesses; 
}
double Core::getL2LocalMissRate() {
 printf("l2Misses %d \n l2Accesses %d \n", l2Misses, l2Accesses);
    return (double)l2Misses/(double)l2Accesses;
}
double Core::getL2GlobalMissRate() {
    return ((double)getL1MissRate() * (double)getVictimLocalMissRate() * (double)getL2LocalMissRate());
}
