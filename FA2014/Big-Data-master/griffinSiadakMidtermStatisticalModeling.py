'''
Created on Oct 23, 2014

@author: GriffinSiadak
'''
import numpy as np
import pandas as pd
from pandas import Series, DataFrame
import matplotlib.pyplot as plt
# from nltk.metrics.association import TOTAL
# from pickle import INST


# Binary value setter
def binarySetter(df):
    for col in df.columns[0:-1]: 
        med = df[col].mean()
        df[col] = np.where(df[col] <= med, 0, 1)
    return df

# Finding the error counts
def findErrorForClass(df, attr, clss):
    
    Data1Frame = df[ Series(df['classification'] == 1) & Series(df[attr] == clss) ]
    Data2Frame = df[ Series(df['classification'] == 2) & Series(df[attr] == clss) ]
    Data3Frame = df[ Series(df['classification'] == 3) & Series(df[attr] == clss) ]
    
    Len1 = len(Data1Frame.index)
    Len2 = len(Data2Frame.index)
    Len3 = len(Data3Frame.index)

    
    return {"ErrorCount": Len1 if (Len1 < Len2 and Len1 < Len3) else Len2 if (Len2 < Len1 and Len2 < Len3) else Len3 
            , "Rule: " : "%s -> %s" % (clss, "Classification = 1" if Len1 < Len2 and Len1 < Len3 else "Classification = 2" if 
                                       Len2 < Len1 and Len2 < Len3 else "Classification = 3" if Len3 < Len1 and Len3 < Len2
                                        else "null")}

# Probability of a value occuring
def probabilityOfValue(attr, val, classification, df):
    df = df[df['classification'] == classification]
    denom = float(len(df.index))
    numer = float(len(df[df[attr] == val].index))
    return (numer / denom)

def checkingAccuracy(df, acc):
    bot = float(len(df.index))
    return acc / bot
def correctCounts(df):
    values = df[df.columns[7]]
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
    total = float(len(df.index))
    pOne = val1 / total
    pTwo = val2 / total
    pThree = val3 / total
    
    return pOne, pTwo, pThree


def findProbabilityOfClass(df):
    acc = 0.0
    clss = 0
    for index, row in df.iterrows():
        df.set_value(index, 'someClass', row['classification'])
    
    for area in range(2):
        for perimeter in range(2):
            for compactness in range(2):
                for length in range(2):
                    for width in range(2):
                        for coeff in range(2):
                            for grooveLength in range(2):
                                pClass1, pClass2, pClass3 = 1, 1, 1 
                                inst = [area, perimeter, compactness, length, width, coeff, grooveLength]
                                for index in range(7):

                                    pClass1 *= probabilityOfValue(df.columns[index], inst[index], 1, df)
                                    pClass2 *= probabilityOfValue(df.columns[index], inst[index], 2, df)
                                    pClass3 *= probabilityOfValue(df.columns[index], inst[index], 3, df)

                                totalLen = float(len(df.index))
    
                                pTotalClass1 = len(df[df['classification'] == 1].index) / totalLen
                                pTotalClass2 = len(df[df['classification'] == 2].index) / totalLen
                                pTotalClass3 = len(df[df['classification'] == 3].index) / totalLen


                                pClass1 *= pTotalClass1
                                pClass2 *= pTotalClass2
                                pClass3 *= pTotalClass3
        
                                tClass1 = pClass1
                                tClass2 = pClass2
                                tClass3 = pClass3
                                
                                sum = tClass1 + tClass2 + tClass3
                                pClass1 /= sum
                                pClass2 /= sum
                                pClass3 /= sum
                            
                                if pClass1 > pClass2 and pClass1 > pClass3:
                                    clss = 1
                                if pClass2 > pClass1 and pClass2 > pClass3:
                                    clss = 2
                                if pClass3 > pClass1 and pClass3 > pClass2:
                                    clss = 3
                                
                                for index, row in df.iterrows():
                                    troof = (row['area'] == area and row['perimeter'] == perimeter and row['compactness'] == compactness
                                         and row['length'] == length and row['width'] == width and row['coeff'] == coeff 
                                         and row['grooveLength'] == grooveLength)
                                    df.set_value(index, 'someClass', np.where(troof, clss, 0))
        
