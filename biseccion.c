#include<stdio.h>
#include <math.h>

//Límite inferior del intervalo
float pi=0.5; 
// Límite superior del intervalo
float pf=1.5;
//Tolerancia del programa 
float error=0.00002;
//Iteraciones máximas para hacer pullout
int limite=100;


//Definir la función igualada a 0 para encontrar la raíz
float funcion(float x)
{
    return 3*sin(x)-4*cos(x)-(1/(1+exp(-x)));
    
}


int main()
{
    float valor,raiz;
    int iteracion=0;
    FILE * archivo=fopen("datosBiseccion.csv","w");
    if (funcion(pi)*funcion(pf)>=0) printf("Rango no valido");
    else
    {
        fprintf(archivo,"Iteracion,Punto inicial,Punto final,Raiz,Raiz en funcion\n");      
        do
        {
            if (iteracion == limite) break;
            raiz = (pi+pf)/2;
            valor=funcion(raiz);
            fprintf(archivo,"%i,%f,%f,%f,%f\n",iteracion+1,pi,pf,raiz,valor);
            if (funcion(pi)*funcion(raiz)<0) pf=raiz;
            else pi=raiz;
            iteracion++;
        } while (fabs(valor)>error);
        fclose(archivo);
        printf("Raiz encontrada evaluada en la funcion:\nf(%f)=%f\n",raiz,funcion(raiz));
    }
    return 0;
}
