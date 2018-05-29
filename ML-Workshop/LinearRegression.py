import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

boston = datasets.load_boston(return_X_y=False)
x = boston.data
y = boston.target

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.12, random_state=1)
reg = LinearRegression()
reg.fit(x_train, y_train)

print('Coefficients of features: ', reg.coef_)
print('y-values: ', reg.predict(x_test))

variance = reg.score(x_test, y_test)
print(variance)

plt.scatter(reg.predict(x_test), reg.predict(x_test)-y_test, color='b', label='Test data')
plt.scatter(reg.predict(x_train), reg.predict(x_train)-y_train, color='r', label='Train data')
plt.hlines(y=0, xmin=0, xmax=50, linewidth=2)
plt.title('Regression Demo')
plt.legend(loc='upper right')
plt.show()
