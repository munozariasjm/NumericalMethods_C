#include <stdio.h>
#include <math.h>

/////////////////////////////////////
//      Resolver ODEs de la forma  //
//    d/dt(z) = a² d²/dx²(z)       //
/////////////////////////////////////

//Límite izquierdo intervalo espacial (x min)
float a=0;
//Límite derecho intervalo temporal (x max)
float b=15;
//Tiempo final para integrar (y max)
float tiempoFinal=50;
//Coeficiente alfa² en la ODE
float coeficiente=0.05; 
//Número de diferenciales de tiempo
int cantidadTiempos=100;
//Número de diferenciales de posicion
int cantidadPosiciones=60;

// Condicion en t=0 -> z(x,t=0)
float g1(float x) {return 20*sin(x+30);}
//Función para el extremo menor del intervalo espacial
float g2(float t) {return exp(-t);}
//Funcion para el extremo mayor del intervalo espacial
float g3(float t) {return -log(t+5);}


 
int main() 
{ 

    float matriz[cantidadTiempos][cantidadPosiciones];

    float h = abs(b-a)/((float)cantidadPosiciones-1); //Tamaño diferencial de longitud 
    float k = tiempoFinal/((float)cantidadTiempos-1); //Tamaño diferencial de tiempo

    for (int x=0; x<cantidadPosiciones; x++) matriz[0][x] = g1(a+x*h);
    for (int t = 1; t < cantidadTiempos; t++)
    {
        matriz[t][0] = g2(t*k);
        matriz[t][cantidadPosiciones-1] = g3(t*k);
    }

    float factor = (k*coeficiente)/pow(h,2); //Factor para resolver, DEBE ser menos de 0.5
    //printf("El factor es de %f",factor);
    for (int t = 0; t < cantidadTiempos-1; t++)
    {
        for (int x = 1; x < cantidadPosiciones-1; x++)
        {
            matriz[t+1][x]=matriz[t][x]+factor*(matriz[t][x+1]-2*matriz[t][x]+matriz[t][x-1]);
        }
    }

    FILE * archivo=fopen("temperaturas.csv","w");
    for (int t = 0; t < cantidadTiempos; t++)
    {
        fprintf(archivo,"%f,",t*k);
        for (int x = 0; x < cantidadPosiciones; x++)
        {
            printf("Temperatura[%i][%i] = %1.5f\n",t,x,matriz[t][x]);
            if (x == cantidadPosiciones-1) fprintf(archivo,"%f",matriz[t][x]);
            else fprintf(archivo,"%f,",matriz[t][x]);
        }
        fprintf(archivo,"\n");
    } 
    fclose(archivo);

    return 0; 
}