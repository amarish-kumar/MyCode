import pandas as pd
from pylab import *

df_custs = pd.read_csv('custs', sep=',')
df_custs.columns = list(['ID', 'Firstname', 'Surname', 'Age', 'Occupation'])

df_txn = pd.read_csv('txns1.txt', sep=',')
df_txn.columns = list(['Tranx no.', 'Date', 'ID', 'Amount', 'Type', 'Product', 'City', 'State', 'Mode'])

df = pd.merge(df_custs, df_txn, how='inner')

products = sort(df['Product'])
max_count = 0

for i in range(1,len(products)):
	count = 0
	while i < len(products) and products[i] == products[i-1]:
		count += 1
		i += 1
	if count > max_count:
		max_count = count
		max_product = products[i-1]
		
	

# print(df.describe())
print(df.head(5))
print(products)
print(max_product)

