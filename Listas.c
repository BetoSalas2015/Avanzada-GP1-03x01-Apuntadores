#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>		// Para el manejo de memoria din�mica

struct Nodo 
{  
	char info;
	struct Nodo *sig;
};

typedef struct Nodo nodo;

nodo *raiz = NULL;		// La lista vac�a

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

void insertn(char dato, int pos)		// insertn('k', 2)
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
	} 
	else 
	{
		int cont = 1;
		nodo *anterior = raiz;
		nodo *siguiente = NULL;
		while( anterior -> sig != NULL && cont != pos - 1)
		{
			anterior = anterior ->sig;
			cont++;
		}
		siguiente = anterior -> sig;
		anterior -> sig = nuevo;
		nuevo -> sig = siguiente;
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
	nuevo ->sig = raiz;
	raiz = nuevo;
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

	insertn('k',2);

	imprimeLista();

	system("pause");
	return 0;
}