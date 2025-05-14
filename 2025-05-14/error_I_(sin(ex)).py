import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

n, et , es , etr , esr = np.loadtxt("integration(sin(ex)).txt", unpack=True)

fig, ax = plt.subplots()
ax.plot(n, et, '-o', label='Error regla de trapecios')
ax.plot(n, es, '-o', label='Error regla de Simpson')
ax.plot(n, etr, '-o', label='Error regla de trapecios + Richardson')
ax.plot(n, esr, '-o', label='Error regla de Simpson + Richardson')
ax.set_xlabel('n')
ax.set_ylabel('error')
ax.set_xscale('log')
ax.set_yscale('log')
ax.legend()
fig.savefig('integration(sin(ex)).pdf')

print("¡PDF generado correctamente!")
plt.close(fig)