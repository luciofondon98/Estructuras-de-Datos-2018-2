#include<stdio.h>
#include<stdlib.h>

typedef struct tNodo{
    int dato;
    struct tNodo *izq;
    struct tNodo *der;
} tNodo;

typedef struct tArbol{
    int size;
    tNodo *raiz;
} tABB;

tABB *crearArbol(){
    tABB *arbol = (tABB*)malloc(sizeof(tABB));
    arbol->size = 0;
    arbol->raiz = NULL;
    return arbol;
}

tNodo *crearNodo(int n){
    tNodo *nodo = (tNodo*)malloc(sizeof(tNodo));
    nodo->dato = n;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

// funcion auxiliar para insertar nuevos nodos
void recursiveInsert(tNodo *nodo, int n){
	if(nodo->dato < n){
	    if(nodo->der == NULL) nodo->der = crearNodo(n);
		else recursiveInsert(nodo->der, n);
	}	

	if(nodo->dato > n){
	   	if(nodo->izq == NULL) nodo->izq = crearNodo(n);
	 	recursiveInsert(nodo->izq, n);
	}
}

// inserta un elemento en el ABB
void insert(tABB *arbol, int n){
	if(arbol->raiz == NULL) arbol->raiz = crearNodo(n);
	else recursiveInsert(arbol->raiz, n);
	arbol->size++;
}

// función auxiliar para encontrar un nodo
int recursiveFind(tNodo *nodo, int n){
	if(nodo == NULL) return 0; //Llegó a un nodo terminal
	if(nodo->dato < n) recursiveFind(nodo->der, n);
	if(nodo->dato > n) recursiveFind(nodo->izq, n);
	else if(nodo->dato == n) return 1;
	return 0;
}

// busca un elemento en un ABB T
void find(tABB *arbol, int n){
	if(arbol->raiz == NULL) printf("Árbol Binario de Búsqueda vacío, no hay elementos.\n");
	else if(recursiveFind(arbol->raiz, n)) printf("El nodo %d si está en el ABB\n", n);
	else printf("El nodo %d no está en el ABB\n", n);
}

// cantidad de elementos en el árbol
void size(tABB *arbol){
	printf("La cantidad de nodos en el ABB es de: %d\n", arbol->size);
}

// función auxiliar para recorrido in-orden
void inOrdenHelp(tNodo *nodo){
	if(nodo == NULL) return;
	inOrdenHelp(nodo->izq);
	printf("%d ",nodo->dato);
	inOrdenHelp(nodo->der);
}

// recorrido in-orden de un ABB T
void inOrden(tABB *arbol){
	if(arbol->raiz == NULL) printf("Árbol Binario de Búsqueda vacío, no se puede recorrer.\n");
	else{
		printf("El recorrido in-orden del arbol es: ");
		inOrdenHelp(arbol->raiz);
		printf("\n");
	}
}

// función auxiliar para recorrido pre-orden
void preOrdenHelp(tNodo *nodo){
	if(nodo == NULL) return;
	printf("%d ",nodo->dato);
	preOrdenHelp(nodo->izq);
	preOrdenHelp(nodo->der);
}


// recorrido pre-orden de un ABB T
void preOrden(tABB *arbol){
	if(arbol->raiz == NULL) printf("Árbol Binario de Búsqueda vacío, no se puede recorrer.\n");
	else{
		printf("El recorrido pre-orden del arbol es: ");
		preOrdenHelp(arbol->raiz);
		printf("\n");
	}
}

// función auxiliar para recorrido post-orden
void postOrdenHelp(tNodo *nodo){
	if(nodo == NULL) return;
	postOrdenHelp(nodo->izq);
	postOrdenHelp(nodo->der);
	printf("%d ",nodo->dato);
}

// recorrido post-orden de un ABB T
void postOrden(tABB *arbol){
	if(arbol->raiz == NULL) printf("Árbol Binario de Búsqueda vacío, no se puede recorrer.\n");
	else{
		printf("El recorrido post-orden del arbol es: ");
		postOrdenHelp(arbol->raiz);
		printf("\n");
	}
}

int main(){
    tABB * arbol = crearArbol();
    insert(arbol, 15);
    insert(arbol, 8);
    insert(arbol, 20);
    insert(arbol, 7);
    insert(arbol, 6);
    insert(arbol, 13);
    insert(arbol, 32);
    find(arbol, 16);
    inOrden(arbol);
    preOrden(arbol);
    postOrden(arbol);
    size(arbol);
    return 0;
}