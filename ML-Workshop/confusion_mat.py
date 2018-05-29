import pandas as pd
import matplotlib.pylab as plt
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix

names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pred', 'age', 'class']
data = pd.read_csv('indians-diabetes.data', names=names)
array = data.values

x = array[:,0:8]
y = array[:,8]

test_size = 0.33
seed = 7	# removing this arg will cause the accuracy to vary
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=test_size, random_state=seed)

model = LogisticRegression()
model.fit(x_train, y_train)
predicted = model.predict(x_test)
matrix = confusion_matrix(y_test, predicted)
print(matrix)


fig = plt.figure()
ax = fig.add_subplot(1,1,1)
cmax = ax.matshow(data.corr(), vmin=-1, vmax=1)
fig.colorbar(cmax) 
cmax = ax.matshow(matrix, vmin=-1, vmax=1)
fig.colorbar(cmax)
ticks = np.arange(0,9,1)
ax.set_xticks(ticks)
ax.set_yticks(ticks)
ax.set_xticklabels(names)
ax.set_yticklabels(names)
plt.show()
