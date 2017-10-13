#include "stdafx.h"
#include <iostream>
#include "struct.h"
#include "funcDef.h"

using namespace std;

int largTimeVar1,largTimeVar=0;

int *cnt;

int main()
{
	int i=0;
	int numNodes,finNodes;
	
	

/*-------------------------------------	Instructions	-----------------------------*/
	
	cout<<"\nInstructions for adding nodes of a DAG and filling (P,C,T) table \n";
	cout<<"\nThe Program design has assumed that DAG has nodes starting with one";
	cout<<"\nThe nodes of each level are numbered in ascending order from left to right";
	cout<<"\nE.g:\n";
	cout<<"\t\t\t1\n";
	cout<<"\t\t2\t\t3\n";
	cout<<"\t\t4\t      5\t  6\n";
	cout<<"\t      7\t 8\t\t9  10\n";
	cout<<"\n1 has 2 & 3 as children, 2 has 4, 5 has none, 6 has 9 & 10\n";

	/*----------------------------------------------------------------------------------------------------*/

	
				//Creating the node table for DAG

	cout<<"\nEnter the total number of nodes for the DAG \n";
	cin>>numNodes;
	N *nd = new N[numNodes];

	while(i<numNodes)
	{
		cout<<" Enter details for node: "<<i+1<<endl;
		largTimeVar1 = nodeAdd(nd,i); 
		if(largTimeVar1>largTimeVar)largTimeVar = largTimeVar1;
		i++;
	}

	i=0;
	int j,k;
	while(i<numNodes)
	{
		j=0;
		while(j<nd[i].numFunitTypes)
		{
			k=0;
			while(k<nd[i].f[j]->numTimeVariables)
			{
				cout<<nd[i].f[j]->tVar[k]<<"\t"<<nd[i].f[j]->c<<"\t"<<nd[i].f[j]->p[k]<<"\n";
				k++;
			}
			j++;
		}		
		i++;
	}
						//Creating the bTable for each node
	bT *b = new bT[numNodes];
	i=0;
	while(i<numNodes)
	{
		bTableBuild(nd,b,i,largTimeVar);
		cout<<"\n--------------------------------------------------------\n";
		i++;
	}


	/*cout<<"\n";
	i=0;
	while(i<numNodes)
	{
		j=0;
		while(j<largTimeVar)
		{
			bTableBlocks *tmp = b[i].bTabBlock[j];
			while(tmp!=NULL)
			{
				cout<<tmp->c<<"\t"<<tmp->p<<"\n";
				tmp=tmp->bTable;
			}
			j++;
		}
		i++;
	}*/

					//Merge nodes

	finNodes = merge (b,nd,numNodes,largTimeVar);

	i=0;
	while(i<finNodes)
	{
		j=0;
		while(j<largTimeVar)
		{
			bTableBlocks *pnt = b[i].bTabBlock[j];
			while(pnt!=NULL)
			{
				cout<<pnt->p<<"\t"<<pnt->c<<"\n";
				pnt = pnt->bTable;
			}
			j++;
		}
		cout<<"\n------------------------------------------\n";
		i++;
	}


					//Creating dTable!!

	int *tim = 0;
	bT* d = dTableBuild(b,nd,finNodes,largTimeVar,cnt,tim);

	cout<<"\nThe optimal probability,cost pair for the best time is: "<<d[finNodes-1].bTabBlock[*tim]->p<<", "<<d[finNodes-1].bTabBlock[*tim]->c;
}
