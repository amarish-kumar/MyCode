import numpy as np
import pandas as pd
import matplotlib.pylab as plt
from pandas.tools.plotting import scatter_matrix

# cols: preg, plas, pres, skin, test, mass, pred, age, class
name = ['preg','plas','pres','skin','test','mass','pred','age','class']

data = pd.read_csv('indians-diabetes.data', names=name)
scatter_matrix(data)
plt.show()


