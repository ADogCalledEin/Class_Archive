# -*- coding utf-8 -*-
"""

Created by gsiadak @ 11:34 AM 3/4/16

"""
import time
import pandas as pd
from Bio import SeqIO
import collections

def main():

    fasta_seq = []
    for seq_record in SeqIO.parse('rosalind_cons.txt', 'fasta'):
        fasta_seq.append(seq_record.seq.tostring())

    A = [0] * (len(fasta_seq[0]))
    C = [0] * (len(fasta_seq[0]))
    G = [0] * (len(fasta_seq[0]))
    T = [0] * (len(fasta_seq[0]))

# getting frequency matrix built
    for dna in fasta_seq:
        counter = 0
        for i in range(len(dna)):
            if dna[i] == 'A':
                A[counter] += 1
            if dna[i] == 'C':
                C[counter] += 1
            if dna[i] == 'G':
                G[counter] += 1
            if dna[i] == 'T':
                T[counter] += 1
            counter += 1

    # print(A)
    # print(C)
    # print(G)
    # print(T)

    #getting consensus string
    nstrlist = []
    for i in range(len(A)):
        a = A[i]
        c = C[i]
        g = G[i]
        t = T[i]

        if a > c and a > g and a > t:
            nstrlist.append("A")
        elif c > a and c > g and c > t:
            nstrlist.append("C")
        elif g > a and g > c and g > t:
            nstrlist.append("G")
        else:
            nstrlist.append("T")

    constr = ",".join(nstrlist)
    constr = constr.replace(",", "")

    #printing it nicely




    print(constr)
    print("A:", *A, "")
    print("C:", *C, "")
    print("G:", *G, "")
    print("T:", *T, "")



# COMPUTATIONALTIMING #
start_time = time.time()
main()
end_time = time.time()
print("Computation Time: %g seconds" % round((end_time - start_time), 3))
