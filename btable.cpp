#include "stdafx.h"
#include "struct.h"
#include "funcDef.h"
#include <iostream>

using namespace std;

void bTableBuild(N* trk,bT* b,int i,int largTimeVar)
{
	int j=0,k=0,lowTimeVar=100;
	cout<<"\n Building B-table for node: "<<i+1<<endl;

								
								//Accumulating probabilities

	while(j<trk[i].numFunitTypes)
	{
		trk[i].f[j]->p[(trk[i].f[j]->numTimeVariables)-1] = 1;
		j++;
	}
		
	b[i].bTabBlock = new bTableBlocks*[largTimeVar];
	
	
								//Assigning default values to all blocks in a Btable for a node
	
	j=0;
	while(j<largTimeVar)
	{
		b[i].bTabBlock[j] = NULL;
		j++;
	}
	
		
								//Assigning tuples to different blocks of bTable
	bTableBlocks *tmp;


	j=0;
	while(j<(trk[i].numFunitTypes))
	{
		k=0;
		while(k<(trk[i].f[j]->numTimeVariables))
		{
			int a = trk[i].f[j]->tVar[k];
			if(b[i].bTabBlock[a-1]==NULL)
			{
				b[i].bTabBlock[a-1] = new bTableBlocks;
				b[i].bTabBlock[a-1]->c = trk[i].f[j]->c;
				b[i].bTabBlock[a-1]->p = trk[i].f[j]->p[k];
				b[i].bTabBlock[a-1]->bTable = NULL;
			}
			else
			{
				tmp = b[i].bTabBlock[a-1];
				while(tmp->bTable!=NULL)tmp = tmp->bTable;
				bTableBlocks *tmpA = new bTableBlocks;
				tmpA->c = trk[i].f[j]->c;
				tmpA->p = trk[i].f[j]->p[k];
				tmpA->bTable = NULL;
				tmp->bTable=tmpA;
			}
			k++;
		}
		j++;
	}

	

	


	
	

				//Using redundant pair removal and insertion of linked lists to form "bTable"
	j=0;
	while(j<largTimeVar)
	{
		int flg=0;
		if(j)
		{
			if(b[i].bTabBlock[j] != NULL)
			{

				b[i].bTabBlock[j] = addLinkList(b[i].bTabBlock[j],b[i].bTabBlock[j-1]);
		
				sortLinkList(b[i].bTabBlock[j]);
			
				b[i].bTabBlock[j] = redPairRemove(b[i].bTabBlock[j]);
			}
			else
			{
				b[i].bTabBlock[j] = addLinkList(b[i].bTabBlock[j],b[i].bTabBlock[j-1]);
			}
		}
			
		else
		{
			sortLinkList(b[i].bTabBlock[j]);

			b[i].bTabBlock[j] = redPairRemove(b[i].bTabBlock[j]);
		}
		j++;
	}

		
	j=0;
	while(j<largTimeVar)
	{
		tmp = b[i].bTabBlock[j];
		while(tmp!=NULL)
		{
			cout<<tmp->p<<"\t"<<tmp->c<<"\n";
			tmp=tmp->bTable;
		}
		cout<<"----------------\n";
		j++;
	}
	
	
	/* ------- Junk Code ---------- */
	
	/*bTableBlocks *tmp = b[i].bTabBlock[j];
		while(tmp!=NULL)tmp = tmp->bTable;
		bTableBlocks *temp = b[i].bTabBlock[j-1];

		while(temp!=NULL)
		{
			tmp = new bTableBlocks;
			tmp->c = temp->c;
			tmp->p = temp->p;
			tmp->bTable = NULL;
			tmp = tmp->bTable;
			temp = temp->bTable;
		}*/

}
