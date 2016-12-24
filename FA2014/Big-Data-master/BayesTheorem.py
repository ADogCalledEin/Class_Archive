'''
Created on Nov 16, 2014

@author: GriffinSiadak and MiguelGuerrero
'''
from pandas import DataFrame, Series
import numpy as np
import pandas as pd
import math
import matplotlib.pyplot as plt


def probabilityOfValue(attr, val, classification, df):
    df = df[df.classification == classification]
    denom = float(len(df.index))
    numer = float(len(df[df[attr] == val].index))
    return (numer / denom)
    
    
def constructProbabilityTable(df):
    fullArray = {}
    classifications = np.unique(df.classification)
    for attr in df.columns:
        attrArray = {}
        if attr != 'classification':
            for val in np.unique(df[attr]):
                classificationArray = {}
                for clss in classifications:
                    classificationArray[clss] = probabilityOfValue(attr, val, clss, df)
                attrArray[val] = classificationArray
        fullArray[attr] = attrArray
    return fullArray

def findProbabilities(testdf, traindf, findROCInfo, yKey):
    classifications = np.unique(traindf.classification)

    columns = traindf.columns

 
    classificationArray = constructProbabilityTable(traindf)
    
    error = 0
    quadLoss = 0
    infoLoss = 0
    yProbs = []
    for index in range(len(testdf.index)):
        instance = testdf.iloc[index][:-1]
        correctClss = testdf.iloc[index]['classification']  
        
        classificationDict = {}
        totalProbability = 0.0
        for classification in classifications:
            prob = 1.0
            for col in columns[:-1]:
                prob *= classificationArray[col][instance[col]][classification]


            classificationCount = len(traindf[traindf.classification == classification].index) 
            prob *= classificationCount / float(len(traindf.index))

            classificationDict[classification] = prob
            totalProbability += prob

        for key in classificationDict:
            classificationDict[key] /= totalProbability
        
        for key in classificationDict:
            if key == yKey:
                yProb = float(classificationDict[key])
                yProbs.append(yProb)
                
        error += countErrorRate(classificationDict, correctClss)
        quadLoss += countQuadraticLoss(classificationDict, correctClss)
        infoLoss += countInformationalLoss(classificationDict, correctClss)
    
    

    ret = {}
    ret['Error Rate'] = error
    ret['Quadratic Loss'] = quadLoss
    ret['Informational Loss'] = infoLoss
    ret['Yes Probability List'] = yProbs

    return ret

def countErrorRate(d, correctClss):
    bestProb = 0.0
    for key in d:
        if bestProb < d[key]:
            bestProb = d[key]
            bestKey = key
    if bestKey != correctClss:
        return 1
    else:
        return 0

def countQuadraticLoss(d, correctClss):
    s = 0
    if correctClss in d:
        correctProb = d[correctClss]
        s += quadLossFun(correctProb)
    return s

def countInformationalLoss(d, correctClss):
    s = 0    
    if correctClss in d:
        correctProb = d[correctClss]
        if correctProb == 0:
            return s        # DON'T DO IT (-log2(0) = INFINITY; not good maths, etc.)
        s += infoLossFun(correctProb)

    return s
             
'''This function comes from ANDREA DEAN. '''    
def quadLossFun(correct):
    notCorrect = 1-correct
    return 1 - 2*correct  + (correct*correct + notCorrect*notCorrect) 

def infoLossFun(correct):
    return -math.log(correct, 2)

