import numpy as np
import random

class MySGDRegression:
    def __init__(self):
        self.intercept_ = 0.0
        self.coef_ = []

    # simple stochastic GD
    def fit(self, x, y, learningRate = 0.001, noEpochs = 1000):
        self.coef_ = [0.0 for _ in range(len(x[0]) + 1)]    #beta or w coefficients y = w0 + w1 * x1 + w2 * x2 + ...
        # self.coef_ = [random.random() for _ in range(len(x[0]) + 1)]    #beta or w coefficients
        for epoch in range(noEpochs):
            # TBA: shuffle the trainind examples in order to prevent cycles
            for i in range(len(x)): # for each sample from the training data
                ycomputed = self.eval(x[i])     # estimate the output
                crtError = ycomputed - y[i]     # compute the error for the current sample
                for j in range(0, len(x[0])):   # update the coefficients
                    self.coef_[j] = self.coef_[j] - learningRate * crtError * x[i][j]
                self.coef_[len(x[0])] = self.coef_[len(x[0])] - learningRate * crtError * 1

        self.intercept_ = self.coef_[-1]
        self.coef_ = self.coef_[:-1]

    def eval(self, xi):
        yi = self.intercept_  # start from the bias term
        for j in range(len(xi)):
            yi += self.coef_[j] * xi[j]
        return yi

    def predict(self, x):
        yComputed = [self.eval(xi) for xi in x]
        return yComputed

class MySGDRegressionBatch:
    def __init__(self):
        self.intercept_ = 0.0
        self.coef_ = []

    def fit(self, x, y, learningRate=0.001, noEpochs=1000, batch_size=32):
        self.coef_ = [0.0 for _ in range(len(x[0]) + 1)]

        for epoch in range(noEpochs):
            combined = list(zip(x, y))
            random.shuffle(combined)
            x_shuffled, y_shuffled = zip(*combined)
            x_shuffled = list(x_shuffled)
            y_shuffled = list(y_shuffled)

            for i in range(0, len(x), batch_size):
                X_batch = x_shuffled[i:i + batch_size]
                y_batch = y_shuffled[i:i + batch_size]

                gradient_w = np.zeros(len(X_batch[0]))
                gradient_b = 0.0

                for j in range(len(X_batch)):
                    y_pred = self.eval(X_batch[j])
                    error = y_pred - y_batch[j]

                    for k in range(len(X_batch[0])):
                        gradient_w[k] += error * X_batch[j][k]
                    gradient_b += error

                for k in range(len(gradient_w)):
                    self.coef_[k] -= learningRate * gradient_w[k] / len(X_batch)

                self.coef_[-1] -= learningRate * gradient_b / len(X_batch)

        self.intercept_ = self.coef_[-1]
        self.coef_ = self.coef_[:-1]

    def eval(self, xi):
        yi = self.intercept_
        for j in range(len(xi)):
            yi += self.coef_[j] * xi[j]
        return yi

    def predict(self, x):
        yComputed = [self.eval(xi) for xi in x]
        return yComputed
