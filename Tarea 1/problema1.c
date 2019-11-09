#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****
*   char** tablero
******
*   La función tablero crea un arreglo de arreglos en el cual almacena el tablero a estudiar.
******
*   Input:
*       FILE* fp : El archivo fp es el archivo .txt en el cual se encuentran almacenados los tableros.
******
*   Returns:
*       char**, Retorna el arreglo de arreglos.
*****/
char **tablero(FILE *fp){
    char b,**tablero;
    int i,j=0,l=0;
    tablero = (char**)malloc(sizeof(char*)*8);
    tablero[l]=(char*)malloc(sizeof(char)*8);
    fscanf(fp,"%c",&b);
    for (i=0;i<64;i++){
        fscanf(fp,"%c",&b);
        tablero[l][j]=b;
        j++;
        if (j==8){
            j=0;
            fscanf(fp,"%c",&b);
            if (i<56){
                l++;
                tablero[l]=(char*)malloc(sizeof(char)*8);
            }
        }
    }
    return tablero;
}

/*****
*   int* BuscarRey
******
*   La función busca cualquiera de los reyes.
******
*   Input:
*       int rey : Es un entero que es equivalente al código ASCII de "k" ó "K", dependediendo de cual rey queramos buscar.
*       char** matriz : Es el arreglo de arreglos el cual contiene al tablero en estudio.
******
*   Returns:
*       int*, Retorna un arreglo de tamaño 2, el cual contiene la posición del rey.
*****/
int * BuscarRey(int rey,char **matriz){
    int i,j,*POS = (int *)malloc(sizeof(int)*2);
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(matriz[i][j] == rey){
                POS[0] = i;
                POS[1] = j;
                return POS;
            }
        }
    }
    return POS;
}

/*****
*   int* Peon
******
*   Ve si alguno de los 2 reyes está en jaque por algún peón.
******
*   Input:
*       int* PosReyN: posición del rey negro.
*       int* PosReyB: posición del rey blanco.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna si los reyes estan en jaque por el peon, jaque[0] para el rey negro y jaque[1] para el rey blanco.
*****/
int* Peon(int *PosReyB,int *PosReyN,char ** tablero){
    int *jaque=(int*)malloc(sizeof(int)*2);
    int i=0,j=0;
    jaque[0]=0;
    jaque[1]=0;
    if (PosReyN[1]==0){
        if (tablero[PosReyN[0]+1][PosReyN[1]+1] == 80) jaque[0]=1;
        i++;
    }
    if (PosReyN[1]==7){
        if (tablero[PosReyN[0]+1][PosReyN[1]-1] == 80) jaque[0]=1;
        i++;
    }
    if (PosReyN[0]==7) i++;

    if (PosReyB[1]==0){
        if (tablero[PosReyB[0]-1][PosReyB[1]+1] == 112) jaque[1]=1;
        j++;
    }
    if (PosReyB[1]==7){
        if (tablero[PosReyB[0]-1][PosReyB[1]-1] == 112) jaque[1]=1;
        j++;
    }
    if (PosReyB[0]==0) j++;

    if(i==0){
        if (tablero[PosReyN[0]+1][PosReyN[1]+1] == 80 || tablero[PosReyN[0]+1][PosReyN[1]-1] == 80) jaque[0]=1;
    }
    if(j==0){
        if (tablero[PosReyB[0]-1][PosReyB[1]+1] == 112 || tablero[PosReyB[0]-1][PosReyB[1]-1] == 112) jaque[1]=1;
    }
    return jaque;
}

/*****
*   char movDer
******
*   Funcion de movimiento de la torre.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición de la torre.
*****/
char movDer(int* a,char** tablero){
  int i,a0,a1;
  a0=a[0];
  a1=a[1];
  for (i=0;i<8;i++){
      if (a1!=7){
          if (tablero[a0][a1+1]!=46) return tablero[a0][a1+1];
          else a1++;
      }
  }
  return 46;
}

/*****
*   char movIzq
******
*   Funcion de movimiento de la torre.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición de la torre.
*****/
char movIzq(int* a,char** tablero){
  int i,a0,a1;
  a0=a[0];
  a1=a[1];
  for (i=0;i<8;i++){
      if (a1!=0){
          if (tablero[a0][a1-1]!=46) return tablero[a0][a1-1];
          else a1--;
      }
  }
  return 46;
}

/*****
*   char movArr
******
*   Funcion de movimiento de la torre.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición de la torre.
*****/
char movArr(int* a,char** tablero){
  int i,a0,a1;
  a0=a[0];
  a1=a[1];
  for (i=0;i<8;i++){
        if (a0!=0){
          if (tablero[a0-1][a1]!=46) return tablero[a0-1][a1];
          else a0--;
        }
  }
  return 46;
}

