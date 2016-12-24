'''
Created on Oct 8, 2014

@author: GriffinSiadak
'''
import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import matplotlib.pyplot as plt

df = pd.read_csv('iris.csv', header=0)
# df = df[df.classification != 'Iris-setosa']

versicolorDF = df[df.classification == 'Iris-versicolor']
virginicaDF = df[df.classification == 'Iris-virginica']
setosaDF = df[df.classification == 'Iris-setosa']


plt.scatter(versicolorDF.petalLength, versicolorDF.petalWidth, marker = 'o', color = 'b')
plt.scatter(virginicaDF.petalLength, virginicaDF.petalWidth, marker = 'x', color = 'r')
plt.scatter(setosaDF.petalLength, setosaDF.petalWidth, marker = 'x', color = 'g')

plt.xlabel('Petal Length')
plt.ylabel('Petal Width')

plt.legend(['Versicolor', 'Virginica','Setosa'])
plt.show()