#                             print 'Classification 1: %f, Classification 2: %f, Classification 3: %f' % (pClass1, pClass2, pClass3)
#     for area in range(2):
#         for perimeter in range(2):
#                 for compactness in range(2):
#                         for length in range(2):
#                                 for width in range(2):
#                                         for coeff in range(2):
#                                                 for grooveLength in range(2):
#                                                     inst = [area, perimeter, compactness, length, width, coeff, grooveLength]
#                                                     
                                                    
#     valueToAppend1 = pClass1
#                                                     valueToAppend2 = pClass2
#                                                     valueToAppend3 = pClass3
#                                                     if sClass1.index() == 0:
#                                                         sClass1 = valueToAppend1
#                                                     else:
#                                                         sClass1[len(sClass1)] = valueToAppend1                                                  
#                                                     sClass2[len(sClass2)] = valueToAppend2
#                                                     sClass3[len(sClass3)] = valueToAppend3
#                                                     pDf.insert(loca, column = ['Classification 1'], pClass1)
#                                                     pDf.insert(loca, column = ['Classification 2'], pClass2)
#                                                     pDf.insert(loca, column = ['Classification 3'], pClass3)
#                                                     loc += 1
#                                                         for row in range(5):
#                                                             for col in range(3):
#                                                                 pDf.loc[row, col] = pClass1
#                                                     newsClass1 = Series(pClass1)
#                                                     sClass1 = sClass1.append(newsClass1, verify_integrity=False)
#                                                     
#                                                     newsClass2 = Series(pClass2)
#                                                     sClass2 = sClass2.append(newsClass2, verify_integrity=False)
#                                                     
#                                                     newsClass3 = Series(pClass3)
#                                                     sClass3 = sClass3.append(newsClass3, verify_integrity=False)
#         
#     return sClass1.mean(), sClass2.mean(), sClass3.mean() 
                                                  
    for index, row in df.iterrows():
        
        if row['classification'] == row['someClass']:
            acc += 1.0

    return checkingAccuracy(df, acc)
# Main method
def main():
    df = pd.read_csv('seeds.train.csv', header=0)
    df2 = pd.read_csv('seeds.test.csv', header=0)
    del df['Unnamed: 0']  # Getting rid of the index column in the dataset (we don't need this)
    del df2['Unnamed: 0']
    binarySetter(df)
    binarySetter(df2)
#     bestErrorCount = np.inf
#     for attr in df.columns[0:-1]:
# #         print attr
#         error = 0
#         ruleTato = []
#         for clss in np.unique(df[attr]):
#             errorForClass = findErrorForClass(df, attr, clss)
#             error += errorForClass["ErrorCount"]
#             ruleTato.append(errorForClass)
#         if error < bestErrorCount:
#             bestErrorCount = error
#             bestAttr = attr
#             bestRuleTato = ruleTato            
#     print "Make rule on %s" % bestAttr
#     print "Rules: %s" % bestRuleTato
    print 'Accuracy for training data is %f' % (findProbabilityOfClass(df))
    print 'Accuracy for testing data is %f' % (findProbabilityOfClass(df2))
    print 'There should be a graph somewhere... Maybe behind the IDE'
    accuracy = Series(findProbabilityOfClass(df), index = ['Training'])
    acc2 = Series(findProbabilityOfClass(df2), index = ['Test'])
    accuracy = accuracy.append(acc2, verify_integrity = False)
    
    fig = plt.figure()
    
    ax = fig.add_subplot(1,1,1)
    plt.title('Accuracy of Statistical Modeling')
    plt.ylabel('Accuracy out of 1')
    accuracy.plot(kind='bar', ax=ax, color= 'k', alpha=0.7)
    
    
    plt.show()
    
if __name__ == '__main__':
    main()
