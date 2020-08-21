#include<stdio.h>
#include<stdlib.h>

typedef struct tNodo{
    int dato;
    struct tNodo *sig;
} tNodo;

typedef struct tLista{
    int size;
    tNodo *head;
} tLista;

tLista *crearLista(){
    tLista *lista = (tLista*)malloc(sizeof(tLista));
    lista->size = 0;
    lista->head = NULL;
    return lista;
}

tNodo *crearNodo(int n){
    tNodo *nodo = (tNodo*)malloc(sizeof(tNodo));
    nodo->sig = NULL;
    nodo->dato = n;
    return nodo;
}

void insertarNodo(tLista *Lista, int n){ //agrega al final de la lista
    if(Lista->head == NULL) Lista->head = crearNodo(n);
    else{
        tNodo * current = Lista->head;
        while (current->sig != NULL) current = current->sig;
        tNodo * nuevo = crearNodo(n);
        current->sig = nuevo; 
    }
    Lista->size++;    
}

void insertarPorIndice(tLista *Lista, int n, int indice){
    if(indice == 0){
        if(Lista->head == NULL){
            tNodo * nuevo = crearNodo(n);
            Lista->head = nuevo;
            Lista->size++;   
        }
        else{
            tNodo * nuevo = crearNodo(n);
            tNodo * current = Lista->head;
            Lista->head = nuevo;
            Lista->head->sig = current;
            Lista->size++;
        }
    }
    else{
        int i = 0;
        tNodo * current = Lista->head;
        tNodo * ant_current;
        while(i != indice){
            ant_current = current;
            current = current->sig; 
            i++;
        }
        if (current == NULL) printf("No se pudo insertar elemento, índice fuera de rango.\n"); //si se pasó de los índices de la lista
        else{
            tNodo * nuevo = crearNodo(n);
            ant_current->sig = nuevo;
            nuevo->sig = current;
            Lista->size++;
        }
    }
}

void borrarPorIndice(tLista *Lista, int indice){
    if(Lista->head==NULL) printf("Lista vacía, no se pueden borrar elementos.\n"); //si es que lista está vacía no se puede borrar
    else if(indice == 0){ //si se quiere borrar el primer elemento de la lista
        tNodo * current = Lista->head->sig;
        free(Lista->head);
        Lista->head = current;
        Lista->size--;
    }
    else{
        if (indice >= Lista->size) printf("No se pudo eliminar elemento, índice fuera de rango.\n"); //si se pasó del largo de la lista
        else{
            int i = 0;
            tNodo * current = Lista->head;
            tNodo * ant_current;
            while(i != indice){
                ant_current = current;
                current = current->sig; //current será el nodo a borrar
                i++;
            }
            int valor = current->dato;
            ant_current->sig = current->sig;
            free(current);
            printf("Elemento con valor: %d eliminado en el índice: %d\n", valor, i);
            Lista->size--;
        }
    }
}

void borrarPorElemento(tLista *Lista, int elemento){
    if(Lista->head==NULL) printf("Lista vacía, no se pueden borrar elementos.\n"); //si es que lista está vacía no se puede borrar
    else if(Lista->head->dato == elemento){ //si se quiere borrar el primer elemento de la lista
        tNodo * current = Lista->head->sig;
        free(Lista->head);
        Lista->head = current;
        Lista->size--;
    }
    else{
        int i = 0;
        tNodo * current = Lista->head;
        tNodo * ant_current;
        while(current != NULL && current->dato != elemento){
            ant_current = current;
            current = current->sig; //current será el nodo a borrar
            i++;
        }
        if(current == NULL) printf("No se encuentra el elemento en la lista.\n");
        else{
            int valor = current->dato;
            ant_current->sig = current->sig;
            free(current);
            printf("Elemento con valor: %d eliminado en el índice: %d\n", valor, i);
            Lista->size--;
        }
    }
}

void borrarTodos(tLista *Lista){
    tNodo * current = Lista->head;
    tNodo * temp;
    while(current != NULL){
        temp = current->sig; //current será el nodo a borrar
        free(current);
        current = temp;
        Lista->size--;
    }
    printf("Todos los elementos de la lista borrados.\n");
    Lista->head = NULL;
}

void mostrarLista(tLista *Lista){
    if(Lista->head==NULL) printf("[ ]\n");
    else{
        printf("[");
      	tNodo * current = Lista->head;
 		while (current != NULL){
 			printf(" %d ",current->dato);
 			current = current->sig;
 		}
        printf("]");
        printf("\n");
    }
}

void liberarLista(tLista *Lista){
    tNodo * current = Lista->head;
    while(current != NULL){
        current = current->sig; 
        free(current);
    }
    free(Lista->head);
    free(Lista);
}

int main(){
    tLista *Lista = crearLista();
    printf("El tamaño inicial de la lista es de: %d\n", Lista->size);
    insertarNodo(Lista, 1);
    printf("El dato en el primer elemento de la lista es: %d\n",Lista->head->dato);
    printf("El tamaño de la lista es de: %d\n", Lista->size);
    mostrarLista(Lista);

    printf("\n");

    insertarNodo(Lista, 7);
    insertarNodo(Lista, 4);
    insertarNodo(Lista, 3);
    insertarNodo(Lista, 9);
    insertarNodo(Lista, 21);
    printf("El tamaño de la lista es de: %d\n", Lista->size);

    mostrarLista(Lista);
    borrarPorIndice(Lista, 5);
    borrarPorIndice(Lista, 1);
    mostrarLista(Lista);
    insertarNodo(Lista, 32);
    insertarNodo(Lista, 12);
    insertarNodo(Lista, 51);
    mostrarLista(Lista);
    borrarPorIndice(Lista, 5);
    borrarPorIndice(Lista, 0);
    insertarPorIndice(Lista, 99, 1);
    mostrarLista(Lista);

    insertarPorIndice(Lista, 9, 0);
    mostrarLista(Lista);

    insertarPorIndice(Lista, 9, 0);
    mostrarLista(Lista);

    insertarPorIndice(Lista, 1, 0);
    mostrarLista(Lista);

    borrarPorIndice(Lista, 3);
    mostrarLista(Lista);

    printf("El tamaño de la lista es de: %d\n", Lista->size);
    borrarPorElemento(Lista, 99);
    borrarTodos(Lista);
    mostrarLista(Lista);

    printf("El tamaño de la lista es de: %d\n", Lista->size);
    liberarLista(Lista);

    return 0;
}
