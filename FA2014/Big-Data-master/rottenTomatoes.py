'''
Created on Sep 10, 2014

@author: GriffinSiadak
'''
import requests
from pandas import DataFrame
apiKey = 'av9dzxft8f9mabtr5nk2m32y'
path= 'http://api.rottentomatoes.com/api/public/v1.0/lists/movies/box_office.json'
param = {
         
         'apikey': apiKey,
         'limit': 50
         }

records = requests.get(path, params=param)
print records.json()
recordsDictionary = records.json()


df = DataFrame(recordsDictionary['movies'])
print df