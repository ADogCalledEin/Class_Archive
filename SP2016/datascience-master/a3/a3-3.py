# -*- coding: utf-8 -*-
"""
Created on Mon Feb  8 11:51:12 2016

@author: gsiadak
"""

with open ('rosalind_revc.txt', 'r') as input:
    data = input.read()
    new = ' '
    for i in data:
        if i == "A":
            new = new + "T"
        elif i == "T":
            new = new + "A"
        elif i == "C":
            new = new + "G"
        elif i == "G":
            new = new + "C"
        
    new = new[::-1]

print(new)

