from sklearn import datasets

pdata = datasets.load_boston(return_X_y=False)
x = pdata.data
y = pdata.target
print(x, y)
