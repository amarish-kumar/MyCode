from numpy import set_printoptions
from sklearn.feature_selection import RFE
from sklearn.linear_model import LinearRegression
from pandas import read_csv

names = ['preg', 'plas', 'pres', 'skin',
         'test', 'mass', 'pred', 'age', 'class']
data = read_csv('indians-diabetes.data', names=names)
val = data.values

x = val[:, 0:8]
y = val[:, 8]

model = LinearRegression()
rfe = RFE(model, 3)
fit = rfe.fit(x, y)

print("No. of features: ", fit.n_features_)
print("Selected features: ", fit.support_)
print("Feature ranking: ", fit.ranking_)
