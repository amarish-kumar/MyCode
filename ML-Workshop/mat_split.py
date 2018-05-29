import pandas as pd
import matplotlib.pylab as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn import datasets

names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pred', 'age', 'class']
data = pd.read_csv('indians-diabetes.data', names=names)
array = data.values

x = array[:,0:8]
y = array[:,8]

test_size = 0.33
seed = 7	# removing this arg will cause the accuracy to vary
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=test_size, random_state=seed)

model = LinearRegression()
model.fit(x_train, y_train)

plt.scatter(model.predict(x_train), model.predict(x_train)-y_train, color='green', s=10, label='Train data')
plt.scatter(model.predict(x_test), model.predict(x_test)-y_test, color='blue', s=10, label='Test data')

plt.hlines(y=0, xmin=0, xmax=50, linewidth=2)
plt.title('Data')
plt.legend(loc='upper right')
plt.show()

result = model.score(x_test, y_test)

print("Accuracy: ", result.mean()*100.0, result.std()*100)
print(result*100)

# boston dataset
data = datasets.load_boston(return_X_y=False)
x = data.data
y = data.target
test_size=0.12
seed=1
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=test_size, random_state=seed)

model = LinearRegression()
model.fit(x_train, y_train)

plt.scatter(model.predict(x_train), model.predict(x_train)-y_train, color='green', s=10, label='Train data')
plt.scatter(model.predict(x_test), model.predict(x_test)-y_test, color='blue', s=10, label='Test data')

plt.hlines(y=0, xmin=0, xmax=50, linewidth=2)
plt.title('Data')
plt.legend(loc='upper right')
plt.show()
