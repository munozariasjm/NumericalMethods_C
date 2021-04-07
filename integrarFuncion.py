from scipy.integrate import quad
import math
import numpy as np 

def funcion(x):
    return (np.sin(x)+np.cos(x))/(x**4)
#Ingresar el limite superior
inferior=10
#Ingresar límite superior
superior=15
resultado = quad(funcion, inferior, superior)
print(type(resultado))
print("El resultado de la integral es {} con un error de {}\n".format(resultado[0],resultado[1]),end="")