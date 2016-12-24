'''
Created on Nov 16, 2014

@author: GriffinSiadak and MiguelGuerrero
'''
from pandas import DataFrame, Series
import numpy as np
import pandas as pd
import BayesTheorem as bayes
import matplotlib.pyplot as plt



def crossValidation(df, yKey, nKey, k, bFindROCInfo):    
    t = 0
    nFoldLength = len(df.index)/k
    rem = len(df.index)%k
    rFoldLength = nFoldLength + 1  
    foldLength = nFoldLength
    if rem > 0:
        foldLength = rFoldLength                                 
    front = 0
    back = front + foldLength
    error = 0.0
    quadLoss = 0.0
    infoLoss = 0.0
    yProbs = []

    while back < len(df.index) + 1:
        testdf, traindf = df.copy(), df.copy()
        testdf = testdf[front:back]
        traindf = traindf.drop(traindf.index[front:back])         

        if rem <= 1:
            foldLength = nFoldLength
        
        ret = bayes.findProbabilities(testdf, traindf, bFindROCInfo, yKey)
        for key in ret:
            if key == 'Error Rate':
                error += ret[key]
            if key == 'Quadratic Loss':
                quadLoss += ret[key]
            if key == 'Informational Loss':
                infoLoss += ret[key]
            if bFindROCInfo == True:
                if key == 'Yes Probability List':
                    yProbs.extend(ret[key])
                    

                
        front = back
        back = front + foldLength
        rem -= 1
        t += 1
    
    if bFindROCInfo == True:
        df['probability'] = 0.0
        for index in range(len(df.index)):
            prob = yProbs.pop(0)
            df.ix[index, 'probability'] = prob
        compare = df.sort(['probability'], ascending = False)
        findROCCurveInfo(compare, yKey, nKey)
        
    errorRate = error/len(df.index)
    print 'Error Rate: ', errorRate
    print 'Quadratic Loss: ', quadLoss 
    print 'Informational Loss: ', infoLoss
    successRate = 1 - errorRate
    print 'Success Rate: ', successRate

        
def findROCCurveInfo(df, yKey, nKey):
    tpr = []
    fpr = []
    yTotal = 0.0
    nTotal = 0.0
    
    for correctClss in df['classification']:
        if correctClss == yKey:
            yTotal += 1.0
        if correctClss == nKey:
            nTotal += 1.0
    
    yCount = 0.0
    nCount = 0.0
    
    y = 0.0
    n = 0.0
    for index, row in df.iterrows():
        correctClss = row['classification']
        if correctClss == yKey:
            yCount += 1.0
            y = 100 * (yCount / yTotal)
        if correctClss == nKey:
            nCount += 1.0
            n = 100 * (nCount / nTotal)
        fpr.append(n)
        tpr.append(y)
    
    plotROCCurve(fpr, tpr)

def plotROCCurve(fpr, tpr):
    plt.figure()
    plt.xlabel('False %', fontsize = 14)
    plt.ylabel('True %', fontsize = 14)
    plt.title("Mushroom ROC Curve", fontsize = 14)
    plt.plot(fpr, tpr)
    
    plt.show()

def main():
    mushroomDF = pd.read_csv('mushroom.csv', header = 0)
    cols = mushroomDF.columns.tolist()
    cols = cols[1:] + cols[:1]
    cols = cols[13:] 
    mushroomDF = mushroomDF[cols]
    nurseryDF = pd.read_csv('nursery.csv', header = 0)
    nurseryDF = nurseryDF.drop(nurseryDF.index[[12960]])
    
    print 'Exit out of the plot to see the nursery data'
    print 'MUSHROOM DATA:'
    crossValidation(mushroomDF, 'e', 'p', 10, True)
    print '------------------------------'
    print 'NURSERY DATA:'
    crossValidation(nurseryDF, None, None, 10, False)
        

    
main()