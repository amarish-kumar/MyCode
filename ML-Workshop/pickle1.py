from pandas import read_csv
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from pickle import dump
from pickle import load

names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pred', 'age', 'class']
df = read_csv('indians-diabetes.data', names=names)
array = df.values

x = array[:, 0:8]
y = array[:, 8]

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.33, random_state=7)

model = LogisticRegression()
model.fit(x_train, y_train)

# save the model to disk
filename = 'finalized_model.sav'
dump(model, open(filename, 'wb'))

# load the model from disk after sometime...
loaded_model = load(open(filename, 'rb'))
result = loaded_model.score(x_test, y_test)
print(result)
