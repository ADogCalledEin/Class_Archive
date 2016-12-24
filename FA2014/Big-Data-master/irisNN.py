'''
Created on Oct 15, 2014

@author: GriffinSiadak
'''
import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import matplotlib.pyplot as plt
import bdlibrary
from sklearn.cross_validation import train_test_split
import math 

def calculateDistance(instance1, instance2):
    return math.sqrt((instance1[0] - instance2[0]) ** 2 + (instance1[1] - instance2[1]) ** 2)



def main():
    
    df = pd.read_csv('iris.csv', header=0)
    df = df[df.classification != 'Iris-setosa']
    
    df.classification = np.where(df.classification == 'Iris-versicolor', 0, 1)
    
    cols = ['petalLength', 'petalWidth']
    
    x = df[cols].values
    y = df.classification.values
    
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.4, random_state=1)
    
    petalList = np.column_stack((x_train, y_train.T))
    
    
    bdlibrary.plot_dataset(x_train, y_train)
    
    plt.show()
    
if __name__ == '__main__':
    main()