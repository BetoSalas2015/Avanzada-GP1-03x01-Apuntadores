#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>		// Para el manejo de memoria dinámica

struct Nodo 
{  
	char info;
	struct Nodo *sig;
};

typedef struct Nodo nodo;

nodo *raiz = NULL;		// La lista vacía

void insert(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )
	{
		printf("No hay memoria suficiente! \n");
		exit(1);
	}
	nuevo ->info = dato;
	nuevo ->sig = NULL;

	if(raiz == NULL)
	{
		raiz = nuevo;
	} else {
		nodo *recorre = raiz;
		while( recorre -> sig != NULL)
			recorre = recorre ->sig;
		recorre -> sig = nuevo;
	}
}

void insert1(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )
	{
		printf("No hay memoria suficiente! \n");
		exit(1);
	}
	nuevo ->info = dato;
	nuevo ->sig = NULL;

	if(raiz == NULL)
	{
		raiz = nuevo;
	} else {
		nodo *recorre = raiz;
		while( recorre -> sig != NULL)
			recorre = recorre ->sig;
		recorre -> sig = nuevo;
	}
}

void imprimeLista()
{
	nodo *recorre = raiz;
	while( recorre  != NULL) {
		printf("%c, ", recorre->info);
		recorre = recorre ->sig;
	}
	printf("\n");
}

int main()
{	
	insert('R');
	insert('o');
	insert('b');
	insert('e');
	insert('r');
	insert('t');
	insert('o');

	imprimeLista();

	system("pause");
	return 0;
}