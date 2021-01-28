void aStar(int n,int src,int dest)
{
	VERTICE *curr = (VERTICE*)calloc(1,sizeof(VERTICE));
	curr = headers[src];
	VERTICE *temp = (VERTICE*)calloc(1,sizeof(VERTICE));
	int visited[n];
	int ch[n];

	for(int i = 0 ; i<n ; i++)
    {
        visited[i]=0;
		headers[i]->distance = INFINITY;
		ch[i] = INFINITY;
    }

	printf("Enter H \n");
    for(int i = 0 ; i<n ; i++)
    {
       scanf("%d", &headers[i]->heuristic);
    }

	
    visited[curr->name] = 1;
	curr-> distance = 0;
	ch[curr->name] = curr->heuristic;
	int cname = curr->name;
	int cd ;
	
	printf("Curr = %d " , curr->name);

	
	
	while( (cname != dest) && curr != NULL )
	{	
		cd = curr->distance;
		printf("\n curr  = %d \n dist = %d",cname,cd);
		for (int i = 0; i < curr->c; ++i)
		{
			temp = curr->links[i];

			if (visited[temp->name] == 0 )
			{
				if(ch[temp->name] > (temp->heuristic + curr->distance + curr->weights[i]))
				{
					ch[temp->name] = temp->heuristic + curr->distance + curr->weights[i];
					temp->distance = curr->distance + curr->weights[i];
					temp->previous = curr;
				}
			}
		}

		visited[cname] = 1;
		ch[cname] = INFINITY;

		int min = 0;
		for(int i = 0 ; i<n ; i++)
		{
			if(ch[i]<ch[min])
				min = i;
		}	
		if (ch[min] == INFINITY)
			curr = NULL;
		else{
			curr = headers[min];
			cname = curr->name;
		}
	}
	
	if(cname = dest){
		cd = curr->distance;
		printf("\n total Distance = %d", cd );
		while(curr != NULL){
			cname = curr->name;
			printf("%d <- " , cname);
			curr = curr->previous;
		}
	}
}