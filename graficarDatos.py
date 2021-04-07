import pandas as pd
import matplotlib.pyplot as plt

datosEuler = pd.read_csv("datosEuler.csv")
datosRk4 = pd.read_csv("datosRk4.csv")
#print(datos)
datosEuler.plot.line(x='X',y='Y_aproximado')
datosRk4.plot.line(x='X',y='Y_aproximado',c="green")
#plt.show()

def graficaAmbos(datosEuler,datosRk4):
#Graficar ambos Metodos Juntos
    xE=datosEuler["X"];xR=datosRk4["X"]
    yEuler=datosEuler['Y_aproximado'];yRk4=dato
    sRk4['Y_aproximado']
    fig,ax=plt.subplots()
    ax.plot(xE,yEuler,label="Euler",c="blue")
    ax.plot(xR,yRk4,label="Rk4",c="green")
    ax.legend();plt.show()

graficaAmbos(datosEuler,datosRk4)
