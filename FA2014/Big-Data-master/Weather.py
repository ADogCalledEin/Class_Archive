'''
Created on Sep 17, 2014

@author: GriffinSiadak
'''
import numpy as np
from pandas import DataFrame, Series
import pandas as pd
from conda import __main__



def findErrorForClass(df, attr, clss):
    
    
    tdf = df[ Series(df['Play'] == 'yes') & Series(df[attr] == clss) ]
    fdf = df[ Series(df['Play'] == 'no') & Series(df[attr] == clss) ]
    
    tLen = len(tdf.index)
    fLen = len(fdf.index)
    
    print '%s -> yes = %d' % (clss, tLen)
    print '%s -> no = %d' % (clss, fLen)


    return {'errorCount': tLen if tLen < fLen else fLen, "Rule:" : "%s -> %s" % (clss, 'no' if tLen < fLen else "yes")}


def probabilityOfValue(attr, val , doesPlay, df):
    df = df[df['Play'] == doesPlay]
    denom = len(df.index)
    df[df[attr] == val]
    
    
    
    
def main():
    df = pd.read_csv('weather.csv', header=0)
    print df
    bestErrorCount = np.inf
    for attr in df.columns[0:-1]:
        print attr 
        ruleTato = []
        error = 0
        for clss in np.unique(df[attr]):
            errorForClass = findErrorForClass(df, attr, clss)
            error += errorForClass(df, attr, clss)
            ruleTato.append(errorForClass)
        bestErrorCount = 0
        if error < bestErrorCount:
            bestErrorCount = error
            bestAttr = attr
            bestRuleTato = ruleTato
            
    print "Make rule on %s" % bestAttr
    print "Rules: %s" % bestRuleTato
            
            
            
    print df[df['Play'] == 'yes']
    print float ((2. / 9.) * (1. / 3.) * (1. / 3.) * (1. / 3.) * (5. / 14.))
    
    pYesPlay = ((3. / 5.) * (1. / 5.) * (4. / 5.) * (3. / 5.) * (5. / 14.))
    pNoPlay = ((2. / 9.) * (1. / 3.) * (1. / 3.) * (1. / 3.) * (9. / 14.))

    print 'Probability yes: %f' % (pYesPlay / (pYesPlay + pNoPlay))
    print 'Probability no: %f' % (pNoPlay / (pYesPlay + pNoPlay))

    
if __name__ == '__main__':
    main()
    
    
    
