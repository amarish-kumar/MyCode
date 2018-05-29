import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0,20,1000)
y = np.sin(x)
plt.plot(x,y,label="My First App")
plt.title("My Simple Data Display")
plt.xlabel("X-Axis")
plt.ylabel("Y-Axis")
plt.grid(True)

plt.figtext(0.995,0.01,'Sine',ha='right',va='bottom')
plt.legend(loc='best',framealpha=0.5, prop={'size':'small'})
plt.tight_layout(pad=1)

plt.savefig("mat1.png")
plt.show()
plt.close()
