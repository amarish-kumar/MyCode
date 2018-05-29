import pandas as pd
from sklearn.model_selection import ShuffleSplit
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import cross_val_score

names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pred', 'age', 'class']
data = pd.read_csv('indians-diabetes.data', names=names)
array = data.values

x = array[:,0:8]
y = array[:,8]

test_size = 0.33
seed = 7	# removing this arg will cause the accuracy to vary

kfold = ShuffleSplit(n_splits=10, test_size=test_size, random_state=seed)

model = LogisticRegression()
result = cross_val_score(model, x, y, cv=kfold)

print(result.mean()*100, result.std()*100)