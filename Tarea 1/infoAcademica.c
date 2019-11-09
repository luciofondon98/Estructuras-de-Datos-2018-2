#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char sigla[6];
    unsigned int nota;
}curso;

typedef struct{
    char nombre[30];
    unsigned int rol;
    curso cursosRealizados[50];
    int numCursos;
}alumno;

/*****
*   void riesgoAcademico
******
*   La función recorre el archivo de entrada, los almacena en un arreglo de structs, para luego poder manejar los datos y poder calcular quienes están en riesgo académico.
******
*   Input:
*       FILE* entrada : El archivo "alumnos.dat".
*       FILE* salida : El archivo "riesgo_academico.txt".
******
*   Returns:
*       void, No retorna nada.
*****/
void riesgoAcademico(FILE *entrada, FILE *salida){
    int i,j,n,cantidad;
    float promedio;
    fread(&n, sizeof(int), 1, entrada);
    alumno *alumnos;
    alumnos = (alumno *)malloc(sizeof(alumno)*n);
    for (i=0; i<n; i++){
        int notas = 0;
        fread(&alumnos[i], sizeof(alumno), 1, entrada);
        cantidad = alumnos[i].numCursos;
        for (j=0; j<cantidad; j++){
            notas += alumnos[i].cursosRealizados[j].nota;
        }
        promedio = notas/cantidad;
        if (promedio < 55){
            fprintf(salida, "%s%d está en riesgo academico.  ", alumnos[i].nombre, alumnos[i].rol);
        }
    }
  free(alumnos);
}

int main(int argc, char const *argv[]) {
    FILE *entrada, *salida;
    entrada = fopen(argv[1],"r");
    if (entrada==NULL){
        printf("Archivo no existe\n" );
        exit(1);
    }
    salida = fopen("riesgo_academico.txt", "w");
    riesgoAcademico(entrada,salida);
    fclose(entrada);
    fclose(salida);
    return 0;
}
