'''
Created on Sep 10, 2014

@author: GriffinSiadak
'''
import numpy as np
from pandas import  DataFrame, Series

dc={'num':[1,2,3,0],'letter':['a','b','c','d']}
# print dc
ser = Series(dc['letter'], name='Letters', index=dc['num'])
# print ser
# print ser.name

# ser = ser.sort_index(ascending=False)


df = DataFrame(ser)
# print df
# print df.describe()

df['col2']= [10,20,30, np.nan]
# print df

# print df.T

dc ={'Oregon':{'cool': 9001,'trees': 150}, 'California':{'cool': 10, 'beaches':5}}

stateFrame = DataFrame(dc)
stateFrame.insert(2, 'Washington', [2, np.nan,1])
# print stateFrame
# print stateFrame.describe()


stateFrame=stateFrame.rename(index={'beaches':'hella beaches', 'cool':'hella cool', 'trees':'hella trees'})
print stateFrame
print stateFrame.index
print stateFrame.drop('Washington',axis=1)











