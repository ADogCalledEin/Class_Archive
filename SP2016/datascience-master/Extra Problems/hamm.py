# -*- coding: utf-8 -*-


strings = []
count = 0
with open('rosalind_hamm.txt', 'r') as f:
    for line in f:
        strings.append(line.rstrip())
    str1 = strings[0]
    str2 = strings[1]
    for i in range(len(str1)):
        if str1[i] != str2[i]:
            count += 1
    print(count)