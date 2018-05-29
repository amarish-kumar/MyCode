from sklearn import datasets
from scipy.misc import imread, imresize, bytescale
from sklearn import svm
import numpy as np

digits = datasets.load_digits()
x, y = digits.data, digits.target

clf = svm.SVC(gamma=0.001)
clf.fit(x, y)

img = imread('digit8.jpg')
img = imresize(img, (8, 8))

img = img.astype(digits.images.dtype)
img = bytescale(img, high=16.0, low=0)

x_testData = []
for row in img:
	for col in row:
		x_testData.append(np.sum(col))

array = np.array(x_testData).reshape(1, 64)
print(array.shape)

print(clf.predict(array))
