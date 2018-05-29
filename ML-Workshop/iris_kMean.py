from sklearn import cluster, datasets

iris = datasets.load_iris()
x_iris = iris.data
y_iris = iris.target
k_mean = cluster.KMeans(n_clusters=3)
print(k_mean)
k_mean.fit(x_iris)
print(k_mean.labels_)
print(k_mean.labels_[::10])
print(y_iris[::])
