from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from scipy.spatial import distance


def euc_dist(a, b):
    return distance.euclidean(a, b)


class KNN():

    def fit(self, x_train, y_train):
        self.x_train = x_train
        self.y_train = y_train

    def predict(self, x_test):
        predictions = []
        for row in x_test:
            label = self.closest(row)
            predictions.append(label)
        return predictions

    def closest(self, row):
        near_dist = euc_dist(row, self.x_train[0])
        near_index = 0
        for i in range(1, len(self.x_train)):
            dist = euc_dist(row, self.x_train[i])
            if dist < near_dist:
                near_dist = dist
                near_index = i
        return self.y_train[near_index]


iris = datasets.load_iris()
x = iris.data
y = iris.target

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=.5)

classifier = KNN()

classifier.fit(x_train, y_train)

predictions = classifier.predict(x_test)

print accuracy_score(y_test, predictions)
