# -*- coding: utf-8 -*-
"""
Created on Mon Feb  8 11:44:24 2016

@author: gsiadak
"""

#input = "GATGGAACTTGACTACGTAAATT"

with open('rosalind_rna.txt', 'r') as input:
    data = input.read()    

    new = data.replace("T", "U")
    
    print (new)
