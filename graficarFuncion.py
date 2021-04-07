import numpy as np
import matplotlib.pyplot as plt

def funcion(x):
    return 3*np.sin(x)-4*np.cos(x)-(1/(1+np.exp(-x)))


x = np.linspace(-2,2,100)
print(x)
y = funcion(x)
fig,ax=plt.subplots()
ax.plot(x,y,label="Funcion")
ax.set_title("Grafica Funcion")
plt.show()