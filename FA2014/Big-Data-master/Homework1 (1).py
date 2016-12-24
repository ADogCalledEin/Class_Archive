# 1.
# Scan in the file named "cs495_input1_1.npy" and put it in a 100x100 ndarray and call the variable 'original'. Then, print 'original'.

# 2.
# Create and print a new bucketed array named 'buckets', such that all elements are floored by 10s. Then, pring 'buckets'.
# Ex. 39 becomes 30, 42 becomes 40.


# 3.
# Print the [23-45] element of the [50-55] Row of 'original'. Then, replace them with 0 and 'original'.
# Both of these ranges are inclusive on both sides. So, if you test original[45][55], it should be 0.


# 4.
# Scan in the file named "cs495_input1_2.npy" and put it into a 100x100 ndarray and call the variable 'names'


# 5.
# For each element in 'original', if it changed more than 5 at step 2, change that element in 'names' to 'Frank
# Ex. If original[1][2] was 46, then buckets[1][2] is 40. Since the difference between the 2 is > 5, names[1][2] becomes 'Frank'


# 6.
# Print which names are in 'names' that are not 'Frank'. This will be a one-dimensional array.


import numpy as np
# 1
original = np.load('cs495_input1_1.npy').reshape (100,100)
# print original
# 2
buckets = original
buckets= (np.floor(buckets/10)*10)
# print buckets
# 3
buckets_slice=buckets[50:55,23:45]
original[50:56, 23:46] = 0
# print original[55][45]

# 4
names = np.load('cs495_input1_2.npy').reshape (100,100)
# print names
# 5
names[(original - buckets) > 5] = 'Frank'
# 6
print names[names != 'Frank']


