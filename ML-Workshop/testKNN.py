import knn
from numpy import *

dataset, labels = knn.createDataset()
print(dataset)
print(labels)
predict = array([[1,1.1]])
result = knn.classify(predict, dataset, labels, 3)
print (result)