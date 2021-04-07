#include <stdio.h>
#include <math.h>

// y(x_0)=y_0 (El PVI)
float y_0=1;
//Valor Inicial del intervalo
float inicioIntervalo=0;
//Valor final del intervalo
float finIntervalo=10;
// diferencial del intervalo
float diferenciaPuntos=0.01; 

float funcion(float x,float y) {return (5*pow(x,2)-y)/exp(x+y);}

//float solucionAnalitca(float x) {return exp(x)-2*pow(x,2);}


int main()
{
 
    FILE * archivo=fopen("datosRk4.csv","w");
    fprintf(archivo,"X,Y_aproximado\n");
    float k1,k2,k3,k4,y_1;
    for(float x_0=inicioIntervalo;x_0<finIntervalo+diferenciaPuntos;x_0+=diferenciaPuntos) 
    {
        fprintf(archivo,"%f,%f\n",x_0,y_0);
        k1=funcion(x_0,y_0);
        k2=funcion(x_0+diferenciaPuntos/2,y_0+k1*diferenciaPuntos/2);
        k3=funcion(x_0+diferenciaPuntos/2,y_0+k2*diferenciaPuntos/2);
        k4=funcion(x_0+diferenciaPuntos,y_0+diferenciaPuntos*k3);  
        y_1=y_0+(diferenciaPuntos/6)*(k1+2*k2+2*k3+k4);
        y_0=y_1; 
    }
    fclose(archivo);
    return 0;
}