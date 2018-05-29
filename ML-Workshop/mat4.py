import pandas as pd
import numpy as np
from pylab import *

df = pd.DataFrame({'Name':['Hema','Jaya','Rekha','Shushma','Ramesh','Suresh','Dinesh','Richa']
	, 'State':['UP','MP','HP','AP','OD','BR','CG','HH']
	, 'Grade':['A','A','B','C','D','E','A','B']
	, 'Age':np.random.uniform(20,50,size=8)
	, 'Salary':np.random.uniform(5000,30000,size=8)})

df.hist()
show()
df.boxplot()
show()