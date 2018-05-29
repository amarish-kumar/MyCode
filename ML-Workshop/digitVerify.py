import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn import svm

digits = datasets.load_digits()
print(digits.images[0])

clf = svm.SVC(gamma=0.001)

x, y = digits.data[:-1], digits.target[:-1]
clf.fit(x, y)
plt.imshow(255*digits.images[-6], cmap=plt.cm.gray)
plt.show()
print(clf.predict(x))

