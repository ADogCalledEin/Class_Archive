'''
Created on Sep 26, 2014

@author: GriffinSiadak
'''
import pandas as pd
from pandas import DataFrame, Series
import numpy as np

def findCorrectOccurrence(df):     
    hardDf = df[df['Recommended Lenses'] == 'hard']
    for col in df.columns[:-1]:
        values = np.unique(df[col])
        
        for val in values:
            den = df[col].value_counts()[val]
            num = hardDf[col].value_counts()[val] if val in hardDf[col].value_counts() else 0
            print '%s: %d / %d' % (val, num, den)


def main():
    df = pd.read_csv('contactLenses.csv', header=0)
    findCorrectOccurrence(df)
    df = df[df['Astigmatism'] == 'yes']
    print '---------------------'
    findCorrectOccurrence(df)

if __name__ == '__main__':
    main()        
        
        
    
    
    

