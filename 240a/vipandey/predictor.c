//Predictor name - PREDETAH - EATING 'EM BRANCHES UP

#include<stdio.h>

#define PHT_SIZE 1024 
#define BHT_SIZE 16384 
#define GHR_SIZE 13 //unused so far

//PHT has 1024 entries, each with 10 bits to maintain history. History bits are simulated by int. Overall size (theoretically) = 30K 
//BHT has 16384  entries, each with 2 bit saturating counter. Saturating counter is simulated by int. Size (theoretically) = 2K

 int PHT[PHT_SIZE];
 int BHT[BHT_SIZE];
 int GHR;

//Initializing the PHT and BHT values
void init_predictor (){
 int i=0;

//initializing all entries in PHT to be 0 to begin with. This refers to beginning with ten history bits saying branch not taken
 for (i=0; i<PHT_SIZE;i++){
	PHT[i]=0;}

//Setting BHT default value to 2, which implies weakly taken. (Could have used enum but lazy)
 for (i=0; i<BHT_SIZE;i++){
	BHT[i]=0;}

//initializing GHR
 GHR=0;

 return ;
}

bool make_prediction (unsigned int pc)
{
 int PHT_index = (int) (pc & (PHT_SIZE - 1)); //picking up the least significant required bits of PC

// Picking up the least significant required bits from PHT entry to find BHT index
 //int BHT_index = (PHT[PHT_index] & (BHT_SIZE-1));
 int BHT_index = ((pc^GHR) & (BHT_SIZE-1));
 //int BHT_index = (GHR & (BHT_SIZE-1));

//If BHT = 2 or 3, predict taken, else not taken 
// This is not "tight" code, switch statement would be better, lazy.  
if ((BHT[BHT_index]) > 1)
	return 1;
else
	return 0;
}

void train_predictor (unsigned int pc, bool outcome)
{
 int PHT_index = (pc & (PHT_SIZE - 1));

 //int BHT_index = (PHT[PHT_index] & (BHT_SIZE-1));
 int BHT_index = ((pc^GHR) & (BHT_SIZE-1));
 //int BHT_index = (GHR & (BHT_SIZE-1));

//Updating BHT
//if the branch was actually taken, then increment the saturating counter, unless it's already 3 (strongly taken)
//do the 'opposite' symmetric thing for the else condition
if (outcome){
	switch (BHT[BHT_index]){
		case 0: (BHT[BHT_index])++; break;
		case 1: (BHT[BHT_index])++; break;
		case 2: (BHT[BHT_index])++; break;
		case 3: break;}}

else{
	switch (BHT[BHT_index]){
		case 0: break;
		case 1: (BHT[BHT_index])--; break;
		case 2: (BHT[BHT_index])--; break;
		case 3: (BHT[BHT_index])--; break;}}

//Updating PHT and GHR
	PHT[PHT_index] <<= 1;
	PHT[PHT_index] = PHT[PHT_index] | outcome;

	GHR <<= 1;
	GHR |= outcome;

 return ;
}
