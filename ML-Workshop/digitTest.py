import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import KFold

data = pd.read_csv('train.csv').as_matrix()
print(data)

clf = DecisionTreeClassifier()
x_train = data[0:21000, 1:]
y_train = data[0:21000,0]
clf.fit(x_train, y_train)

x_test = data[21000:,1:]
y_test = data[21000:,0]
d = x_test[8]
d.shape = (28,28)

plt.imshow(d, cmap='gray')

model = DecisionTreeClassifier()
kfold = KFold(n_splits=10, random_state=1)
result = cross_val_score(model, x_test, y_test, cv=kfold)
print(result.mean()*100)
