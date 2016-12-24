# -*- coding: utf-8 -*-
"""
Created on Wed Feb 10 12:04:41 2016

@author: gsiadak
"""

from Bio import SeqIO


for seq_record in SeqIO.parse('rosalind_gc.txt', 'fasta'):
    print(seq_record.id)
    count = total = 0
    for i in seq_record.seq:
        if (i == "C") or (i == "G"):
            count += 1
    length = len(seq_record.seq)
    percentage = '%.6f' % (float(count) / float(length) * 100)

    print(percentage)
