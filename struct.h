#ifndef MEM_DECL
#define MEM_DECL

				/* FU Types */
			
struct fuType
{
	int numTimeVariables,*tVar;
	float *p,c;	// Total (P,C) pairs are number of time 					//variables 
};

										
				/* Nodes of DAG */									

struct node
{
	fuType **f;
	int num,numFunitTypes,parNodeNum;
};

typedef node N;


struct bTableBlocks
{
	float p,c;
	bTableBlocks* bTable;
};

struct bTable
{
	bTableBlocks **bTabBlock;
};

typedef bTable bT;

#endif
