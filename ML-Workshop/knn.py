from numpy import *
from operator import itemgetter
from sklearn.metrics.pairwise import euclidean_distances


def createDataset():
    group = array([[1.0, 1.1], [1.0, 1.0], [0, 0], [0, 0.1]])
    labels = ['A', 'A', 'B', 'B']
    return group, labels


def classify(p_data, dataset, labels, k):
    # dataSetSize = dataset.shape[0]
    # diffmat = tile(p_data, (dataSetSize, 1)) - dataset
    # sqDiffMat = diffmat**2
    # sqDistance = sqDiffMat.sum(axis=1)		# axis=0 gives sum of column
    # distance = sqDistance**.5
    distance = euclidean_distances(dataset, p_data)
    sortMetDistances = distance[:,0].argsort()
    classcount = {}
    for i in range(k):
        votIlabel = labels[sortMetDistances[i]]
        classcount[votIlabel] = classcount.get(votIlabel, 0) + 1
        sortedClassCount = sorted(
            classcount.items(), key=itemgetter(1), reverse=True)

        return sortedClassCount[0][0]
