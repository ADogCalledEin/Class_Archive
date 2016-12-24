'''
Created on Oct 3, 2014

@author: GriffinSiadak
'''
import math

# Entropy function
def info(vals):
    total = sum(vals)
    infosum  = 0
    for val in vals:
        if val != 0:
            infosum += -(float(val)/total)*math.log(float(val)/total,2)
    return infosum

print info([2,3])

# def gain():