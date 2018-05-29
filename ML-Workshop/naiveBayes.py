import pandas as pd
from sklearn.model_selection import KFold
from sklearn.model_selection import cross_val_score
from sklearn.naive_bayes import GaussianNB

names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pred', 'age', 'class']
data = pd.read_csv('indians-diabetes.data', names=names)
array = data.values

x = array[:,0:8]
y = array[:,8]

num_fold = 10
seed = 7
kfold = KFold(n_splits=num_fold, random_state=seed)

model = GaussianNB()
result = cross_val_score(model, x, y, cv=kfold)

print(result.mean()*100, result.std()*100)