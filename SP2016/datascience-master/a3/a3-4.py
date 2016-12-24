# -*- coding: utf-8 -*-
"""
Created on Mon Feb  8 11:58:18 2016

@author: gsiadak
"""

n = 29
k = 2

def fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return (k * fib(n - 2)) + fib(n - 1)

print(fib(n))