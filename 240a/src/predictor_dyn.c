// A very stupid predictor.  It will always predict not taken.

void init_predictor (){
 int i=0;
 int num_of_unique_branches=0;	
 int list_of_PC[MAX_NUM_OF_BRANCHES];
 
 int curr_index=0;
 while (read_branch (&pc, &outcome)) {
	pc = ntohl (pc);
	if(!is_PC_exist(pc, &list_of_PC)){
		list_of_PC[curr_index++] = pc;
		num_of_unique_branches++;}
	}

 printf("\n The num of unique branches is %d\n", num_of_unique_branches);

 int pht_size=28672/num_of_unique_branches;
 for  
}

	
bool make_prediction (unsigned int pc)
{
  return false;
}

void train_predictor (unsigned int pc, bool outcome)
{
}
