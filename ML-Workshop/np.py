import numpy as np

a = np.ones((3, 3), dtype=np.int64)
b = np.full((3, 3), 7)
c = np.eye(3)
d = np.random.random((3, 3))
e = np.array([[0, 1, 2.0], [0, 0, 0], (1+1j, 3., 2.)])
x = e+2+3j

# linspace() will create arrays with a specified number of items which are
# spaced equally between the specified beginning and end values

j = np.linspace(2., 4., 5)

# indices() will create a set of arrays stacked as a one-higher
# dimensioned array, one per dimension with each representing variation
# in the dimension

k = np.indices((2, 2))

a1 = np.array([[1, 2], [3, 4]])
a2 = np.array([[1, 2], [3, 4], [5, 6]])

p = 'madam'


print(a)
print(b)
print(c)
print(d)
print(e)
print(x)
print(j)
print(k)
print(a1)
print(a1[[0, 1], [0, 1]])
print(a1[[0, 1], [1, 1]])
print(a2 > 2)
print(a2[a2 > 2])
print(p == p[::-1])     # palindrome

x = np.array([[1, 2], [3, 4]])
y = np.array([[5, 6], [7, 8]])
a = np.array([9, 10])
b = np.array([11, 12])

print(a.dot(b))
print(np.dot(a, b))
print(x.dot(y))

# Brodcasting enables arithmetic operations to be performed
# between different shaped arrays.

a = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
v = np.array([1, 0, 1])
# create an empty matrix with the same shape as a
b = np.empty_like(a)
# Add the vector b to each row of the matrix x with an explicit loop

for i in range(3):
    b[i, :] = a[i, :] + v
    print b

# Compute outer product of vectors
# v has shape(3,)
v = np.array([1, 2, 3])
# w has shape(2,)
w = np.array([4, 5])
# to compute an outer product, we first reshape v to be a column vector
# of shape (3, 1); we can then brodcast it against w to yeild an output
# of shape (3, 2), which is the outer product of v and w:
print(np.reshape(v, (3, 1))*w)
