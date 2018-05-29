import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

data = pd.read_csv('movies.csv')
array = data.values
x = array[:,1:2]
y = array[:,2:3]

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.33, random_state=7)

model = LinearRegression()
model.fit(x_train, y_train)

plt.scatter(model.predict(x_train), model.predict(x_train)-y_train, color='green', s=10, label='Train data')
plt.scatter(model.predict(x_test), model.predict(x_test)-y_test, color='blue', s=10, label='Test data')

plt.hlines(y=0, xmin=0, xmax=50, linewidth=2)
plt.title('Data')
plt.legend(loc='upper right')
plt.show()

