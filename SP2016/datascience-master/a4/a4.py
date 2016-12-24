# -*- coding utf-8 -*-
"""

Created by gsiadak @ 13:07 2/28/16

"""

import pandas as pd
import time

def maleprob(df, length):
    counter = 0

    for row in df[0]:
        if row == "M":
            counter +=1

    ratio = float(counter)/float(length)
    return ratio

def largeprob(df, mean, length):
    counter = 0

    for row in df[1]:
        if row > mean:
            counter += 1

    ratio = float(counter)/float(length)
    return ratio

def maleAndLarge(df, mean, length):
    counter = 0

    for index, row in df.iterrows():
        if (row[0] == "M") and (row[1] > mean):
            counter += 1

    ratio = float(counter)/float(length)
    return ratio

def main():
    df = pd.read_csv('abalone.csv', header=None)
    dfLength = len(df.index)
    mLength = df[1].mean()

    rMean = df[8].mean()
    rMed = df[8].median()
    rStd = df[8].std()
    rCorr = df[1].corr(df[8])
    pMale = maleprob(df, dfLength)
    pLarge = largeprob(df, mLength, dfLength)
    pMaleAndLarge = maleAndLarge(df, mLength, dfLength)
    pMaleOrLarge = (pMale + pLarge) - pMaleAndLarge
    pMaleIfLarge = pMaleAndLarge / pLarge
    pLargeIfMale = pMaleAndLarge / pMale

    print("Mean number of rings: %s" % round(rMean, 4))
    print("Median number of rings: %s" % rMed)
    print("Standard deviation of Number of Rings: %s" % round(rStd, 4))
    print("Correlation between length and rings: %s" % round(rCorr, 4))
    print("P[male]: %s" % round(pMale, 4))
    print("P[large]: %s" % round(pLarge, 4))
    print("P[male and large]: %s" % round(pMaleAndLarge, 4))
    print("P[male or large]: %s" % round(pMaleOrLarge, 4))
    print("P[male | large]: %s" % round(pMaleIfLarge, 4))
    print("P[large | male]: %s\n" % round(pLargeIfMale, 4))




start_time = time.time()
main()
end_time = time.time()
print("Computation Time: %g seconds" % round((end_time - start_time), 3))