/*****
*   char movAba
******
*   Funcion de movimiento de la torre.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición de la torre.
*****/
char movAba(int* a,char** tablero){
  int i,a0,a1;
  a0=a[0];
  a1=a[1];
  for (i=0;i<8;i++){
      if (a0!=7){
          if (tablero[a0+1][a1]!=46) return tablero[a0+1][a1];
          else a0++;
      }
  }
  return 46;
}

/*****
*   int* Torre
******
*   Ve si algunas de las funciones de movimiento retornó una torre.
******
*   Input:
*       int* PosReyN: posición del rey negro.
*       int* PosReyB: posición del rey blanco.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna si los reyes estan en jaque por la torre, jaque[0] para el rey negro y jaque[1] para el rey blanco.
*****/
int * Torre(int* PosReyN,int* PosReyB,char** tablero){
  int *jaque = (int*)malloc(sizeof(int)*2); //jaque[0]=reyn jaque[1]=reyb
  char upN,doN,deN,izN,upB,doB,deB,izB;
  jaque[0]=0;
  jaque[1]=0;
  upN = movArr(PosReyN,tablero);
  doN = movAba(PosReyN,tablero);
  deN = movDer(PosReyN,tablero);
  izN = movIzq(PosReyN,tablero);
  upB = movArr(PosReyB,tablero);
  doB = movAba(PosReyB,tablero);
  deB = movDer(PosReyB,tablero);
  izB = movIzq(PosReyB,tablero);
  if (upN == 84 || doN == 84 || deN == 84 || izN == 84) jaque[0]=1;
  if (upB == 116 || doB == 116 || deB == 116 || izB == 116) jaque[1]=1;
  return jaque;
}

/*****
*   char movDerAb
******
*   Funcion de movimiento del alfil.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del alfil.
*****/
char movDerAb(int* a,char** tablero){
  int i,a0,a1;
  a0=a[0];
  a1=a[1];
  for (i=0;i<8;i++){
      if (a0 != 7 && a1 != 7){
          if (tablero[a0+1][a1+1]!=46) return tablero[a0+1][a1+1];//46 es el punto
          else{
              a0++;
              a1++;
          }
      }
  }
  return 46;
}

/*****
*   char movIzqAb
******
*   Funcion de movimiento del alfil.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del alfil.
*****/
char movIzqAb(int* a,char** tablero){
  int i,a0,a1;
  a0=a[0];
  a1=a[1];
  for (i=0;i<8;i++){
      if (a0 != 7 && a1 != 0){
          if (tablero[a0+1][a1-1]!=46) return tablero[a0+1][a1-1];//46 es el punto
          else{
              a0++;
              a1--;
          }
      }
  }
  return 46;
}

/*****
*   char movIzqArr
******
*   Funcion de movimiento del alfil.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del alfil.
*****/
char movIzqArr(int* a,char** tablero){
  int i,a0,a1;
  a0=a[0];
  a1=a[1];
  for (i=0;i<8;i++){
      if (a0 != 0 && a1 != 0){
          if (tablero[a0-1][a1-1]!=46) return tablero[a0-1][a1-1];//46 es el punto
          else{
              a0--;
              a1--;
          }
      }
  }
  return 46;
}

/*****
*   char movDerArr
******
*   Funcion de movimiento del alfil.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del alfil.
*****/
char movDerArr(int* a,char** tablero){
    int i,a0,a1;
    a0=a[0];
    a1=a[1];
    for (i=0;i<8;i++){
        if (a0 != 0 && a1 != 7){
            if (tablero[a0-1][a1+1]!=46) return tablero[a0-1][a1+1];//46 es el punto
            else{
                a0--;
                a1++;
            }
        }
    }
    return 46;
}

/*****
*   int* Alfil
******
*   Ve si algunas de las funciones de movimiento retornó un alfil.
******
*   Input:
*       int* PosReyN: posición del rey negro.
*       int* PosReyB: posición del rey blanco.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna si los reyes estan en jaque por el alfil, jaque[0] para el rey negro y jaque[1] para el rey blanco.
*****/
int *Alfil(int *PosReyB,int *PosReyN,char ** tablero){
    int *jaque=(int*)malloc(sizeof(int)*2); //jaque[0]=reyn y jaque[1]=reyb
    char sdB,asB,awB,wdB,sdN,asN,awN,wdN;
    jaque[0]=0;
    jaque[1]=0;
    awN=movIzqArr(PosReyN,tablero);
    wdN=movDerArr(PosReyN,tablero);
    asN=movIzqAb(PosReyN,tablero);
    sdN=movDerAb(PosReyN,tablero);
    awB=movIzqArr(PosReyB,tablero);
    asB=movIzqAb(PosReyB,tablero);
    wdB=movDerArr(PosReyB,tablero);
    sdB=movDerAb(PosReyB,tablero);
    if (sdN==65 || asN==65 || awN==65 || wdN==65) jaque[0]=1;
    if (sdB==97 || asB==97 || awB==97 || wdB==97) jaque[1]=1;
    return jaque;
}

