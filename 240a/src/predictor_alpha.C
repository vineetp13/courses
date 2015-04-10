//Predictor name - PREDETAH - EATING 'EM BRANCHES UP

#include<stdio.h>

#define PHT_SIZE 1024 
//#define BHT_SIZE 16384 
//#define GHR_SIZE 13 //unused so far

#define BHT1_SIZE 2048
#define BHT2_SIZE 4096
#define CHOICE_SIZE 4096

//PHT has 1024 entries, each with 10 bits to maintain history. History bits are simulated by int. Overall size (theoretically) = 30K 
//BHT has 16384  entries, each with 2 bit saturating counter. Saturating counter is simulated by int. Size (theoretically) = 2K

 int PHT[PHT_SIZE];
 int BHT1[BHT1_SIZE]; //local BHT
 int BHT2[BHT2_SIZE]; //global BHT
 int CHOICE[CHOICE_SIZE];
 int GHR;

//Initializing the PHT and BHT values
void init_predictor (){
 int i=0;

//initializing all entries in PHT to be 0 to begin with. This refers to beginning with ten history bits saying branch not taken
 for (i=0; i<PHT_SIZE;i++){
	PHT[i]=0;}

//Setting BHT default value to 2, which implies weakly taken. (Could have used enum but lazy)
 for (i=0; i<BHT1_SIZE;i++){
	BHT1[i]=0;}

//Initializing BHT global 
 for (i=0; i<BHT2_SIZE;i++){
	BHT2[i]=0;}

//initializing GHR
 GHR=0;

//initializing choice_predictor
 for(i=0;i<CHOICE_SIZE;i++){
	CHOICE[i]=0;}
 return ;
}

bool make_prediction (unsigned int pc)
{
 int choice_index = ((GHR) & (CHOICE_SIZE-1));
 bool predictor = ((CHOICE[choice_index] & 10) >> 1);
 int PHT_index = (int) (pc & (PHT_SIZE - 1)); //picking up the least significant required bits of PC
 
 switch ((int) predictor){
	case 0:{ //local
	// Picking up the least significant required bits from PHT entry to find BHT index
 	int BHT1_index = (PHT[PHT_index] & (BHT1_SIZE-1));
 	//int BHT_index = ((pc^GHR) & (BHT_SIZE-1));
 	//int BHT_index = (GHR & (BHT_SIZE-1));
	return ((BHT1[BHT1_index] & 100) >> 2);
	break;}

	case 1:{ //global (gshare)
 	int BHT2_index = ((GHR) & (BHT2_SIZE-1));
	return ((BHT2[BHT2_index] & 10) >> 1);
	break;}}

//If BHT = 2 or 3, predict taken, else not taken 
// This is not "tight" code, switch statement would be better, lazy.  

//if ((BHT[BHT_index]) > 1)
//	return 1;
//else
//	return 0;
}

void train_predictor (unsigned int pc, bool outcome)
{
 int choice_index = ((GHR) & (CHOICE_SIZE-1));
 bool predictor = ((CHOICE[choice_index] & 10) >> 1);
 int PHT_index = (pc & (PHT_SIZE - 1));

 int choice_predictor=CHOICE[choice_index];
 
 switch ((int) predictor){
	case 0:{ //local
 	int BHT1_index = (PHT[PHT_index] & (BHT1_SIZE-1));
 	//int BHT_index = ((pc^GHR) & (BHT_SIZE-1));
 	//int BHT_index = (GHR & (BHT_SIZE-1));

 //If the outcome was true, increment the saturating counter, except when it's already in 3
 	if (outcome){
		switch (BHT1[BHT1_index]){
			case 0: 
			case 1: 
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:BHT1[BHT1_index])++; break; 
			case 7: break;}}
//else decrement the counter
	else{
		switch (BHT1[BHT1_index]){
			case 0: break;
			case 1: (BHT1[BHT1_index])--; break;
			case 2: (BHT1[BHT1_index])--; break;
			case 3: (BHT1[BHT1_index])--; break;}}

//if outcome is correctly predicted, then make the choice predictor more biased towards local predictor
	if(outcome==make_prediction(pc)){
		switch(CHOICE[choice_index]){
			case 0: break;
			case 1: CHOICE[choice_index]--;
			case 2: break;
			case 3: break;}}

//else, bias it towards global predictor	
	if(outcome!=make_prediction(pc)){
		switch(CHOICE[choice_index]){
			case 0: CHOICE[choice_index]++;break; 
			case 1: CHOICE[choice_index]++;break;
			case 2: break;
			case 3: break;}}

//Updating PHT
	PHT[PHT_index] <<= 1;
	PHT[PHT_index] = PHT[PHT_index] | outcome;
	
	break;}



	case 1:{ //global
 	int BHT2_index = ((GHR) & (BHT2_SIZE-1));
 	if (outcome){
		switch (BHT2[BHT2_index]){
			case 0: (BHT2[BHT2_index])++; break;
			case 1: (BHT2[BHT2_index])++; break;
			case 2: (BHT2[BHT2_index])++; break;
			case 3: break;}}

	else{
		switch (BHT2[BHT2_index]){
			case 0: break;
			case 1: (BHT2[BHT2_index])--; break;
			case 2: (BHT2[BHT2_index])--; break;
			case 3: (BHT2[BHT2_index])--; break;}}

//if outcome is correctly predicted, then make it more biased towards global predictor
	if(outcome==make_prediction(pc)){
		switch(choice_predictor){
			case 0: break;
			case 1: break;
			case 2: choice_predictor++;
			case 3: break;}}

//else, bias it towards global predictor	
	if(outcome!=make_prediction(pc)){
		switch(choice_predictor){
			case 0: break;
			case 1: break;
			case 2: choice_predictor--;break;
			case 3: choice_predictor--;break;}}

	break;}}

//Updating GHR
	GHR <<= 1;
	GHR |= outcome;

 return ;
}
