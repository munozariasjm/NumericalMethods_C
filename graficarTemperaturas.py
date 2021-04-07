import pandas as pd
import matplotlib.pyplot as plt

datos = pd.read_csv("temperaturas.csv", header=None)
print(datos.loc[0,[2,3]])

print([i for i in range(1,8)])

for i in range(datos.shape[0]):
    datos.loc[i,[i for i in range(1,datos.shape[1])]].plot.line(label="t:{}".format(datos.loc[i,0]))
plt.legend()
plt.show()

datos.plot.line(x=0,y=[1,5,6,10])
plt.show()
