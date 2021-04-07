import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d

# datos = pd.read_csv("datosEuler.csv")
datos = pd.read_csv("datosRk4.csv")
x = datos['X']
y = datos['Y_aproximado']

funcion = interp1d(x, y, kind='cubic')
step=-np.min(x)+np.max(x)/100

xNuevo = np.arange(np.min(x),np.max(x),step)
plt.plot(x, y,'ob')
plt.plot(xNuevo, funcion(xNuevo),'--r')
#print(funcion(xNuevo))
plt.legend(['Datos', 'Interpolacion'], loc='best')
plt.show()