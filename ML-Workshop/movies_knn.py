import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import KFold
from sklearn.model_selection import cross_val_score


data = pd.read_csv('movies.csv')
array = data.values
x = array[:-1, 1: 3]
y = array[:-1, -1]

model = KNeighborsClassifier(n_neighbors=1)
kfold = KFold(n_splits=3, random_state=1)

result = cross_val_score(model, x, y, cv=kfold)
print(result.mean()*100)

