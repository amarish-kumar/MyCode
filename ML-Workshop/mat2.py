import matplotlib.pyplot as plt
# from ABC import abstract_method

fig, ax = plt.subplots()
fig, (ax1,ax2,ax3) = plt.subplots(nrows=3,ncols=1,sharex=True)
figsize = (8,4)

for ax in fig.get_axes():
	pass

plt.show()