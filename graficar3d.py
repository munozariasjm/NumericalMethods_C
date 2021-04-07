import numpy as np 
import matplotlib.pyplot as plt 
import pandas as pd

# https://www.geeksforgeeks.org/three-dimensional-plotting-in-python-using-matplotlib/

datos = pd.read_csv("ondas.csv")
datos = datos.drop(datos.columns[-1],axis=1)

tiempos = datos['t']
datos = datos.drop(['t'],axis=1)

fig = plt.figure() 
ax = plt.axes(projection ='3d') 
posiciones = np.array(datos.columns).astype(float)
unos = np.ones(posiciones.shape[0])
for i in range(tiempos.shape[0]):
    ax.plot3D(posiciones, unos*tiempos.iloc[i], datos.iloc[i], 'blue')

ax.set_title('Ecuacion de onda') 
ax.set_xlabel('Posicion')
ax.set_ylabel('Tiempo')
ax.set_zlabel('Desplazamiento')
plt.show() 
