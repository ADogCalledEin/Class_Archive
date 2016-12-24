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
    
    

def main():
    df = pd.read_csv('weather.csv', header=0)

    '''
    Generate testing data
    
    Last column is our classification!
    '''
    ####### THIS SHOULD NOT EXIST IN YOUR FINAL CODE #########

    testdf = df.copy()

    ##########################################################
    
    
    classifications = np.unique(df.classification)
    
    columns = df.columns
    
    for index, row in testdf.iterrows():
        instance = testdf.iloc[index][:-1]
        
        
        classificationDict = {}
        totalProbability = 0.0
        for classification in classifications:
            prob = 1.0
            for col in columns[:-1]:
                # Compute the probability of a attribute/value pair existing given a classification
                prob *= float(probabilityOfValue(col, instance[col], classification, df))

            # Create the last probability: how often a classification occurs given all instances
            classificationCount = len(df[df.classification == classification].index) 
            prob *= classificationCount / float(len(df.index))

            # Save this into a dictionary keyed off of the classification
            classificationDict[classification] = prob
            totalProbability += prob

        # normalize the probabilities
        for key in classificationDict:
            classificationDict[key] /= totalProbability
    
        print classificationDict
        
        
    
    
    
    
if __name__ == '__main__':
    main()
