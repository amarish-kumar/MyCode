from numpy import set_printoptions
import pandas as pd
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import chi2

names = ['preg', 'plas', 'pres', 'skin',
         'test', 'mass', 'pred', 'age', 'class']
data = pd.read_csv('indians-diabetes.data', names=names)

val = data.values
x = val[:, 0:8]
y = val[:, 8]

test = SelectKBest(score_func=chi2, k=4)
fit = test.fit(x, y)	# x = classification, y = regression

set_printoptions(precision=3)
print(fit.scores_)
feature = fit.transform(x)
print(feature[:5, :])
