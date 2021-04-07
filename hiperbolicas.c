#include <stdio.h>
#include <math.h>

/////////////////////////////////////
//      Resolver ODEs de la forma  //
//    d²/dt²(z) = v² d²/dx² (z)    //
/////////////////////////////////////

//Coordenada x del punto izquierdo del intervalo:
float a=0;
//Coordenada x del punto derecho del intervalo:
float b=0;
//Tiempo máximo
float tiempoFinal=0;
//Velocidad de la onda que se propaga
float velocidad=0; 
//Número de diferenciales de tiempo
int cantidadTiempos=0;
//Número de diferenciales de posicion
int cantidadPosiciones=0;


//Función en t=0 ->  z(x,t=0)
float g1(float x) {return sin(x);}

//Función para el extremo izquierdo
float g2(float t) {return cos(t);}

//Función para el extremo derecho
float g3(float t) {return -cos(t);}

//Velocidad de las partículas en t=0  -> d/dt  z(x,t=0)
float g4(float t) {return cos(t);}


int main() 
{ 
    float matriz[cantidadTiempos][cantidadPosiciones];
    //diferencial de longitud
    float h = (b-a)/((float)cantidadPosiciones-1); 
    //diferencial de tiempo
    float k = tiempoFinal/((float)cantidadTiempos-1);

    for (int x=0; x<cantidadPosiciones; x++) matriz[0][x] = g1(a+x*h);
    for (int t = 1; t < cantidadTiempos; t++)
    {
        matriz[t][0] = g2(t*k);
        matriz[t][cantidadPosiciones-1] = g3(t*k);
    }
    for (int x = 1; x < cantidadPosiciones-1; x++) matriz[1][x] = k*g4(a+x*h)+matriz[0][x];

    float factor = pow((velocidad*k)/h,2);
    for (int t = 1; t < cantidadTiempos-1; t++)
    {
        for (int x = 1; x < cantidadPosiciones-1; x++)
        {
            matriz[t+1][x]=2*(1-factor)*matriz[t][x]+factor*(matriz[t][x+1]+matriz[t][x-1])-matriz[t-1][x];
        }
    }

    FILE * archivo=fopen("ondas.csv","w");
    fprintf(archivo,"t,");
    for (int i = 0; i < cantidadPosiciones; i++) fprintf(archivo,"%1.2f,",a+i*h);
    fprintf(archivo,"\n");
    for (int t = 0; t < cantidadTiempos; t++)
    {
        fprintf(archivo,"%1.2f,",t*k);
        for (int x = 0; x < cantidadPosiciones; x++)
        {
            if (x == cantidadPosiciones-1) fprintf(archivo,"%f",matriz[t][x]);
            else fprintf(archivo,"%f,",matriz[t][x]);
        }
        fprintf(archivo,"\n");
    } 
    fclose(archivo);

    return 0; 
}