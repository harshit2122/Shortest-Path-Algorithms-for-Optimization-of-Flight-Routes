#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define INFINITY 999
#define V 100
#include"structure.h"
#include"psuedoGraph.h"
#include"min.h"
#include"infAssign.h"
#include"dijkstra.h"
#include"bellmanFord.h"
#include"floydWarshall.h"
#include"aStar.h"
#include"weightArray.h"
#include"heuristicsArray.h"

int main()
{
	int G[V][V],H[V],i,j,k;
	int u[2], v[2], taStar[2];
	int n[2] = {7, 8};
		
	for (int i = 0 ; i < 2; i++){
		for(int j = 0; j<n[i] ; j++){
			for (int k = 0; k<n[i]; k++){
				G[j][k] =  weights[i][j][k];
			}
		}
	
	srandom(time(NULL)); 
	u[i] = random()%n[i];
	v[i] = random()%n[i];

	for (int i = 0 ; i < 2; i++)
		for(int j = 0; j<n[i] ; j++){
			H[j] =  heuristics[i][v[i]][j];	
		}

	/*for(int j = 0; j<n[i] ; j++){
			for (int k = 0; k<n[i]; k++){
				printf("%d  ", G[j][k]);
			}
			printf("\n");
		}*/
	printf("\n %d ", u[i] );
	printf("\n %d ", v[i] );

	infAssign(G,n[i]);
	psuedoGraph(G,n[i]);
	dijkstra(G,n[i],u[i],v[i]);
	bellmanFord(G,n[i],u[i],v[i]);
	floydWarshall(G,n[i],u[i],v[i]);
	aStar(n[i],u[i],v[i],H);
	}
	
	printf(" \n ---------------------------------------------------------------------------\nThe Final Output Table\n");
	printf("\n\tNodes\tSrc\tDest");
	for(i = 0; i< 2; i++){
		printf("\n\t%d\t%d\t%d",n[i],u[i],v[i]);
	}
	printf("\n----------------------------------------------------------------------------");		
	return 0;
}