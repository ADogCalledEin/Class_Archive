# -*- coding: utf-8 -*-
"""
Created on Fri Feb  5 19:18:29 2016

@author: gsiadak
"""

a = 0
g = 0
c = 0
t = 0

with open('rosalind_dna.txt', 'r') as input:
    data = input.read()
#data = 'AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC'
    
for i in data:
    if i =="A":
        a = a + 1
    if i =="C":
        c = c + 1
    if i =="G":
        g = g + 1
    if i == "T":
        t = t + 1

print (a,c,g,t)