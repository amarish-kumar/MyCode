import numpy as np
import matplotlib.pylab as plt

x = np.linspace(0, 20, 1000)
y = np.sin(x)

fig = plt.figure(figsize=(8, 4))		# bget an empty fig adn add an axes
ax = fig.add_subplot(1, 1, 1)			# row-col-num
# line plot data on the axes add title, labels and legend, etc.
ax.plot(x, y, 'b-', linewidth=2, label='Sample label')
ax.set_ylabel('y axis label', fontsize=16)
ax.set_xlabel('x axis label', fontsize=16)
ax.legend(loc='best')
ax.grid(True)
fig.suptitle('Sample Plot Title')
fig.tight_layout(pad=1)
fig.savefig('mat5.png', dpi=125)
