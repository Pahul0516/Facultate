import numpy as np

class LogisticRegressionScratch:
    def __init__(self, alpha=0.09, iterations=1000):
        self.alpha = alpha
        self.iterations = iterations
        self.theta = None

    def sigmoid(self, z):
        return 1 / (1 + np.exp(-z))

    def compute_cost(self, X, y):
        m = len(y)
        h = self.sigmoid(np.dot(X, self.theta))
        cost = -1 / m * np.sum(y * np.log(h) + (1 - y) * np.log(1 - h))
        return cost

    def gradient_descent(self, X, y):
        m = len(y)
        cost_history = []

        for i in range(self.iterations):
            h = self.sigmoid(np.dot(X, self.theta))
            gradient = (1 / m) * np.dot(X.T, (h - y))
            self.theta -= self.alpha * gradient

            cost_history.append(self.compute_cost(X, y))

        return cost_history

    def fit(self, X, y):
        X = np.column_stack([np.ones(X.shape[0]), X])
        self.theta = np.zeros(X.shape[1])
        cost_history = self.gradient_descent(X, y)
        return cost_history

    def predict(self, X):
        X = np.column_stack([np.ones(X.shape[0]), X])
        y_pred_prob = self.sigmoid(np.dot(X, self.theta))
        y_pred = [1 if p >= 0.5 else 0 for p in y_pred_prob]
        return np.array(y_pred)

    def evaluate(self, X, y):
        y_pred = self.predict(X)
        accuracy = np.mean(y_pred == y)
        return accuracy