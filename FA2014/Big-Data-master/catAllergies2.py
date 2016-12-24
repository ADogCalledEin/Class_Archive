'''
Created on Oct 1, 2014

@author: ntiller
'''
import numpy as np
from pandas import Series
import matplotlib.pyplot as plt
import math


allergyPerc = np.asarray([.03, .2, .36, .45, .67, .8])
catnum = np.arange(len(allergyPerc))
plt.scatter(catnum, allergyPerc)

n = len(catnum)
Ex = sum(catnum)
Ey = sum(allergyPerc)
Exy = sum(catnum * allergyPerc)
Exx = sum(catnum * catnum)
Eyy = sum(allergyPerc * allergyPerc)

sxx = Exx - ((Ex * Ex) / n)
syy = Eyy - ((Ey * Ey) / n)
sxy = Exy - ((Ex * Ey) / n)

print 'Correlation Coefficient: %f' % (sxy / (math.sqrt(sxx * syy)))



b = (Ey * Exx - Ex * Exy) / (n * Exx - Ex*Ex)
m = (n * Exy - Ex * Ey) / (n * Exx - Ex*Ex)

slope, intercept = np.polyfit(catnum, allergyPerc, 1)
fitFn = np.poly1d([slope, intercept])


print 'slope: %f, intercept: %f' % (slope, intercept)
print b, m

expected = fitFn(catnum)

plt.plot(catnum, expected, linestyle='--', color='red')

plt.show()




