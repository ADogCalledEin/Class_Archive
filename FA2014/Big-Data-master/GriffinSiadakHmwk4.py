'''
Created on Nov 9, 2014

@author: GriffinSiadak with a large amount of assistance from Miguel Guerrero
'''
import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import math
import matplotlib.pyplot as plt
from tables.hdf5extension import correct_byteorder



def quadLoss(correct):
    notCorrect = 1 - correct
    return 1 - 2 * correct + (correct * correct + notCorrect * notCorrect)

def infoLoss(correct):
    return -math.log(correct, 2)
    
def countInfoLoss(d, correctClss):
    s = 0
    if correctClss in d:
        correctProb = d[correctClss]
        if correctProb == 0:
            return s
        s += infoLoss(correctProb)
    return s    
    
def countQuadloss(d, correctClss):
    s = 0
    if correctClss in d:
        correctProb = d[correctClss]
        s += quadLoss(correctProb)
    return s
    
    
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

# def keyWithMaxVal(d):
#     v=list(d.values())
#     k=list(d.keys())
#     return k[v.index(max(v))]
 
def findProbabilities(testdf, traindf):
    quadloss = 0.0
    infoloss = 0.0
    error = 0.0
    
    
    classifications = np.unique(traindf.classification)

    columns = traindf.columns

    # HERE IS THE IMPORTANT LINE. THIS FINDS ALL PROBABILITIES AND SAVES THEM
    classificationArray = constructProbabilityTable(traindf)
    
    for index in range(len(testdf.index)):
        instance = testdf.iloc[index][:-1]
        correctClss = testdf.iloc[index]['classification']
        
        classificationDict = {}
        totalProbability = 0.0
        for classification in classifications:
            prob = 1.0
            for col in columns[:-1]:
                # Compute the probability of a attribute/value pair existing given a classification
                # prob *= float(probabilityOfValue(col, instance[col], classification, traindf))
                prob *= classificationArray[col][instance[col]][classification]


            # Create the last probability: how often a classification occurs given all instances
            classificationCount = len(traindf[traindf.classification == classification].index) 
            prob *= classificationCount / float(len(traindf.index))

            # Save this into a dictionary keyed off of the classification
            classificationDict[classification] = prob
            totalProbability += prob

        # normalize the probabilities
        for key in classificationDict:
            classificationDict[key] /= totalProbability
#         print classificationDict
        error += countErrorRate(classificationDict, correctClss)
        quadloss += countQuadloss(classificationDict, correctClss)
        infoloss += countInfoLoss(classificationDict, correctClss)
        
            
       
    retur = {}
    retur['Error Rate'] = error
    retur['Quad Loss'] = quadloss
    retur['Info Loss'] = infoloss
    return retur

def shroomsFindProbabilities(testdf, traindf):
    quadloss = 0.0
    infoloss = 0.0
    error = 0.0
    classList = []
    
    classifications = np.unique(traindf.classification)

    columns = traindf.columns

    # HERE IS THE IMPORTANT LINE. THIS FINDS ALL PROBABILITIES AND SAVES THEM
    classificationArray = constructProbabilityTable(traindf)
    
    for index in range(len(testdf.index)):
        
        instance = testdf.iloc[index][:-1]
        correctClss = testdf.iloc[index]['classification']
        
        classificationDict = {}
        totalProbability = 0.0
        for classification in classifications:
            prob = 1.0
            for col in columns[:-1]:
                # Compute the probability of a attribute/value pair existing given a classification
                # prob *= float(probabilityOfValue(col, instance[col], classification, traindf))
                prob *= classificationArray[col][instance[col]][classification]


            # Create the last probability: how often a classification occurs given all instances
            classificationCount = len(traindf[traindf.classification == classification].index) 
            prob *= classificationCount / float(len(traindf.index))

            # Save this into a dictionary keyed off of the classification
            classificationDict[classification] = prob
            totalProbability += prob
            
        # normalize the probabilities
        for key in classificationDict:
            classificationDict[key] /= totalProbability
            
        for key in classificationDict:
            if key == 'e':
                classList.append(float(classificationDict[key]))  
          
        error += countErrorRate(classificationDict, correctClss)
        quadloss += countQuadloss(classificationDict, correctClss)
        infoloss += countInfoLoss(classificationDict, correctClss)        
        
        
        
    retur = {}
    retur['Error Rate'] = error
    retur['Quad Loss'] = quadloss
    retur['Info Loss'] = infoloss
    return retur, classList

