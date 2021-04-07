#include<stdio.h>
#include<math.h>

// Número de parabolas a ejecutar
int parabolas=1000;
// Límite inferior de la integral
float li=10;
//Límite Superior de la integral
float ls=15;
 
float funcion(float x) {return (sin(x)+cos(x))/pow(x,4);}


 
int main()
{
    float pares=0, impares=0, suma, altura;
    altura=(ls-li)/(2*parabolas);
    for(int contador=1; contador<=2*parabolas-1; contador++)
    {
        if(contador%2 == 0) pares+=funcion(li+contador*altura);
        else impares+=funcion(li+contador*altura);
    }
    suma=(altura/3)*(funcion(li)+funcion(ls)+4*impares+2*pares);
    printf("Integral utilizando metodo de Simpson 1/3:\t%1.19f",suma);
    return 0;
}