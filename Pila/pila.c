#include<stdio.h>
#include<stdlib.h>

typedef struct tNodo{
    int dato;
    struct tNodo *sig;
} tNodo;

typedef struct tStack{
    int current_size;
    tNodo *tope;
} tPila;

tPila *crearPila(){
    tPila *pila = (tPila*)malloc(sizeof(tPila));
    pila->current_size = 0;
    pila->tope = NULL;
    return pila;
}

tNodo *crearNodo(int n){
    tNodo *nodo = (tNodo*)malloc(sizeof(tNodo));
    nodo->sig = NULL;
    nodo->dato = n;
    return nodo;
}
// inserta un elemento en el tope de la pila
void push(tPila* Pila, int n){
    if(Pila->current_size == 0){
        Pila->tope = crearNodo(n);
        Pila->current_size++;
    }
    else{
        tNodo * nuevo = crearNodo(n);
        nuevo->sig = Pila->tope;
        Pila->tope = nuevo;
        Pila->current_size++;
    }
}

// elimina el elemento que está en el tope de la pila
void pop(tPila *Pila){
    if(Pila->current_size == 0) printf("Pila vacía, no se pueden eliminar elementos.\n");
    else{
        printf("Eliminando elemento: %d\n",Pila->tope->dato);
        tNodo * temp = Pila->tope;
        Pila->tope = Pila->tope->sig;
        free(temp);
        Pila->current_size--;
    }
}
// reinicializa una pila como vacía
void clear(tPila *Pila){
    int n = Pila->current_size;
    for (int i = 0; i < n; i++){
        tNodo * temp = Pila->tope;
        Pila->tope = Pila->tope->sig;
        free(temp);
    }
    Pila->current_size = 0;
    printf("Cola reinicializada.\n");

}
// muestra por pantalla el elemento que está en el tope de la pila
void topValue(tPila *Pila){
    printf("El valor en el tope de la pila es: %d\n",Pila->tope->dato); 
}
// retorna el tamaño de una pila
void size(tPila *Pila){
    printf("El tamaño actual de la pila es: %d\n",Pila->current_size); 
}

int main(){
    tPila * Pila = crearPila();
    push(Pila,7);
    push(Pila,3);
    size(Pila);
    push(Pila,4);
    push(Pila,1);
    push(Pila,9);
    push(Pila,11);
    pop(Pila);
    pop(Pila);
    size(Pila);
    clear(Pila);
    size(Pila);
    pop(Pila);
    free(Pila);
    return 0;
}
