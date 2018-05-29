import pandas as pd
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_excel('data.xlsx')
df.head()

data = df.values
x1 = data[:, 2:9]
print('Type: ', x1.dtype)

df1 = df.drop(['ID Tag', 'Model', 'Department'], axis=1)

km = KMeans(n_clusters=4, init='k-means++', n_init=10)
km.fit(x1)
x = km.fit_predict(x1)

df['Cluster'] = x
print(df.groupby(['Cluster']).mean())

sns.lmplot('WO count', 'Labor Cost',
			data=df,
			fit_reg=False,
			hue='Cluster',
			scatter_kws={'marker': 'D', 's': 20})

plt.title('Low work order and labour count')
plt.xlabel('Low work order')
plt.ylabel('Labour count')
plt.show()
