#%% Plotting Avida meta evolution training results
import numpy as np
import matplotlib.pyplot as plt

resultfile = "output/testresults.data"
with open(resultfile) as file:
    for line in file:
        if line.startswith("best_fitness"):
            best_fitness = line.split(':')[1][:-3]

best_fitness = np.array(best_fitness.split(',')).astype(np.float)

plt.plot(best_fitness)
plt.xlabel("Generation")
plt.ylabel("Fitness")




# %%
