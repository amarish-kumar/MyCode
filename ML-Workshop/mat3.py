import numpy as np
import matplotlib.pyplot as plt

x = np.arange(5)
y = (20,35,30,35,27)

plt.bar(x,y)

# need to close the fig using show() or close(), or any follow up plot cmds will use same fig.
# plt.show()
plt.scatter(x,y)
plt.show()

