typedef struct Vertice VERTICE;

struct Vertice
{
	/*
	float longitude;
	float latitude;
	*/
	int heuristic;
	int distance;
	int name;
	int c;
	VERTICE *next;
	VERTICE *links[V];
	int weights[V];	
};

VERTICE *headers[V];

