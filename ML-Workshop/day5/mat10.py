import numpy as np
import pandas as pd
import matplotlib.pylab as plt

# cols: preg, plas, pres, skin, test, mass, pred, age, class
name = ['preg','plas','pres','skin','test','mass','pred','age','class']

data = pd.read_csv('indians-diabetes.data', names=name)
cor = data.corr()
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
cmax = ax.matshow(cor, vmin=-1, vmax=1)
fig.colorbar(cmax)
ticks = np.arange(0,9,1)
ax.set_xticks(ticks)
ax.set_yticks(ticks)
ax.set_xticklabels(name)
ax.set_yticklabels(name)
plt.show()
# print(cor)