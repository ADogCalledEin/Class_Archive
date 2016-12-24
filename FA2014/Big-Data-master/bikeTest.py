'''
Created on Oct 6, 2014

@author: GriffinSiadak
'''

import numpy as np
import pandas as pd
from pandas import DataFrame, Series
import matplotlib.pyplot as plt


df = pd.read_csv('bike_share_test.csv', header=0, index_col = 'instant')

fig1, ax1 = plt.subplots(1,1)
fig2, ax2 = plt.subplots(1,1)
ax1.scatter(df.registered, df.cnt)
ax1.set_xlabel('Registered')
ax1.set_ylabel('Number Rented')  


highestCorrelation = 0.0
for col in df.columns[1:-1]:
    correlation = df[col].corr(df.cnt)
    if correlation > highestCorrelation and abs(df[col].corr(df.registered)) < 0.5:
        highestCorrelation = correlation
        highestCorrelationColumn = col
        
ax2.scatter(df[highestCorrelationColumn], df.cnt)
ax2.set_xlabel(highestCorrelationColumn)
ax2.set_ylabel('Number Rented')       
        
print '%s --- correlation with Count: %f' % (highestCorrelationColumn, df[highestCorrelationColumn].corr(df.cnt))
print 'correlation: ' , df.registered.corr(df.cnt)
plt.show()
