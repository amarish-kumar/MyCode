import sklearn.datasets as datasets
import matplotlib.pyplot as plt

data = datasets.make_blobs		# blobs - binary large obj blocks
#x, y = data.data, data.target

x1, y1 = datasets.make_blobs(n_samples=200, centers=3, cluster_std=10)

plt.scatter(x1[:,0], x1[:,1], c='green', marker='2', edgecolors='black', s=50)
plt.grid()
plt.show()
print(x1)
