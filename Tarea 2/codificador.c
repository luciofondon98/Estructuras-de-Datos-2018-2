#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo{
    int dato;
    struct Nodo *der;
    struct Nodo *izq;
}nodo;

typedef struct Arbol{
    int tam;
    nodo *raiz;
}arbol;

/*****
*   arbol * inicializarArbol
******
*   Inicializa un arbol con raíz NULL y con tamaño igual a cero.
******
*   Input:
*       No recibe parámetros.
******
*   Returns:
*       arbol, Retorna un struct de tipo arbol.
*****/
arbol *inicializarArbol(){
    arbol *aarbol = (arbol*)malloc(sizeof(arbol));
    aarbol->raiz=NULL;
    aarbol->tam=0;
    return aarbol;
}

/*****
*   nodo *InicializarNodo
******
*   Inicializa un nodo con su respectiva estructura, hijos y el dato o la informacion.
******
*   Input:
*       int n : Recibe como parametro el dato que contendra el nodo inicializado.
******
*   Returns:
*       nuevo_nodo, Retorna un struct de tipo nodo.
*****/
nodo *inicializarNodo(int n){
    nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
    nuevo_nodo-> der = NULL;
    nuevo_nodo-> izq = NULL;
    nuevo_nodo-> dato = n;
    return nuevo_nodo;
}

/*****
*   void recursividad
******
*    Agrega los nodos de forma recursivda al ABB.
******
*   Input:
*       FILE* salida : El archivo de salida "salida.txt".
*       nodo* n :
*       nodo* noodo :
******
*   Returns:
*          Es de tipo void, no retorna nada.
*****/
void recursividad(FILE* salida,nodo* n,nodo* noodo){
    if(n->dato < noodo->dato){
        fprintf(salida, "%c",45);
        if (n->der ==  NULL) n->der = noodo;
        else recursividad(salida,n->der,noodo);
    }
    if(n->dato > noodo->dato){
        fprintf(salida, "%c",46);
        if (n->izq ==  NULL) n->izq = noodo;
        else recursividad(salida,n->izq,noodo);
    }
}

/*****
*   void agregarnodo
******
*   Agrega un nodo al arbol con la letra correspondiente
******
*   Input:
*       FILE* salida: El archivo de salida "salida.txt".
*       arbol* aarbol: Es el nodo raíz del arbol y sus respectivos sub-arboles.
*       int dato: Es el dato que almacena el nodo.
*
******
*    Returns:
*           No retorna nada.
*****/


void agregarnodo(FILE* salida,arbol* aarbol,int dato){
    nodo* nuevo_nodo = inicializarNodo(dato);
    recursividad(salida,aarbol->raiz,nuevo_nodo);
    fprintf(salida,"   ");
    aarbol->tam+=1;
}

/*****
*   void agregarpalabras
******
*   Toma cada caracter del archivo de entrada e imprime en el archivo de salida, las palabras en codigo Morse. Luego, agrega el nodo de la letra al arbol.
******
*   Input:
        FILE* fp : Es el archivo de entrada, "mensaje.txt".
        FILE* salida: Es el archivo de salida "salida.txt".
        arbol* aarbol: Es el arbol al que se le agregara el nodo de la letra obtenida del archivo.
*
******
*   Returns:
*          No retorna nada.
*****/
void agregarpalabras(FILE* fp,FILE* salida,arbol* aarbol){
    char letra;
    while(!feof(fp)){
        letra = fgetc(fp);
        if (!(letra==EOF || letra == '\n'|| letra == '\0')){
              if (letra == 32 || letra == 44 || letra == 46){
                  fprintf(salida,"%c",47);
              }
        if (letra!=32) agregarnodo(salida,aarbol,letra);
        }
    }
  fprintf(salida,"%c",47);
}

/*****
*   void liberarNodo
******
*   Libera la memoria que fue pedida para los nodos.
******
*   Input:
       nodo* noodo: Nodo a liberar.
******
*   Returns:
*       No retorna nada.
*****/
void liberarNodo (nodo* noodo){
    if (noodo->izq == NULL && noodo->der == NULL) free((void*)noodo);
    else{
        if(noodo->izq != NULL) liberarNodo(noodo->izq);
        if(noodo->der != NULL) liberarNodo(noodo->der);
    }
}

/*****
*   void liberar_arbol
******
*   Libera la memoria que fue pedida para el arbol.
******
*   Input:
       arbol* aarbol: Arbol a liberar.
******
*   Returns:
*       No retorna nada.
*****/
void liberar_arbol (arbol* aarbol){
    free(aarbol);
}

int main(int argc, char const *argv[]){
    FILE *fp,*salida;
    fp = fopen(argv[1],"r");
    salida = fopen("salida.txt","w");
    arbol *abb=inicializarArbol();
    nodo *no=inicializarNodo(107);
    abb->raiz=no;
    agregarpalabras(fp,salida,abb);
    liberarNodo(abb->raiz);
    liberar_arbol(abb);
    return 0;
}
