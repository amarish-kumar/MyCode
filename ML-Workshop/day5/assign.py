import pandas as pd
import matplotlib.pylab as plt

df = pd.read_csv('ARVIND.NS.csv', sep=',')
df['Change'] = df['High'] - df['Low']
# print(df.head())
df['mavg'] = pd.rolling_mean(df['Adj Close'], len(df.columns))
print(df.tail(10))

df['Date'] = pd.to_datetime(df['Date'])

x = df['Date']
y1 = df['Adj Close']
y2 = df['mavg']

plt.plot(x, y1, label='Adj Close')
plt.plot(x, y2, label='mavg')
plt.show()
