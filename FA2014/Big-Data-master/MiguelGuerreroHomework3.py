'''
Created on Sep 30, 2014

@author: Miguel
'''
import pandas as pd
import numpy as np
from pandas import DataFrame
import math

def cleanData(df):
    del df['Name']              # Just deleting columns that probably will not effect these
    del df['PassengerId']       # folks' chances of survival, etc. 
    del df['Ticket']
    del df['Cabin']
    del df['Fare']
    del df['Age']
    del df['Embarked']
    del df['Parch']
    del df['SibSp']


# entropy and gain functions were brought to you in part by:
# http://www.onlamp.com/pub/a/python/2006/02/09/ai_decision_trees.html?page=4
def entropy(df, attr):
    # Making a list  of integers that are the frequency of each value in attr. 
    freq = {}
    entropy = 0.0
     
    # Finding the frequency of all values in attr.
    for i in df:
        if freq.has_key(i[attr]):
            freq[i[attr]] += 1.0
        else:
            freq[i[attr]] = 1.0
             
    # Calculating the entropy of attr.
    for f in freq.values():
        entropy += (-f/len(df)) * math.log(f/len(df), 2) 
     
def gain(df, attr, dAttr):
    # Making a list of integers that are the frequency of each value in attr.
    freq = {}
    sEntropy = 0.0
    
    # Finding the frequency of all values in attr.
    for i in df:
        if freq.has_key(i[attr]):
            freq[i[attr]] += 1.0
        else:
            freq[i[attr]] = 1.0
            
    # Calculating the sum of the entropies weighted by the probabilities.
    for val in freq.keys():
        prob        = freq[val] / sum(freq.values())
        data_subset     = [record for record in df if record[attr] == val]
        sEntropy += prob * sEntropy(data_subset, dAttr)

    # Returns the information gain.
    return (entropy(df, dAttr) - sEntropy)

# This was supposed to be a recursive function that made a decision tree, 
# but I don't know how to do that.
def ID3(df, attr):
    return

def main():
    df = pd.read_csv('titanic2.csv', header = 0)
    cleanData(df)
    print df
    print gain(df, 'Survived', 'Sex')
    
main()