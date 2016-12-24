# -*- coding utf-8 -*-
from matplotlib import pyplot as plt
import pandas as pd #YES I USE PANDAS ITS AMAZING
import numpy as np
#1.
#opening the csv into a dataframe and redefining it so we only have the data we need
df = pd.read_csv('annual.csv')
df = df[df['Source'] == 'GCAG']
#pulling the data we want
years = df['Year']
temps = df['Mean']
#plotting it
plt.plot(years, temps)
plt.title('Global Mean Temperatures')
plt.xlabel('Year')
plt.ylabel('Difference from 20th century average ('+ u'\N{DEGREE SIGN}' + 'C)')
plt.show()

#2.
#opening the csv into a dataframe
df = pd.read_csv('global.csv')
#pulling the data we need and plotting it
years = df['Year']
totals = df['Total']
plt.plot(years, totals)
plt.title('Carbon Emission Averages')
plt.xlabel('Year')
plt.ylabel('Millions of tons of Carbon Emissions')
plt.show()

#3.
#reading in csv
df = pd.read_csv('guns.csv')
#getting rid of NaNs and then sorting it in descending
rate = df[np.isfinite(df['Average firearms per 100 people'])]
rate = rate.sort_values(by='Average firearms per 100 people', ascending=False)
#pulling out the lists we need and shortening them to 20 lines
#I convert the frame columns to a list since they're more direct to plot with
names = rate['ISO code'][:20]
rate = rate['Average firearms per 100 people'][:20]
#setting the bar width
xs = [i + 0.1 for i, _ in enumerate(rate)]
#plot away
plt.bar(xs, rate)
plt.xticks([i + 0.5 for i, _ in enumerate(names)], names)
plt.ylabel('Ownership per 100 People')
plt.xlabel('Countries')
plt.title('Average Ownership per 100 People')
plt.show()

#4.
#reading in the csv then pulling out the values I need
#Theres no column labels, so if you don't specify None as the header 
#it defaults to row 0
df = pd.read_csv('iris.csv', header=None)
length = df[0]
width = df[1]
#PLOT PLOT PLOT PLOT PLOT PLOT PLOT PLOT PLOT PLOT PLOT PLOT PLOT PLOT PLOT PLOT 
#EVERYBODY (read like Lil Jon)
plt.scatter(length, width)
plt.title('Iris Data')
plt.xlabel('Sepal Length (cm)')
plt.ylabel('Sepal Width (cm)')
plt.show()
