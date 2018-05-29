import pandas as pd
from sklearn.model_selection import KFold
from sklearn.model_selection import cross_val_score
from sklearn.linear_model import LinearRegression

names = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE',
                 'DIS', 'RAD', 'TAX', 'PTRATIO',
                 'B', 'LSTAT', 'MEDV']
data = pd.read_csv('housing.data', delim_whitespace=True, names=names)
array = data.values

x = array[:, 0:13]
y = array[:, 13]

kfold = KFold(n_splits=10, random_state=7)

model = LinearRegression()
scoring = 'neg_mean_absolute_error'		# 'accuracy' is default
result = cross_val_score(model, x, y, cv=kfold, scoring=scoring)

print(result.mean(), result.std())
