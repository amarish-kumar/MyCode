import numpy as np
from sklearn.cluster import MeanShift
from sklearn.datasets.samples_generator import make_blobs
import matplotlib.pyplot as plt

centers = [[1,1],[5,5],[3,10]]
print(centers)
x, y = make_blobs(n_samples=200, centers=centers, cluster_std=1)

# plt.scatter(x[:,0], x[:,1])
# plt.show()

ms = MeanShift()
ms.fit(x)
labels = ms.labels_
cluster_centers = ms.cluster_centers_

print('No. of labels: ', labels)
print('No. of estimated clusters: ', cluster_centers)

color = 10*['r.','g.','b.','c.','k.','y.','m.']
print(color)
for i in range(len(x)):
	plt.plot(x[i][0], x[i][1], color[labels[i]] , markersize='10')

plt.scatter(cluster_centers[:,0], cluster_centers[:,1], marker='x', s=150, linewidths=5)
plt.show()

