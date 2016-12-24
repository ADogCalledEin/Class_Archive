'''
Created on Sep 30, 2014

@author: GriffinSiadak
'''
#Change it to the length of the index

import numpy as np
from pandas import DataFrame, Series
import pandas as pd
import math

def gain(data, attr, val):
    
    return entropy(data) - ((len(data[data[attr] == val].index) / len(data.index) * entropy(data[data[attr] == val], val)))
    
def entropy(data, val):

    return ((-(attr1/total) * math.log(attr1/total, 2)) - ((attr2/total) * math.log(attr2/total, 2)))
    
def ID3(data, attr):
    print attr
    if (len(data[data['Survived'] == 1].index) == len(data.index)):#all instances in the data survived
        #create a yes node
        print 'yes'
    if (len(data[data['Survived'] == 0].index) == len(data.index)):#all instances in the data did not survive
        #create a no node
        print 'no'
    
        ID3(data, attr) #Selecting next attribute to key off of
    
    
    
def main():
    data = pd.read_csv('titanic2.csv')
    
    # These attributes appear to be irrelevant to whether or not a passenger survived
    data = data.drop('Name', 1) #We already have an identifier in 'PassengerId', and that is shorter
    data = data.drop('Ticket', 1) #No useful conclusions to make from this 
    data = data.drop('Embarked', 1) #Too general of a stat to care about
    data = data.drop('Cabin', 1) #Incomplete data
    
    dataF = data[data['Sex'] == 'female']
    dataM = data[data['Sex'] == 'male']
    ID3(dataF ,1)
    
if __name__ == '__main__':
    main()