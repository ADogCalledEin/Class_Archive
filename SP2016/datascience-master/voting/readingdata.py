# -*- coding utf-8 -*-
"""

Created by gsiadak @ 2:00 PM 4/4/16

"""
import time
import pandas as pd



def main():

    df = pd.read_csv("house-votes-84.data.txt")

    inputs = df.to_dict("records")


    print(inputs)


# COMPUTATIONALTIMING #
start_time = time.time()
main()
end_time = time.time()
print("Computation Time: %g seconds" % round((end_time - start_time), 3))
