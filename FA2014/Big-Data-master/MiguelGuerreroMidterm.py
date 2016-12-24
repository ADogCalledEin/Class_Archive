'''
Created on Oct 21, 2014

@author: Miguel
'''
import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import matplotlib.pyplot as plt
import bdlibrary
from sklearn.cross_validation import train_test_split
import math

''' In this function, I am going to set the values of each column to low or high
    using the df.median function to find the median of each column's data. '''
def setNominalValues(df):
    for col in df.columns[:-1]:
        med = df[col].median()
        df[col] = np.where(df[col] <= med, 'low', 'high')
#         for val in col:
#             if val <= med:
#                 df[col][val] = 'low'
#             else:
#                 df[col][val] = 'high'
    
    return df

def findCorrectOccurrence(df, clss):
    hardDf = df[df['classification'] == clss]
    bestPorp = 0.000
    bestVal = ''
    bestCol = ''
    
    for col in df.columns[:-1]:
        values = np.unique(df[col])
        
        for val in values:
            
            den = float(df[col].value_counts()[val])
            num = float(hardDf[col].value_counts()[val] if val in hardDf[col].value_counts() else 0)
#            den = df[col].value_counts()[val]
#            num = hardDf[col].value_counts()[val] if val in hardDf[col].value_counts() else 0
            porp = num / den
            if porp > bestPorp:
                bestPorp = porp
                bestCol = col
                bestVal = val
#            data = {'Rule': [col + '' + val], 'Proportion': [porp]} 
#            print '%s %s : %d / %d' % (col, val, num, den)
        
    print '%s = %s ' % (bestCol, bestVal)
    bestRule(df, bestPorp, bestVal, bestCol, clss)

def bestRule(df, porp, val, col, clss):
    if porp != 1:
        print 'and '
        df = df[df[col] == val]
        findCorrectOccurrence(df, clss)

def main():
    df = pd.read_csv('seeds.train.csv', header = 0)
    columnsToSave = ['area', 'perimeter', 'compactness', 'length', 'width', 'coeff', 'grooveLength', 'classification']
    df = df[columnsToSave]
    df = setNominalValues(df)
    clss = 1
    while clss < 4:
        print 'RULE: If '
        print findCorrectOccurrence(df, clss)
        print 'then classification = %d' % (clss)
        print '-------------------------'
        clss += 1

main()