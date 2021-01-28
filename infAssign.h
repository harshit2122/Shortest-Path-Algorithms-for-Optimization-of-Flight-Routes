void infAssign(int G[V][V],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0 && i!=j)
				G[i][j]=INFINITY;
}
