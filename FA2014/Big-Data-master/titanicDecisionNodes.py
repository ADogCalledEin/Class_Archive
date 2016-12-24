import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import math

class Node:
    values = {}
    def __init__(self, attr):
        self.attr = attr
        self.values = {}

    def addNode(self, value, node):
        self.values[value] = node

    def __str__(self):
        return self.attr

    def getChildNode(self, value):
        if value in self.values:
            return self.values[value]
        else:
            return None


class Leaf(Node):
    def __init__(self, val, survived, died):
        self.survived = survived
        self.died = died
        self.val = val

    def __str__(self):
        return '%d survived, %d died' % (self.survived, self.died)
    
    def getCategory(self):
        return 1 if self.survived >= self.died else 0



def printTree(node, depth=0):
    for i in range(depth):
        print ' ',
    print node

    for val in node.values:
        for i in range(depth):
            print ' ',
        print val
        printTree(node.values[val], depth+1)
        
    


def info(vals):
    tot = 0
    de = sum(vals)
    if de == 0:
        return 0
    for val in vals:
        val = float(val) / float(de)
        if val != 0.:
            tot += -val * math.log(val, 2)
    return tot

def getColumnWithHighGain(df, depth, val=None):
    survivedValCount = df.Survived.value_counts()
    totalN = survivedValCount[0] if 0 in survivedValCount else 0
    totalY = survivedValCount[1] if 1 in survivedValCount else 0

    totalInfo = info([totalY, totalN])
    nDf = df[df.Survived == 0]
    yDf = df[df.Survived == 1]

    if totalN == 0 or totalY == 0 or len(df.columns) < 2:
        return Leaf(val, totalY, totalN)

    totalLen = len(df.index)
    highestGainColVal = -1

    for col in df.columns[1:]:
        values = np.unique(df[col])
        lVal = []
        infog = 0
        for val in values:
            valDf = df[df[col] == val]
            valC = valDf.Survived.value_counts()
            survC = valC[1] if 1 in valC else 0
            notSurvC = valC[0] if 0 in valC else 0
            tinfo = (info([survC, notSurvC]) * (((float)(survC + notSurvC))/(totalLen)))
            infog += tinfo
        # print col, infog
        infog = totalInfo - infog
        if infog > highestGainColVal:
            highestGainColVal = infog
            highestGainColName = col



    node = Node(highestGainColName)
    '''print node
    print node.values'''
    depth += 1

    for val in np.unique(df[highestGainColName]):
        valDf = df[df[highestGainColName] == val]
        valDf = valDf.drop(highestGainColName, 1)
        node.addNode(val, getColumnWithHighGain(valDf, depth+1, val))

    return node


def categorizeRow(row, node):
    if isinstance(node, Leaf):
        return node.getCategory()
    
    childNode = node.getChildNode(row[node.attr])

    if childNode == None:
        return 0
    else:
        return categorizeRow(row, childNode)


    



def main():
    # Import the csv file
    weathertest = False
    if weathertest:
        df = pd.read_csv('weather.csv', header=0)
    else:
        df = pd.read_csv('titanic2.csv', header=0, index_col='PassengerId')
        df = df.drop('Cabin', 1)
        df = df.drop('Name', 1)
        # df = df.drop('Parch', 1)
        df = df.drop('Ticket', 1)
        df = df.drop('Fare', 1)
        df = df.drop('Embarked', 1)
        df = df.drop('Age', 1)
        # df.loc[ (df.Embarked.isnull()), 'Embarked'] = 'C'
    size = len(df.index)
    
    
    
    for split in np.arange(.5,.1,.1):
        
    
        ind = int(math.floor(size*split))
    
    
    
    
    
        testdf = df[ind:]
        df = df[:597]
    
        node = getColumnWithHighGain(df, 0)
    
        count = 0
        for index, row in testdf.iterrows():
            if categorizeRow(row, node) == row['Survived']:
                count += 1
    
        print float(count)/len(testdf.index)




    #printTree(node)



if __name__ == "__main__":
    main()

