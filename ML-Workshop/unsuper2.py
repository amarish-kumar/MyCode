from sklearn import datasets
import pandas as pd
from sklearn.cluster import KMeans

iris = datasets.load_iris()
x, y = iris.data, iris.target

kmean = KMeans(n_clusters=3)
kmodel = kmean.fit(x)
print(y)
print(kmodel.labels_)
print(kmodel.cluster_centers_)
print(pd.crosstab(y, kmodel.labels_))

