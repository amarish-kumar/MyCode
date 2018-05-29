import pandas as pd
from numpy import set_printoptions
from sklearn.preprocessing import MinMaxScaler

name = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pred', 'age', 'class']
df = pd.read_csv('indians-diabetes.data', sep=',', names=name)


array = df.values

# seperate array into input and output components.
x = array[:,0:8]
y = array[:,8]
scaler = MinMaxScaler(feature_range=(0,1))
rescaledX = scaler.fit_transform(x)

maxX = max(df['preg'])
minX = min(df['preg'])
std = (df['preg'][0] - minX) / (maxX - minX)
print(std)
# scaled = std * (1-0) + 0

# summarize transformed data
set_printoptions(precision=3)
print(rescaledX[0:5,:])