import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report
import matplotlib.pylab as plt

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
report = classification_report(y_test, predicted)

print(report)
report = report[60:160].strip('\t').split()
new = []
for x in report:
	i = float(x)
	new.append(i)

print(new)

