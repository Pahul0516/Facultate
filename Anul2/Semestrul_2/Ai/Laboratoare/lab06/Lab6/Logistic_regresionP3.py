import numpy as np

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

class MyLogisticRegression:
    def __init__(self, learning_rate=0.01, epochs=1000):
        self.learning_rate = learning_rate
        self.epochs = epochs
        self.weights = None
        self.bias = None

    def fit(self, X, y):
        X = np.array(X)
        y = np.array(y)
        n_samples, n_features = X.shape

        self.weights = np.zeros(n_features)
        self.bias = 0

        for _ in range(self.epochs):
            model = np.dot(X, self.weights) + self.bias
            predictions = sigmoid(model)

            dw = (1 / n_samples) * np.dot(X.T, (predictions - y))
            db = (1 / n_samples) * np.sum(predictions - y)

            self.weights -= self.learning_rate * dw
            self.bias -= self.learning_rate * db

    def predict_proba(self, X):
        model = np.dot(X, self.weights) + self.bias
        return sigmoid(model)

    def predict(self, X):
        return [1 if p >= 0.5 else 0 for p in self.predict_proba(X)]

class MyOvRClassifier:
    def __init__(self):
        self.models = {}
        self.classes = []

    def fit(self, X, y):
        self.classes = np.unique(y)
        for cls in self.classes:
            binary_y = [1 if label == cls else 0 for label in y]
            clf = MyLogisticRegression()
            clf.fit(X, binary_y)
            self.models[cls] = clf

    def predict(self, X):
        X = np.array(X)
        probabilities = {}
        for cls, model in self.models.items():
            probabilities[cls] = model.predict_proba(X)

        preds = []
        for i in range(len(X)):
            best_class = max(self.classes, key=lambda cls: probabilities[cls][i])
            preds.append(best_class)
        return preds
