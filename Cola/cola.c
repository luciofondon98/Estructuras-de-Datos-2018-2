#include<stdio.h>
#include<stdlib.h>

typedef struct tNodo{
    int dato;
    struct tNodo *sig;
} tNodo;

typedef struct tQueue{
    int current_size;
    tNodo * frente; //primero en salir de la cola
    tNodo * final; //ultimo en salir de la cola
} tCola;

tNodo *crearNodo(int n){
    tNodo *nodo = (tNodo*)malloc(sizeof(tNodo));
    nodo->sig = NULL;
    nodo->dato = n;
    return nodo;
}

//Crea una cola vacía
tCola *crearCola(){
    tCola *cola = (tCola*)malloc(sizeof(tCola));
    cola->current_size = 0;
    cola->frente = NULL;
    cola->final = NULL;
    return cola;
}
//Reinicializa una cola como vacía
void clear(tCola *Cola){
    if(Cola->frente == NULL) printf("Cola vacía, no se puede reinicializar.\n");
    else{
        int n = Cola->current_size;
        for (int i = 0; i < n; i++){
            tNodo * temp = Cola->frente;
            Cola->frente = Cola->frente->sig;
            free(temp);
        }
        Cola->current_size = 0;
        printf("Cola reinicializada.\n");
    }
}
//Inserta un elemento al final de la cola
void enqueue(tCola *Cola, int n){
    if(Cola->current_size == 0){
        tNodo * nuevo = crearNodo(n);
        Cola->frente = nuevo;
        Cola->final = Cola->frente;
        Cola->current_size++;
    }
    else{
        tNodo * nuevo = crearNodo(n);
        Cola->final->sig = nuevo;
        Cola->final = nuevo;
        Cola->current_size++;
    }
}
//Elimina el elemento que está al frente de la cola
void dequeue(tCola *Cola){;
    if(Cola->current_size == 0) printf("Cola vacía, no se pueden eliminar elementos.\n");
    else{
        printf("Eliminando elemento: %d\n",Cola->frente->dato);
        tNodo * temp = Cola->frente;
        Cola->frente = Cola->frente->sig;
        free(temp);
        Cola->current_size--;
    }
}
// muestra por pantalla el elemento que está al frente de la cola
void frontValue(tCola *Cola){
    if(Cola->frente == NULL) printf("Cola vacía, no hay elemento al frente.\n");
    else printf("El primer elemento en la cola es: %d\n",Cola->frente->dato);
}

//Retorna el tamaño de la cola
void size(tCola *Cola){
    printf("El tamaño actual de la cola es: %d\n",Cola->current_size); 
}

int main(){
    tCola * Cola = crearCola();
    enqueue(Cola,2);
    enqueue(Cola,4);
    enqueue(Cola,5);
    enqueue(Cola,9);
    size(Cola);
    enqueue(Cola,1);
    enqueue(Cola,2);
    size(Cola);
    dequeue(Cola);
    dequeue(Cola);
    dequeue(Cola);
    size(Cola);
    clear(Cola);
    size(Cola);
    free(Cola);
    return 0;
}
