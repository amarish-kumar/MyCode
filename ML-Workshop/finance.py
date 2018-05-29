import pandas as pd

xls = pd.ExcelFile('kk.xlsx')
df1 = pd.read_excel(xls, 'Sheet1')
df2 = pd.read_excel(xls, 'Sheet2')

print(pd.merge(df1, df2, how='inner'))
