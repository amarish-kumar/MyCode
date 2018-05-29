import pandas as pd
from pylab import *

data = {'sid': [101, 102, 103, 104]
        , 'name': ['Amit', 'Sumit', 'Dinesh', 'Hema']
        , 'Gender': ['M', 'M', 'M', 'F']
        , 'Marks': [300, 382, 399, 201]}

df = pd.DataFrame(data)
df["Total %"] = ((df['Marks']/400)*100)
print(df)
print(df.describe)
print(df.head())
print(df.head(2))
print(df.tail(2))
print(df['name'])
print(df.Marks.hist())
print(show())
print(legend())

df2 = pd.Series(range(5))
print(df2)

# Index in a series can be specified and using the index we can fetch its
# corresponding value.

series = pd.Series(range(1, 10), index=[1, 2, 3, 4, 5, 6, 7, 8, 10])
print(series)

print(data['name'][1])

# Data can be filtered using conditions.
# pandas can accommodate incomplete data. Incomplete data is replaced with
# "NaN" and "NaN" value is not an issue in arithmetic operations. Unlike in
# NumPy ndarray, data is automatically aligned.

# series = pd.Series([1:10, 2:20, 3:30], index = [1, 2, 3, 4])
# print(series)

# len gives number of rows

print(len(data))
print(len(df.columns))

# df.open.Hist()

# irow() func lets you grabs the ith row from a DataFrame (starting from 0)

# print(data.irow(1))

# selecting rows fo interest from a dataframe. In addition to strings,
# the dictionary syntax accepts things like this:
# we can apply filters again on Hi_Volume gives more than one row as output.
# Multiple conditions can also be checked at a time.

# volume = data[data.ID == 400002]
# volume = data[data.Occupation == 'Writer']
