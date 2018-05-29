import numpy as np
import matplotlib.pylab as plt

# changing sharex to true will use the same x axis
fig, ax = plt.subplots(figsize=(8,4))

# plot some lines
x1 = np.linspace(0, 100, 20)
x2 = np.linspace(0, 100, 20)
x3 = np.linspace(0, 100, 20)
y1 = np.sin(x1)
y2 = np.cos(x2)
y3 = np.tan(x3)

ax.plot(x1,y1,label='sin')
ax.plot(x2,y2,label='cos')
ax.plot(x3,y3,label='tan')

# add grid, legend, title and save
ax.grid(True)
ax.legend(loc='best',prop={'size':'large'})

fig.suptitle('A simple multi axis line plot')
fig.savefig('mat7.png', dpi=125)