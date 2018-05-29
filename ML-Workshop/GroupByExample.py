import numpy as np
import pandas as pd

df = pd.DataFrame({'Name':['Hema','Jaya','Rekha','Shushma','Ramesh','Suresh','Dinesh','Richa']
	, 'State':['UP','MP','HP','AP','OD','BR','CG','HH']
	, 'Grade':['A','A','B','C','D','E','A','B']
	, 'Age':np.random.uniform(20,50,size=8)
	, 'Salary':np.random.uniform(5000,30000,size=8)})

df2 = pd.DataFrame(df, columns=['Name','State','Age','Salary'])
df3 = df2.groupby(['Name']).max()
print(df3)