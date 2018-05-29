import pandas as pd
from sklearn.model_selection import LeaveOneOut
from sklearn.model_selection import cross_val_score
from sklearn.linear_model import LogisticRegression

names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pred', 'age', 'class']
data = pd.read_csv('indians-diabetes.data', names=names)
array = data.values

x = array[:,0:8]
y = array[:,8]

num_fold = 10
locv = LeaveOneOut()

model = LogisticRegression()
result = cross_val_score(model, x, y, cv=locv)

print(result.mean()*100, result.std()*100)