#Thank you Miguel and Andrea for helping me understand why I shouldn't choose the blue pill
'''
Created on Sep 29, 2014

@author: GriffinSiadak
'''
import pandas as pd
import numpy as np
from pandas import DataFrame
import math

def cleanData(df):
    del df['Name']              # None of these parameters affected survivability. 
    del df['PassengerId']        
    del df['Ticket']
    del df['Cabin']
    del df['Fare']
    del df['Age']
    del df['Embarked']

#Entropy, sooooo much entropy (the actual equation is called formula, but for clarity's sake we used a separate definition
def entropy(df, depth):
    surviveDf = df[df['Survived'] == 1]
    totalSurvive = np.sum(df['Survived']) * 1.0
    totalSurviveNo = df.count()['Survived'] * 1.0 - totalSurvive
    bestGain = 0
    totalInfo = formula(totalSurvive, totalSurviveNo, totalSurvive + totalSurviveNo)
    for col in df.columns[1:]:
        values = np.unique(df[col])
        average = 0.
        for val in values:
            den = (df[col].value_counts()[val]) * 1.0
            surviveYes = surviveDf[col].value_counts()[val]* 1.0 if val in surviveDf[col].value_counts() else 0.0 #Did they survive?
            surviveNo = (den - surviveYes) * 1.0
            info = formula(surviveYes, surviveNo, den) 
            average += info*(den/(totalSurvive+totalSurviveNo))    
        gain = totalInfo - average #Info gain
        if gain > bestGain:
            bestGain = gain
            bestAttr = col
    if bestGain != 0: #Now on to printing the decision tree itself
        for i in range(depth):
            print '\t',
        print bestAttr
        for val in np.unique(df[bestAttr]):
            for i in range(depth+1):
                print '\t', #Lovely printing
            print val
            entropy(df[df[bestAttr] == val], depth+1)
    else:
        for i in range(depth):
            print '\t',
        print 'Survived: %d ; Not Survived %d' % (totalSurvive, totalSurviveNo)
        return 0 
#It all makes sense in my head, and is probably redundant in some areas

# Finds the entropy of the data based on how many survived versus how many did not survive.
def formula(sYes, sNo, den):
    info = -(sYes/den) * np.log2(sYes/den)  - (sNo/den) * np.log2(sNo/den) 
    if (info > 0) & (info <= 1):
        return info 
    else:
        return 0
     
def main():
    df = pd.read_csv('titanic2.csv', header = 0)
    cleanData(df)
    dTree = ""
    entropy(df,0)
    
main()