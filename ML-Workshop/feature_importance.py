from sklearn.ensemble import ExtraTreesClassifier
from pandas import read_csv

names = ['preg', 'plas', 'pres', 'skin',
         'test', 'mass', 'pred', 'age', 'class']
data = read_csv('indians-diabetes.data', names=names)
val = data.values

x = val[:, 0:8]
y = val[:, 8]

model = ExtraTreesClassifier()
model.fit(x, y)
print(model.feature_importances_)
#[ 0.10324539  0.23931158  0.10305729  0.07853572  0.07223132  0.13919265
 # 0.11779331  0.14663274]