import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from sklearn.cluster import KMeans
from sklearn import datasets

iris = datasets.load_iris()
x = iris.data
y = iris.target

k_mean = KMeans(n_clusters=3)
k_mean.fit(x)

fig = plt.figure(figsize=(4,3))
plt.clf()		# clear axes
ax = Axes3D(fig, rect=[0,0,1,1])
plt.cla()		# clear entire figure
labels = k_mean.labels_
ax.scatter(x[:,3], x[:,0], x[:,2], c=labels.astype(np.float))

ax.w_xaxis.set_ticklabels([])
ax.w_yaxis.set_ticklabels([])
ax.w_zaxis.set_ticklabels([])
ax.set_xlabel('Petal Width')
ax.set_ylabel('Sepal Length')
ax.set_zlabel('Petal Length')
plt.show()

