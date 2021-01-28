void bellmanFord(int G[V][V],int m, int src, int dest)
{
	int i,j,e=0,n,u,v,k,distance[500],parent[500],p=0,flag=1,edge[500][500];

 	for(i=0;i<m;i++)
    {
       for(j=0;j<m;j++)
        {
            if(G[i][j]!=0)
                edge[p][0]=i,edge[p++][1]=j;
        }
    }

    for(i=0;i<m;i++)
    {
        distance[i] = INFINITY;
        parent[i] = -1 ;
        distance[src]=0 ;
    }
    for(i=0;i<m-1;i++)
    {
        for(k=0;k<p;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v] , parent[v]=u ;
        }
    }

    for(k=0;k<p;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                flag = 0 ;
        }
    if(flag)
    {
       for(i=0;i<m;i++)
       {
            if (i == dest)
            printf("\nBellman Ford =\n Total distance = %d",distance[i]);
       }
    }
}