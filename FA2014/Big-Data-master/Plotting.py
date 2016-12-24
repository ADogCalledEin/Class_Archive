'''
Created on Sep 12, 2014

@author: GriffinSiadak
'''
import matplotlib.pyplot as plt
from pandas import DataFrame, Series
from numpy.random import randn, random
import numpy as np

fig = plt.figure()
 
ax1= fig.add_subplot(2,2,1)
ax2= fig.add_subplot(2,2,2)
ax3= fig.add_subplot(2,2,3)
ax4= fig.add_subplot(2,2,4)
# fig, axes = plt.subplot(2, 3)
# print axes

ser = Series(randn(100))

ax1.plot(ser.cumsum(), 'k', marker = 'o')
ax1.set_xlim(40,60)

ax2.hist(ser, bins=20)

ax3.scatter(np.arange(100), np.arange(100) + 3 * randn(100))

nfig = plt.figure()
nax = nfig.add_subplot(1,1,1)
nax.plot(randn(1000).cumsum(), 'k', label ='One')
nax.plot(randn(1000).cumsum(), 'k--', label ='Two')
nax.plot(randn(1000).cumsum(), 'g', label='Three')
nax.legend(loc='best')

df = DataFrame(randn(10, 4).cumsum(0), columns=['A','B','C','D'], index=np.arange(0,100,10))
df.plot()

barr = Series(random(16), index=list('abcdefghijklmnop'))
barr.plot(kind='bar', ax=ax4, color= 'k', alpha=0.7)

fig, axes = plt.subplots(2,2)
df.plot(kind='barh', ax=axes[0][0], stacked=False)
df.plot(kind='barh', ax=axes[0][1], stacked=True)

rect = plt.Rectangle((0.2,0.75), 0.4, 0.15, color='k', alpha=0.3)
circ = plt.Circle((0.7,0.2),0.15, color='b', alpha=0.3)
axes[1][0].add_patch(rect) 
axes[1][0].add_patch(circ)

plt.show()