'''
Created on Sep 17, 2014

@author: ntiller
'''

from pandas import DataFrame, Series
import numpy as np
import pandas as pd
import math



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


def findProbabilities(testdf, traindf):
    classifications = np.unique(traindf.classification)

    columns = traindf.columns

    # HERE IS THE IMPORTANT LINE. THIS FINDS ALL PROBABILITIES AND SAVES THEM
    classificationArray = constructProbabilityTable(traindf)
    
    for index in range(len(testdf.index)):
        instance = testdf.iloc[index][:-1]
        
        
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
    
    

def main():
    df = pd.read_csv('mushroom.csv', header=0)


    # Here is simple code to move the first column to the last spot. 
    cols = df.columns.tolist()
    print cols
    cols = cols[1:] + cols[:1]
    print cols
    df = df[cols]
    print df
    '''
    Generate testing data
    
    Last column is our classification!
    '''
    ####### THIS SHOULD NOT EXIST IN YOUR FINAL CODE #########

    testdf = df.copy()

    ##########################################################
    
        
    # Example
    findProbabilities(testdf, df)
        
    
    
    
    
if __name__ == '__main__':
    main()
