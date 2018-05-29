import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 10, .1)
y = 1 + (x * 2) + (np.random.normal(0, 1, len(x)) * 5)
# print(y)

mx = x.mean()
my = y.mean()
temp = x - mx
c1 = np.sum(temp * (y - my) / np.sum(temp**2))
c0 = my - c1 * mx
x2 = [0, 10]
y2 = [c0 + c1 * 0, c0 + c1 * 10]
dpi = 100
plt.figure(figsize=(800 / dpi, 800 / dpi), dpi=dpi)
plt.scatter(x, y, color='r', s=20)
plt.plot(x2, y2, color='b', linewidth=2)
plt.axes([0, 10, 5, 30])
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Linear Regression')
plt.show()
