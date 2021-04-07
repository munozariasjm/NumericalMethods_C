#include<stdio.h>
#include <math.h>

//Límite inferior del intervalo
float pi=-10; 
// Límite superior del intervalo
float pf=10;
//Tolerancia del programa 
float error=0.1;
//Iteraciones máximas para hacer pullout
int limite=1000;

float funcion(float x)
{
    return ((pow(x,3)))+pow(x,2);
    // return 3*sin(x-2)+5*tan(x);
}



int main()
{

    float valor,raiz;
    int iteracion=0;
    FILE * archivo=fopen("datosSecante.csv","w");
    fprintf(archivo,"Iteracion,Punto inicial,Punto final,Raiz,Raiz en funcion\n");   
    do
    {
        if(iteracion == limite) break;
        raiz = pf-(funcion(pf)*(pf-pi))/(funcion(pf)-funcion(pi));
        valor=funcion(raiz);
        fprintf(archivo,"%i,%f,%f,%f,%f\n",iteracion+1,pi,pf,raiz,valor);
        pi = pf;
        pf = raiz;
        iteracion++;
    } while (fabs(valor)>error);
    fclose(archivo);
    printf("Raiz encontrada evaluada en la funcion:\nf(%f)=%f\n",raiz,funcion(raiz));
    return 0;
}


