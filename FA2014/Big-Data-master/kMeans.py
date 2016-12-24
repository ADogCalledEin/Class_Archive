import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import matplotlib.pyplot as plt
import bdlibrary
from sklearn.cross_validation import train_test_split
import math
from numpy import ndarray

def calculateDistance(instance1, instance2):
    return math.sqrt((instance1[0] - instance2[0]) ** 2 + (instance1[1] - instance2[1]) ** 2)


def getKInitialPoints(df, k):
    h = len(df.index)
    rands = np.random.randint(0, h-1, k)
    print rands
    startpoints = []
    for i in range(k):
        startpoints.append(df.iloc[rands[i]].values)
    print startpoints
    return startpoints


# Assuming startpoints is an array of points
def categorizeBasedOnStartpoints(df, startpoints):
    
    


# Create an array of points (x,y) such that the first point's x is the mean of all
# instances of class 0, the first point's y is the mean of all instances of class 0, etc
def createNewStartPoints(df):
    zeroDF = df[df.classification == 0]
    oneDF = df[df.classification == 1]
    twoDF = df[df.classification == 2]
    
    return [(sum(zeroDF.petalLength)/len(zeroDF), sum(zeroDF.petalWidth)/len(zeroDF)),
            (sum(oneDF.petalLength)/len(oneDF), sum(oneDF.petalWidth)/len(oneDF)),
            (sum(twoDF.petalLength)/len(twoDF), sum(twoDF.petalWidth)/len(twoDF))]

def plotOnAxis(ax, df):
    zeroDf = df[df.classification == 0];
    oneDf = df[df.classification == 1];
    twoDf = df[df.classification == 2];

    ax.scatter(zeroDf.petalLength, zeroDf.petalWidth, marker='o', color='r', alpha=0.6)
    ax.scatter(oneDf.petalLength, oneDf.petalWidth, marker='+', color='b', alpha=0.6)
    ax.scatter(twoDf.petalLength, twoDf.petalWidth, marker='*', color='g', alpha=0.6)

def plotStartPoints(startpoints):
    plt.scatter(startpoints[0][0], startpoints[0][1], marker='o', color='r')
    plt.scatter(startpoints[1][0], startpoints[1][1], marker='+', color='b')
    plt.scatter(startpoints[2][0], startpoints[2][1], marker='*', color='g')


def main():
    df = pd.read_csv('irisWithNames.csv', header=0)
    del df['sepalLength']
    del df['sepalWidth']

    fig, axes = plt.subplots(2,2);
    
    startpoints = getKInitialPoints(df, 3)





    plt.show()


if __name__ == '__main__':
    main()
