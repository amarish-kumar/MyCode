import pandas as pd
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_excel('data.xlsx')

df1 = df.drop(['ID Tag', 'Model', 'Department'], axis=1)
print(df1.head())

km = KMeans(n_clusters=4, init='k-means++', n_init=10)	# k-means++ algo works fast; n_init is no. of runs
km.fit(df1)
x = km.fit_predict(df1)
data = df1.values
x1 = data[:,0:7]
labels = km.labels_
print(x1)

plt.scatter(km.cluster_centers_[:, 0], km.cluster_centers_[:,1], s=250, marker='x', linewidth=5)
for i in  range(0,len(x1[0])):
	plt.scatter(x1[x == 0, 0], x1[x == 0, i], c='r')
	'''
	plt.scatter(x1[x == 1, 1], x1[x == 1, i], c='b')
	plt.scatter(x1[x == 2, 2], x1[x == 2, i], c='g')
	plt.scatter(x1[x == 3, 3], x1[x == 3, i], c='black')
	'''

plt.show()
print(x)

print(pd.crosstab(labels, x))
print(labels)
print(x)

#df['Cluster'] = x 
#print(df.head())
#print(km.labels_)

# df = df.sort_values(['Cluster'])
# print(df)

# df.to_excel('opt.xlsx', index=False)
