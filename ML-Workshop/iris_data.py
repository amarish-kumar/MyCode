import pandas as pd
from sklearn import datasets
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

names = ['min', 'max', 'mean', 'sd', 'class']
data = pd.read_csv('iris.data', names=names)

array = data.values
i = 0
'''for x in data['class']:
	if x == 'Iris-setosa':
		data['class'][i] = 0
	elif x == 'Iris-versicolor':
		data['class'][i] = 1
	else:
		data['class'][i] = 2
	i += 1'''

print(array)
x = array[:, 0:3]
y = array[:, 3]
plt.plot(x, y)

'''
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.33, random_state=7)

model = LinearRegression()
model.fit(x_train, y_train)
result = model.score(x_test, y_test)

print("Accuracy: ", result.mean()*100.0, result.std()*100)
'''
