'''
Created on Sep 17, 2014

@author: ntiller
'''

from pandas import DataFrame, Series
import numpy as np
import pandas as pd

def findErrorForClass(df, attr, clss):
    
    yDataFrame = df[ Series(df['Play'] == 'yes') & Series(df[attr] == clss) ]
    nDataFrame = df[ Series(df['Play'] == 'no') & Series(df[attr] == clss) ]
    
    yLen = len(yDataFrame.index)
    nLen = len(nDataFrame.index)
    
#     print '%s -> yes = %d' % (clss, yLen) 
#     print '%s -> no = %d' % (clss, nLen) 
    
    return {"ErrorCount": yLen if yLen < nLen else nLen, "Rule: " : "%s -> %s" % (clss, "no" if yLen < nLen else "yes")}


def probabilityOfValue(attr, val, doesPlay, df):
    df = df[df['Play'] == doesPlay]
    denom = float(len(df.index))
    numer = float(len(df[df[attr] == val].index))
    return (numer / denom)
    
    

def main():
    df = pd.read_csv('weather.csv', header=0)
    print df
    bestErrorCount = np.inf
    for attr in df.columns[0:-1]:
        print attr
        error = 0
        ruleTato = []
        for clss in np.unique(df[attr]):
            errorForClass = findErrorForClass(df, attr, clss)
            error += errorForClass["ErrorCount"]
            ruleTato.append(errorForClass)
        if error < bestErrorCount:
            bestErrorCount = error
            bestAttr = attr
            bestRuleTato = ruleTato
            
    print "Make rule on %s" % bestAttr
    print "Rules: %s" % bestRuleTato
    
    
#     print df[df['Play'] == 'no']
    
    instance = ['Sunny', 'cool', 'high', True]
    
    
    pNoPlay = 1
    pYesPlay = 1
    for index in range(4):
        print '%s %s' % (df.columns[index], instance[index])
        pYesPlay *= probabilityOfValue(df.columns[index], instance[index], 'yes', df)
        pNoPlay *= probabilityOfValue(df.columns[index], instance[index], 'no', df)
    
    totalLen = float(len(df.index))
    
    pTotalYes = len(df[df['Play'] == 'yes'].index) / totalLen
    pTotalNo = len(df[df['Play'] == 'no'].index) / totalLen
    
    print '%f %f' % (pTotalYes, pTotalNo)
    pYesPlay *= pTotalYes
    pNoPlay *= pTotalNo
    
    tYesPlay = pYesPlay
    tNoPlay = pNoPlay
    
    pYesPlay /= (tYesPlay + tNoPlay)
    pNoPlay /= (tYesPlay + tNoPlay)
    
    
    print 'Yes: %f, No: %f' % (pYesPlay, pNoPlay)
    
    
#     pNoPlay = (3./5.) * (1./5.) * (4./5.) * (3./5.) * (5./14.)
#     pYesPlay = (2./9.) * (1./3.) * (1./3.) * (1./3.) * (9./14.)
#     
#     print "Probability yes: %f" % (pYesPlay / (pYesPlay + pNoPlay))
#     print "Probability no: %f" % (pNoPlay / (pYesPlay + pNoPlay))
    
    
if __name__ == '__main__':
    main()
