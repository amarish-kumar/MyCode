from pandas import read_csv
from sklearn.decomposition import PCA

names = ['preg', 'plas', 'pres', 'skin',
         'test', 'mass', 'pred', 'age', 'class']
data = read_csv('indians-diabetes.data', names=names)
array = data.values

x = array[:,0:8]
y = array[:,8]

pca = PCA(n_components=3)
fit = pca.fit(x)

print("Explained variance:", fit.explained_variance_ratio_)
print(fit.components_)
