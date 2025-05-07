import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

n, nr = np.loadtxt("norm_twins_prime.txt", unpack=True)

fig, ax = plt.subplots()
ax.plot(n, nr, '-o', label='norma de la nth pareja')
ax.set_xlabel('n')
ax.set_ylabel('norma')
ax.legend()
fig.savefig('norm_twins_prime.pdf')

print("¡PDF generado correctamente!")
plt.close(fig)