/*****
*   int* Reina
******
*   Ve si algunas de las funciones de movimiento retornó una reina.
******
*   Input:
*       int* PosReyN: posición del rey negro.
*       int* PosReyB: posición del rey blanco.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna si los reyes estan en jaque por la reina, jaque[0] para el rey negro y jaque[1] para el rey blanco.
*****/
int * Reina(int* PosReyN, int*PosReyB,char** tablero){
    int* jaque = (int*)malloc(sizeof(int)*2);
    char sdB,asB,awB,wdB,sdN,asN,awN,wdN,upN,doN,deN,izN,upB,doB,deB,izB;
    jaque[0]=0;
    jaque[1]=0;
    upN = movArr(PosReyN,tablero);
    doN = movAba(PosReyN,tablero);
    deN = movDer(PosReyN,tablero);
    izN = movIzq(PosReyN,tablero);
    upB = movArr(PosReyB,tablero);
    doB = movAba(PosReyB,tablero);
    deB = movDer(PosReyB,tablero);
    izB = movIzq(PosReyB,tablero);
    if (upN == 82 || doN == 82 || deN == 82 || izN == 82) jaque[0]=1;
    if (upB == 114 || doB == 114 || deB == 114 || izB == 114) jaque[1]=1;
    sdN=movDerAb(PosReyN,tablero);
    asN=movIzqAb(PosReyN,tablero);
    awN=movIzqArr(PosReyN,tablero);
    wdN=movDerArr(PosReyN,tablero);
    sdB=movDerAb(PosReyB,tablero);
    asB=movIzqAb(PosReyB,tablero);
    awB=movIzqArr(PosReyB,tablero);
    wdB=movDerArr(PosReyB,tablero);
    if (sdN==82 || asN==82 || awN==82 || wdN==82) jaque[0]=1;
    if (sdB==114 || asB==114 || awB==114 || wdB==114) jaque[1]=1;
    return jaque;
}

/*****
*   char movArrArrDer
******
*   Funcion de movimiento del caballo.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del caballo.
*****/
char movArrArrDer(int* a,char** tablero){
    if (a[0]-2>-1 && a[1]+1<8) return tablero[a[0]-2][a[1]+1];
    return 46;
}

/*****
*   char movArrArrIzq
******
*   Funcion de movimiento del caballo.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del caballo.
*****/
char movArrArrIzq(int*a,char** tablero){
    if (a[0]-2>-1 && a[1]-1>-1) return tablero[a[0]-2][a[1]-1];
    return 46;
}

/*****
*   char movAbaAbaDer
******
*   Funcion de movimiento del caballo.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del caballo.
*****/
char movAbaAbaDer(int*a,char** tablero){
    if (a[0]+2<8 && a[1]+1<8) return tablero[a[0]+2][a[1]+1];
    return 46;
}

/*****
*   char movAbaAbaIzq
******
*   Funcion de movimiento del caballo.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
* Returns:
*       int*, retorna la posible posición del caballo.
*****/
char movAbaAbaIzq(int*a,char** tablero){
    if (a[0]+2<8 && a[1]-1>-1) return tablero[a[0]+2][a[1]-1];
    return 46;
}

/*****
*   char movDerDerArr
******
*   Funcion de movimiento del caballo.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del caballo.
*****/
char movDerDerArr(int*a,char** tablero){
    if (a[0]-1>-1 && a[1]+2<8) return tablero[a[0]-1][a[1]+2];
    return 46;
}

/*****
*   char movDerDerAba
******
*   Funcion de movimiento del caballo.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del caballo.
*****/
char movDerDerAba(int*a,char** tablero){
    if (a[0]+1<8 && a[1]+2<8) return tablero[a[0]+1][a[1]+2];
    return 46;
}

/*****
*   char movIzqIzqArr
******
*   Funcion de movimiento del caballo.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del caballo.
*****/
char movIzqIzqArr(int*a,char** tablero){
    if (a[0]-1>-1 && a[1]-2>-1) return tablero[a[0]-1][a[1]-2];
    return 46;
}

