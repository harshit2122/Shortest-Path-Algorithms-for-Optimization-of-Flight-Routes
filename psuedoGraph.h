void psuedoGraph(int G[V][V],int n)
{
	int i,j,k,count;
	for(i=0;i<n;i++)
	{	
		headers[i] = (VERTICE*)calloc(V,sizeof(VERTICE));
		headers[i]->c = 0;
		headers[i]->name = i;
		headers[i]->next = NULL;
	}

	for(i=0;i<n;i++)
	{
		count=0;
		for (j=0;j<n;++j)
		{
			if(G[i][j]!=0 && G[i][j]!=INFINITY)
			{
				headers[i]->weights[count] = G[i][j];
				headers[i]->links[count] = headers[j] ;
				count++;
			}
		}
		headers[i]->c = count;
	}

	/*for (i = 0; i < n; ++i)
	{
		printf("%d\n", headers[i]->name );
		for (j = 0; j < headers[i]->c; ++j)
		{
			printf("link %d  wt %d\n", headers[i]->links[j]->name, headers[i]->weights[j]);
		}
	} */
}