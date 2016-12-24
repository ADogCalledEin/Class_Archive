'''
Created on Nov 12, 2014

@author: GriffinSiadak with a large amount of assistance from Miguel Guerrero
'''

import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import GriffinSiadakHmwk4 as hmk
import math as m
import matplotlib.pyplot as plt

def crossValidation(df, k):
    t = 1
    normalFold = len(df.index)/k
    remainder = len(df.index)%k
    remainderFold = normalFold + 1
    fold = normalFold
    if remainder > 0:
        fold = remainderFold
    front = 0
    back = front + fold
    error = 0.0
    quadloss = 0.0
    infoloss = 0.0
    while back < len(df.index) + 1:
        print t, ': ', back, 'Fold Size: ', fold
        testdf, traindf = df.copy(), df.copy()
        testdf = testdf[front:back]
        traindf = traindf.drop(traindf.index[front:back])
        
        if remainder <= 1:
            fold = normalFold
        
        returned = hmk.findProbabilities(testdf, traindf)
        for key in returned:
            if key == 'Error Rate':
                error += returned[key]
            if key == 'Quad Loss':
                quadloss += returned[key]
            if key == 'Info Loss':
                infoloss += returned[key]
        front = back
        back = front + fold
        remainder -= 1
        t += 1
        
    errorRate = error/len(df.index)
    print 'Error Rate: ', errorRate
    print 'Quadratic Loss: ', quadloss
    print 'Informational Loss: ', infoloss
    successRate = 1  - errorRate
    print 'Success Rate: ', successRate

def main():
    shroomsDF = pd.read_csv('mushroom.csv', header = 0)
    shroomsDF['probability'] = 0
    cols = shroomsDF.columns.tolist()
    cols = cols[1:] + cols[:1]
    cols = cols[13:]
    shroomsDF = shroomsDF[cols]
    babiesDF = pd.read_csv('nursery.csv', header = 0)
    babiesDF = babiesDF.drop(babiesDF.index[[12960]])
    
    print 'Shrooms Data:'
    crossValidation(shroomsDF, 10)
    print '##################'
    print 'Nursery Data:'
    crossValidation(babiesDF, 10)
    
    
    ROC = plt.figure(figsize=(4,4), dpi = 80)
    plt.xlabel("False Positive Rate", fontsize = 14)
    plt.ylabel("True Positive Rate", fontsize = 14)
    plt.title("ROC Curve", fontsize = 14)
    
    
    
    
    
    
    plt.show()
    
if __name__ == '__main__':
    main() 
            