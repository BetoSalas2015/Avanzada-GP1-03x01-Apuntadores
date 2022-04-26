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
	if(pos == 1)
	{
		nodo *siguiente = raiz;
		raiz = nuevo;
		nuevo -> sig = siguiente;
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


char remueve(void)
{
	nodo *anterior = raiz;
	char dato;
	if( raiz == NULL) 
	{
		printf("La lista está vacía.");  //  _Underflow: 
		return '\0';
	}
	if( anterior ->sig == NULL)
	{
		dato = anterior -> info;
		raiz = NULL;
		free(anterior);
	}
	else
	{
		nodo *siguiente = anterior ->sig;
		while( siguiente->sig != NULL)
		{
			anterior = anterior ->sig;
			siguiente = siguiente->sig;
		}
		dato = siguiente -> info;
		anterior ->sig = NULL;
		free(siguiente);
	}

	return dato;
}


char remueve1(void)
{
	nodo *anterior = raiz;
	char dato;
	if( raiz == NULL) 
	{
		printf("La lista está vacía.");  //  _Underflow: 
		return '\0';
	}
	dato = anterior -> info;
	raiz = anterior ->sig;
	free(anterior);
	return dato;
}


char remueven(int pos)
{
	nodo *anterior = raiz;
	char dato;
	if( raiz == NULL) 
	{
		printf("La lista está vacía.");  //  _Underflow: 
		return '\0';
	}
	if( anterior ->sig == NULL)
	{
		dato = anterior -> info;
		raiz = NULL;
		free(anterior);
	}
	else
	{
		nodo *siguiente = anterior ->sig;
		while( siguiente->sig != NULL)
		{
			anterior = anterior ->sig;
			siguiente = siguiente->sig;
		}
		dato = siguiente -> info;
		anterior ->sig = NULL;
		free(siguiente);
	}

	return dato;
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

	insertn('k',1);

	imprimeLista();

	printf("Salió la letra: %c\n", remueve()   );
	printf("Salió la letra: %c\n", remueve()   );
	printf("Salió la letra: %c\n", remueve()   );

	imprimeLista();

	printf("Salió la letra: %c\n", remueve1()   );
	printf("Salió la letra: %c\n", remueve1()   );

	imprimeLista();

	system("pause");
	return 0;
}