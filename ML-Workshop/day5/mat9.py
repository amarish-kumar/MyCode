import pandas as pd
import matplotlib.pylab as plt

# cols: preg, plas, pres, skin, test, mass, pred, age, class
name = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pred', 'age', 'class']

data = pd.read_csv('indians-diabetes.data', names=name)
data.plot(kind='density', subplots=True, sharex=False, layout=(3, 3))
plt.show()
data.plot(kind='box', subplots=True, sharey=False, layout=(3, 3))
plt.show()
