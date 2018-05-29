from operator import itemgetter
d = {'asish':1, 'dinesh': 3 ,'amit':2}
# print(d.get('a'))
# print(d.get('b'))

a = sorted(d.items(), key=itemgetter(1, 0), reverse=False)
print(a)
