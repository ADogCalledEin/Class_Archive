'''
Created on Sep 29, 2014

@author: GriffinSiadak
'''
import pandas as pd
from pandas import DataFrame
import numpy as np

def findCorrectOccurrence(df):     
    surviveDf = df[df['Survive'] == '1']
    for col in df.columns[:-1]:
        values = np.unique(df[col])
         
        for val in values:
            den = df[col].value_counts()[val]
            num = surviveDf[col].value_counts()[val] if val in surviveDf[col].value_counts() else 0
            print '%s: %d / %d' % (val, num, den)


def main():
    df = pd.read_csv('titanic2.csv', header=0)
    findCorrectOccurrence(df)
    df = df[df['Survived'] == '1']
    print '---------------------'
    findCorrectOccurrence(df)

if __name__ == '__main__':
    main()        
        
        