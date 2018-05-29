import numpy as np
import matplotlib.pylab as plt
import pandas as pd

df = pd.DataFrame({'ID':['Hema','Jaya','Rekha','Shushma','Ramesh','Suresh','Dinesh','Richa']
	, 'Marks':np.random.uniform(10,100,size=8)})

plt.scatter(df['ID'],df['Marks'])
plt.savefig('student_plot.png',dpi=1250)
