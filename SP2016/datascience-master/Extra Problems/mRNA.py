# -*- coding utf-8 -*-
"""

Created by gsiadak @ 11:48 AM 3/2/16

"""

from Bio.Alphabet import IUPAC
from Bio.Seq import Seq

with open('rosalind_prot.txt', 'r') as f:
    data=f.read().replace('\n', '')

rna = Seq(data,IUPAC.unambiguous_rna)
trna = rna.translate()
print(trna)