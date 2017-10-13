#include "struct.h"

#ifndef Mem_ctrl
#define Mem_ctrl


int nodeAdd(N*,int);				// Creating the primary node table for given DAG

void bTableBuild(N*,bT*,int,int);	// Building the bTable

void sortLinkList(bTableBlocks*);

bTableBlocks* redPairRemove(bTableBlocks*);

bTableBlocks* addLinkList(bTableBlocks*,bTableBlocks*);

int merge(bT*,N*,int,int);

bT* dTableBuild(bT*,N*,int,int,int*,int*);					// Building the dTable

void multiplySortRedRemove(bT*,int,int,int);

bTableBlocks* dTableMultiple(bTableBlocks*,bTableBlocks*);

#endif