/*****
*   char movIzqIzqAba
******
*   Funcion de movimiento del caballo.
******
*   Input:
*       int* a: posición del rey.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna la posible posición del caballo.
*****/
char movIzqIzqAba(int*a,char** tablero){
    if (a[0]+1<8 && a[1]-2>-1) return tablero[a[0]+1][a[1]-2];
    return 46;
}

/*****
*   int* Caballo
******
*   Ve si algunas de las funciones de movimiento retornó un caballo.
******
*   Input:
*       int* PosReyN: posición del rey negro.
*       int* PosReyB: posición del rey blanco.
*       char** tablero: tablero de ajedrez.
******
*   Returns:
*       int*, retorna si los reyes estan en jaque por el caballlo, jaque[0] para el rey negro y jaque[1] para el rey blanco.
*****/
int* Caballo(int* PosReyN,int* PosReyB,char** tablero){
    int *jaque = (int*)malloc(sizeof(int)*2);
    char wwdN,wwaN,ssdN,ssaN,ddwN,ddsN,aawN,aasN;
    char wwdB,wwaB,ssdB,ssaB,ddwB,ddsB,aawB,aasB;
    jaque[0]=0;
    jaque[1]=0;
    wwdN = movArrArrDer(PosReyN,tablero);
    wwaN = movArrArrIzq(PosReyN,tablero);
    ssdN = movAbaAbaDer(PosReyN,tablero);
    ssaN = movAbaAbaIzq(PosReyN,tablero);
    ddwN = movDerDerArr(PosReyN,tablero);
    ddsN = movDerDerAba(PosReyN,tablero);
    aawN = movIzqIzqAba(PosReyN,tablero);
    aasN = movIzqIzqAba(PosReyN,tablero);

    wwdB = movArrArrDer(PosReyB,tablero);
    wwaB = movArrArrIzq(PosReyB,tablero);
    ssdB = movAbaAbaDer(PosReyB,tablero);
    ssaB = movAbaAbaIzq(PosReyB,tablero);
    ddwB = movDerDerArr(PosReyB,tablero);
    ddsB = movDerDerAba(PosReyB,tablero);
    aawB = movIzqIzqAba(PosReyB,tablero);
    aasB = movIzqIzqAba(PosReyB,tablero);
    if (wwdN==67 || wwaN==67 || ssdN==67 || ssaN==67 || ddwN==67 || ddsN==67 || aawN==67 || aasN==67) jaque[0]=1;
    if (wwdB==99 || wwaB==99 || ssdB==99 || ssaB==99 || ddwB==99 || ddsB==99 || aawB==99 || aasB==99) jaque[1]=1;
    return jaque;
}

/*****
* int LiberarTablero
******
* Libera el tablero de ajedrez.
******
* Input:
*     char** tablero: tablero de ajedrez.
******
* Returns:
*     int, retorna 0 para no tener problemas al compilar.
*****/
int LiberarTablero(char** tablero){
	int i;
	for(i=0;i<8;i++){
	    free((void *)tablero[i]);
	}
	free((void **)tablero);
  return 0;
}

int main(){
    int i=0,x,*reyblanco,*reynegro,*p,*a,*t,*r,*c;
    char **ajedrez;
    FILE *fp;
    fp = fopen("tableros.txt","r");
    while (1){//Realiza el analisis de todos los tableros que se encuentren en el archivo .txt
        fscanf(fp,"%d",&x);
        if (x==0) break;
        ajedrez=tablero(fp);
        reyblanco=BuscarRey(75,ajedrez);
        reynegro=BuscarRey(107,ajedrez);
        p=Peon(reyblanco,reynegro,ajedrez);
        a=Alfil(reyblanco,reynegro,ajedrez);
        t=Torre(reynegro,reyblanco,ajedrez);
        r=Reina(reynegro,reyblanco,ajedrez);
        c=Caballo(reynegro,reyblanco,ajedrez);
        if(p[0]==1 || a[0]==1 || t[0]==1 || r[0]==1 || c[0]==1) {
            printf("Tablero #%d: Rey Negro en Jaque\n",x);
            i++;
        }
        if(p[1]==1 || a[1]==1 || t[1]==1 || r[1]==1 || c[1]==1){
            printf("Tablero #%d: Rey Blanco en Jaque\n",x);
            i++;
        }
        if(i==0) printf("Tablero #%d: No hay Rey en Jaque\n",x);
        i=0;
    }
	LiberarTablero(ajedrez);
  free((void *)reyblanco);
  free((void *)reynegro);
  free((void *)p);
  free((void *)a);
  free((void *)t);
  free((void *)r);
  free((void *)c);
  fclose(fp);
  return 0;
}
