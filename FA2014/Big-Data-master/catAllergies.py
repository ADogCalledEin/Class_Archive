'''
Created on Oct 1, 2014

@author: GriffinSiadak
'''
import numpy as np
from pandas import Series
import matplotlib.pyplot as plt
from numpy import polyfit


allergyPerc = np.asarray([.03, .2, .36, .45, .67, .8])
catnum = np.arange(len(allergyPerc))
plt.scatter(catnum, allergyPerc)


n = len(catnum)
Ex = sum(catnum)
Ey = sum(allergyPerc)
Exy = sum (catnum * allergyPerc)
Exx = sum (catnum * catnum)
Eyy = sum (allergyPerc * allergyPerc)

b = (Ey * Exx - Ex * Exy) / (n * Exx - Ex * Ex)
m = (n * Exy - Ex * Ey) / (n * Exx - Ex * Ex)

redonk = (Exy - ((Ex * Ey) / n)) / np.sqrt((Exx - ((Ex * Ey) / n)) * (Eyy) - (Eyy) / n))

slope, intercept = polyfit(catnum, allergyPerc, 1)
fitFn = np.poly1d([slope, intercept])

print 'slope: %f, intercept: %f' % (slope, intercept)
print b, m
# Basically fit and polyfit and poly1d do all of the work for us

expected = fitFn(catnum)

plt.plot(catnum, expected, 'yo', catnum, fitFn(catnum), linestyle='--', color='red')


plt.show()
