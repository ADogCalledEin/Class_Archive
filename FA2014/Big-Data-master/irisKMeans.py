import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import matplotlib.pyplot as plt
import bdlibrary
from sklearn.cross_validation import train_test_split
import math

def calculateDistance(instance1, instance2):
    return math.sqrt((instance1[0] - instance2[0]) ** 2 + (instance1[1] - instance2[1]) ** 2)


def getKInitialPoints(df, k):
    h = len(df.index)
    # np.random.seed(100)
    # np.random.seed(140)
    rands = np.random.randint(0, h-1, k)
    print rands
    startpoints = []
    for i in range(k):
        startpoints.append(df.iloc[rands[i]].values)
    print startpoints
    return startpoints

def categorizeBasedOnStartpoints(df, startpoints):
    h = len(df.index)
    k = len(startpoints)

    for i in range(h):
        currentInstance = df.iloc[i].values
        closestIndex = 0
        closestDist = calculateDistance(currentInstance, startpoints[0])

        for j in range(1, k):
            nDist = calculateDistance(currentInstance, startpoints[j])
            if nDist < closestDist:
                closestDist = nDist
                closestIndex = j

        df.loc[i, 'classification'] = closestIndex

    return df


def createNewStartPoints(df):
    zeroDf = df[df.classification == 0]
    oneDf = df[df.classification == 1]
    twoDf = df[df.classification == 2]

    return [(sum(zeroDf.petalLength)/len(zeroDf), sum(zeroDf.petalWidth)/len(zeroDf)), 
            (sum(oneDf.petalLength)/len(oneDf), sum(oneDf.petalWidth)/len(oneDf)),
            (sum(twoDf.petalLength)/len(twoDf), sum(twoDf.petalWidth)/len(twoDf))]


def plotOnAxis(ax, df):
    zeroDf = df[df.classification == 0];
    oneDf = df[df.classification == 1];
    twoDf = df[df.classification == 2];

    ax.scatter(zeroDf.petalLength, zeroDf.petalWidth, marker='o', color='r', alpha=0.6)
    ax.scatter(oneDf.petalLength, oneDf.petalWidth, marker='+', color='b', alpha=0.6)
    ax.scatter(twoDf.petalLength, twoDf.petalWidth, marker='*', color='g', alpha=0.6)

def plotStartPoints(startpoints, ax):
    ax.scatter(startpoints[0][0], startpoints[0][1], marker='o', color='k')
    ax.scatter(startpoints[1][0], startpoints[1][1], marker='+', color='k')
    ax.scatter(startpoints[2][0], startpoints[2][1], marker='*', color='k')


def main():
    df = pd.read_csv('irisWithNames.csv', header=0)
    tdf = pd.read_csv('iris.csv', header=0)
    del df['sepalLength']
    del df['sepalWidth']

    fig, axes = plt.subplots(2,2);
    
    startpoints = getKInitialPoints(df, 3)

    df = categorizeBasedOnStartpoints(df, startpoints)
    plotOnAxis(axes[0][0], df)
    plotStartPoints(startpoints, axes[0][0])

    startpoints = createNewStartPoints(df)
    df = categorizeBasedOnStartpoints(df, startpoints)
    plotOnAxis(axes[0][1], df)
    plotStartPoints(startpoints, axes[0][1])
    startpoints = createNewStartPoints(df)
    df = categorizeBasedOnStartpoints(df, startpoints)
    plotOnAxis(axes[1][0], df)
    plotStartPoints(startpoints, axes[1][0])
    startpoints = createNewStartPoints(df)
    df = categorizeBasedOnStartpoints(df, startpoints)
    plotOnAxis(axes[1][1], df)
    plotStartPoints(startpoints, axes[1][1])


    fig1, axes1 = plt.subplots(1,1)
    plotOnAxis(axes[0][0], tdf)





    plt.show()


if __name__ == '__main__':
    main()
