void dijkstra(int G[V][V],int n,int src,int dest)
{
 
	int cost[V][V],distance[V],pred[V];
	int visited[V],count,mindistance,nextnode,i,j;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cost[i][j]=G[i][j];
	
	for(i=0;i<n;i++)
	{
		distance[i]=cost[src][i];
		pred[i]=src;
		visited[i]=0;
	}
	
	distance[src]=0;
	visited[src]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
						
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}


			printf("\n Dijkstra \n Total Distance = %d",distance[dest]);
			printf("\n Path \n");
			printf("%d",dest);
			j=dest;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=src);
		
}