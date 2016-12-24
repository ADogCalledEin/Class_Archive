'''
Created on Oct 21, 2014

@author: GriffinSiadak
'''
import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import matplotlib.pyplot as plt
# import bdlibrary
# from sklearn.cross_validation import train_test_split
# import math

# Attempting to make the data easier to work with
# def dataFix(df):
#     for row in df:
# #         for col in row:
# #             np.floor(col)
# #             
# #     return df
# 
# #  Comparing the compactness against the type of kernel by adapting an old method of covering rules
# def findCorrectOccurance(df):     
#     classDf = df[df['width'] > 3]
#     for row in df.rows[:-1]:
#         values = np.unique(df[row])
#             
#         for val in values:
#             den = df[row].value_counts()[val]
#             num = classDf[row].value_counts()[val] if val in classDf[row].value_counts() else 0
#             print '%s: %d / %d' % (val, num, den)
# 
# 
# # Main method
# def main():
#     df = pd.read_csv('seeds.train.csv', header = 0)
#     oneDf= df[df['classification'] == 1]
#     twoDf= df[df['classification'] == 2]
#     threeDf= df[df['classification'] == 3]
#     findCorrectOccurance(oneDf)
# #     fig = plt.figure()
# # 
# #     plt.scatter(oneDf.perimeter, oneDf.compactness, marker = '+', color = 'RED')
# #     plt.scatter(twoDf.perimeter, twoDf.compactness, marker = '+', color = 'BLUE')
# #     plt.scatter(threeDf.perimeter, threeDf.compactness, marker = '+', color = 'GREEN')
# #     
# #     plt.show()
# #     print oneDf, twoDf, threeDf
#     
# if __name__ == '__main__':
#     
# for col in threeDf.columns[1:-1]:
#     print threeDf[col].min()
#     print threeDf[col].max()
#     print '---'

# Finding the correct classification numnbers
def correctCounts(df):
    values = df[df.columns[8]]
    val1 = 0
    val2 = 0
    val3 = 0
    for val in values:
        if val == 1:
            val1 += 1
        if val == 2:
            val2 += 1
        if val == 3:
            val3 += 1

    return val1, val2, val3
    

# print df.median(axis = 0)   
# Changing values to nominals (high and low)    
def nominalSetter(df):
    for col in df.columns[0:-1]: 
        med = df[col].median()
        df[col] = np.where(df[col] <= med, 'low', 'high')
    return df

# Finding the best attribute to sort off of
def findCorrectOccurance(df, clss):
    classDf = df[df['classification'] == clss]
    bestGoodAttr = 0.0
    bestVal = ''
    bestCol = ''
    for col in df.columns[:-1]:
        values = np.unique(df[col])
        
        for val in values:
            den = float(df[col].value_counts()[val])
            num = float(classDf[col].value_counts()[val] if val in classDf[col].value_counts() else 0)
            goodAttr = num / den
            if goodAttr > bestGoodAttr:
                bestGoodAttr = goodAttr
                bestVal = val
                bestCol = col
    print '%s = %s' % (bestCol, bestVal)
    bestRuleTato(df, bestGoodAttr, bestVal, bestCol, clss)

# calling back to findCorrectOccurance to decide the best rule, and then it gets called again by findCorrectOccurance
def bestRuleTato(df, goodAttr, val, col, clss):  # Plus a throwback to silly part of class
    if goodAttr != 1:
        print 'and' 
        df = df[df[col] == val]
        findCorrectOccurance(df, clss)
        
        
        
def accuracyCheck(df):
    
    for index, row in df.iterrows():
        trueClass1 = (row['coeff'] == 'low' and row['grooveLength'] == 'low' and row['length'] == 'high')
        trueClass2 = (row['area'] == 'high' and row['coeff'] == 'high' and row['width'] == 'high' and row['compactness'] == 'low')
        trueClass3 = (row['area'] == 'low' and row['grooveLength'] == 'high' and row['perimeter'] == 'low')

        df.set_value(index, 'ruleClass', np.where(trueClass1, 1, 0))
        df.set_value(index, 'ruleClass', np.where(trueClass2, 2, 0))
        df.set_value(index, 'ruleClass', np.where(trueClass3, 3, 0))
        
    bot = 0.0
    top = 0.0
    for index, row in df.iterrows():
        if row['ruleClass'] == row['classification']:
            top += 1
        bot += 1
    
    return top / bot
#     class1 = 0
#     class2 = 0
#     class3 = 0
#     for row in df.iterrows():
#         if df[df['coeff']] == 'low' and df[df['grooveLength']] == 'low' and row.df[df['length']] == 'high':
#             class1 += 1
#     print class1
#     for row in df.iterrows():
#         if hasattr(row, 'low'):
#             class1 += 1
#     print class1
#             if hasattr(row, 'low'):
#                 if hasattr(row, 'high'):
                     
# Main program
def main():
    df = pd.read_csv('seeds.train.csv', header=0)
    df2 = pd.read_csv('seeds.test.csv', header=0) 
    savedColumns = ['area', 'perimeter', 'compactness', 'length', 'width', 'coeff', 'grooveLength', 'classification']  
    df = df[savedColumns]
    df2 = df2[savedColumns]
#     print correctCounts(df)
    df = nominalSetter(df)
    df2 = nominalSetter(df2)
    clss = 1
    while clss < 4: 
        print 'If'
        print findCorrectOccurance(df, clss)
        print 'then classification =' 
        print clss
        print '-----'
        clss += 1 
    print accuracyCheck(df)
    clss = 1
    while clss < 4: 
        print 'If'
        print findCorrectOccurance(df2, clss)
        print 'then classification =' 
        print clss
        print '-----'
        clss += 1 
    print accuracyCheck(df2)
    
    accuracy = Series(accuracyCheck(df), index = ['Training'])
    acc2 = Series(accuracyCheck(df2), index = ['Test'])
    accuracy = accuracy.append(acc2, verify_integrity = False)
    
    fig = plt.figure()
    
    ax = fig.add_subplot(1,1,1)
    plt.title('Accuracy of Covering Rules')
    plt.ylabel('Accuracy out of 1')
    accuracy.plot(kind='bar', ax=ax, color= 'k', alpha=0.7)
    
    
    plt.show()
    

# Found out the hard way not to forget this statement
if __name__ == '__main__':
    main()