def crossValidation(df, k):
    t = 1
    normalFold = len(df.index) / k
    remainder = len(df.index) % k
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
        
        returned = findProbabilities(testdf, traindf)
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
        
    errorRate = error / len(df.index)
    print 'Error Rate: ', errorRate
    print 'Quadratic Loss: ', quadloss
    print 'Informational Loss: ', infoloss
    successRate = 1 - errorRate
    print 'Success Rate: ', successRate

def shroomsCrossValidation(df, k):
    t = 1
    normalFold = len(df.index) / k
    remainder = len(df.index) % k
    remainderFold = normalFold + 1
    fold = normalFold
    if remainder > 0:
        fold = remainderFold
    front = 0
    back = front + fold
    error = 0.0
    quadloss = 0.0
    infoloss = 0.0
    edibleProbList = []
    while back < len(df.index) + 1:
        print t, ': ', back, 'Fold Size: ', fold
        testdf, traindf = df.copy(), df.copy()
        testdf = testdf[front:back]
        traindf = traindf.drop(traindf.index[front:back])
        
        if remainder <= 1:
            fold = normalFold
        
        returned, classList = shroomsFindProbabilities(testdf, traindf)
        edibleProbList.extend(classList)
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
        
        
    for index in range(len(df.index)):
        prob = edibleProbList.pop(0)
        df.ix[index, 'probability'] = prob
    compare = df.sort(['probability'], ascending = False)    
    
    edibleProbList.sort(cmp=None, key=None, reverse=False)
    df['probability'] = edibleProbList 
    errorRate = error / len(df.index)
    print 'Error Rate: ', errorRate
    print 'Quadratic Loss: ', quadloss
    print 'Informational Loss: ', infoloss
    successRate = 1 - errorRate
    print 'Success Rate: ', successRate
    print df.probability
#     correct = 0.0
#     wrong = 0.0
#        
#     trueRate = [0.0]
#     falseRate = [0.0]
#     
#     tRate = 0.0
#     fRate = 0.0
#     
#     totalPos = 0.0
#     totalNeg = 0.0
#        
    for clss in df['classification']:
        if clss == 'e':
            totalPos += 1
        else:
            totalNeg += 1
#        
# #     print totalPos, totalNeg
#      
#     for index, row in df.iterrows():
#         if row['probability'] >= 0.5 and row['classification'] == 'e':
#             correct += 1      
#         elif row['probability'] < 0.5 and row['classification'] == 'e':
#             wrong += 1
#         elif row['probability'] >= 0.5 and row['classification']  == 'p':
#             wrong += 1
#         elif row['probability'] < 0.5 and row['classification']  == 'p':
#             correct += 1
#         TPR = 0.0
#         FPR = 0.0    
#             
#         TPR = correct / totalPos
#         FPR = wrong / totalNeg
#         
#         tRate += TPR  
#         fRate += FPR 
#         
#         trueRate.append(tRate)
#         falseRate.append(fRate)
    print trueRate, falseRate
    plt.plot(falseRate, trueRate)
    plt.xlabel('False %', fontsize = 14)
    plt.ylabel('True %', fontsize = 14)
    plt.title('ROC Curve', fontsize = 14)
     
    plt.show()


def findROC
 
def main():
    shroomsDF = pd.read_csv('mushroom.csv', header=0)
    shroomsDF['probability'] = 0
    cols = shroomsDF.columns.tolist()
    cols = cols[1:] + cols[:1]
    cols = cols[13:]
    shroomsDF = shroomsDF[cols]
    babiesDF = pd.read_csv('nursery.csv', header=0)
    babiesDF = babiesDF.drop(babiesDF.index[[12960]])
    
    print 'Shrooms Data:'
    shroomsCrossValidation(shroomsDF, 10) 
#     print '##################'
#     print 'Nursery Data:'
#     crossValidation(babiesDF, 10)
    
if __name__ == '__main__':
    main() 
