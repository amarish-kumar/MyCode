import pandas as pd

admData = pd.read_csv('admissions_mapping.csv')
dbData = pd.read_csv('diabetic_data.csv')

data = pd.merge(admData, dbData, on='admission_type_id', how='inner')
# print(data)

data = pd.merge(admData, dbData, on='admission_type_id', how='outer')
# print(data)

count = [0, 0, 0, 0, 0, 0, 0, 0]
m = f = 0
for x in range(len(data['admission_type_id'])):
    count[data['admission_type_id'][x] - 1] += 1
    if data['gender'][x] == 'Male':
        m += 1
    else:
        f += 1

print(count)
print(m)
print(f)
