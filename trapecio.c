#include<stdio.h>
#include<math.h>

// Número de trapecios a sumar
int trapecios=100;
//Límite inferior de la integral
float li=10;
//Límite superior de la integral
float ls=15;
 
float funcion(float x) {return (sin(x)+cos(x))/pow(x,4);} //Función a integrar


 
int main()
{
    float altura,suma,resultado;
    altura=(ls-li)/trapecios;
    for(int contador=1; contador<=trapecios-1; contador++) suma+=funcion(li+contador*altura);
    resultado=(altura/2)*(funcion(li)+funcion(ls)+2*suma);
    printf("Integral utilizando metodo del trapecio:\t%1.19f\n", resultado);
    return 0;
}