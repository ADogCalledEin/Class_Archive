import matplotlib.pyplot as plt
import numpy as np
from pandas import Series, DataFrame

# Create a Figure with 4 different subplots in a 2x2 matrix.

fig=plt.figure()

ax1= fig.add_subplot(2,2,1)
ax2= fig.add_subplot(2,2,2)
ax3= fig.add_subplot(2,2,3)
ax4= fig.add_subplot(2,2,4)



# For Axis 1, create a Series that ranges across 1-15, with the indexes named 'A', 'B', 'C' ... 'O' 
# and plot the Series in a dashed line plot
# barr = Series(random(16), index=list('abcdefghijklmnop'))

ser = Series(np.arange(15), index=list('ABCDEFGHJIKLMNO'))
ax1.plot(ser, 'k--', marker = 'o')

# Create a dictionary for the following data:
# Oregon -- 2012: 1000, 2013: 900, 2014: 500
# California -- 2012: 100, 2013: 300, 2014: 700
# Washington -- 2012: 1100, 2013: 800, 2014: 700
# Idaho -- 2012: 200, 2013: 400, 2014: 600
# Then create a DataFrame from the dictionary and plot it to Axis 2 with a line graph. Title it 'TMNT Action Figures' 
# (the title can be achieve by passing in a String as an argument to the plotting call, using plot(title='TITLE'). 
fig2=plt.figure()
ax5=fig2.add_subplot(1,1,1)
data = {'Oregon':{'2012':1000,'2013':900,'2014':500},'California':{'2012':100,'2013':300,'2014':700},'Washington':{'2012':1100,'2013':800,'2014':700},'Idaho':{'2012':200,'2013':400,'2014':600}}
df = DataFrame(data)
df.plot(title='TMNT Action Figures', ax=ax5)


# Again, load in 'cs495_input1_2.npy' into a list.
# Load that information into a Series and give the Series a name (via an argument to the Series constructor).
# Update your Series variable to instead be the value count of each element in the Series (this can be achieved
# by using Series's value_counts() function and saving that into your variable). Plot this series on the top-right
# axis as a horizontal bar graph, with an xlim that goes from the minimum value of your Series minus 10 
# (ser.min()-10) to the maximum plus 10 (ser.max()+10).  
li=np.load('cs495_input1_2.npy')
ser2 = Series(li)
ser2 = ser2.value_counts()
ser2.plot(kind='barh', ax=ax2, color= 'k', alpha=0.7)
ax2.set_xlim((ser2.min()-10),(ser2.max()+10))

# For the bottom left axis, make a scatter plot where x ranges over 0-100 and y is the range from 0-100 plus a normal 
# distribution multiplied by 10. 
x = np.arange(100)
y = np.arange(100) + (np.random.randn(100))*10
ax3.scatter(x, y)
# Create a histogram that shows the information from cs495_input2_1.npy over 10 bins and put it in the bottom right
# axis.
data=np.load('cs495_input2_1.npy')
ax4.hist(data, bins = 10)


plt.show()