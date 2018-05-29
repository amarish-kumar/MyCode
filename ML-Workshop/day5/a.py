from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import Normalizer
from sklearn.preprocessing import Binarizer
from pandas import read_csv
from numpy import set_printoptions

names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pred', 'age', 'class']
df = read_csv('indians-diabetes.data', sep=',', names=names)
array = df.values

x = array[:,0:8]
y = array[:,8]
scaler = StandardScaler().fit(x)
rescaledX = scaler.transform(x)

set_printoptions(precision=3)
print(rescaledX[0:5,:])

scaler = Normalizer().fit(x)
rescaledX = scaler.transform(x)

set_printoptions(precision=3)
print(rescaledX[0:5,:])

scaler = Binarizer().fit(x)
rescaledX = scaler.transform(x)

set_printoptions(precision=3)
print(rescaledX[0:5,:])

