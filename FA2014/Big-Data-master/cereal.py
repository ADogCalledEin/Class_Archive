'''
Created on Oct 6, 2014

@author: GriffinSiadak
'''
import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import matplotlib.pyplot as plt



df = pd.read_csv('cereal.csv', header=0, index_col='name')

print df[df.rating == min(df.rating)]
plt.scatter(df.sugars, df.rating)
print df.sugars.corr(df.rating)


slope, intercept = np.polyfit(df.sugars, df.rating, 1)
fit_fn = np.poly1d([slope, intercept])
# estimatedPoints = slope * df.sugars + intercept
print 'slope, intercept: ' , slope, intercept


n = np.max(df.sugars.size)
X = np.vstack([np.ones(n), df.sugars, df.fat]).T


print np.linalg.lstsq(X, df.rating)[0]
print 'fat/sugar correlation' ,df.sugars.corr(df.fat)



plt.plot(df.sugars, fit_fn(df.sugars), color = 'red', linestyle = '--')

plt.show()