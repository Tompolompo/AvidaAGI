import subprocess
import time
import numpy as np

def run_avida(n, m, u, i):
    subprocess.call(["./avida", "-n" + str(n), "-m" + str(m), "-u" + str(u), "-i" + str(i)], )

N=30
M=30
U=40000
print("Running with " + str(N) +  " worlds, " + str(M) + " meta generations and " + str(U) + " updates.")

times = []
for i in range(0,M):
    start = time.perf_counter()
    run_avida(n=N, m=M, u=U, i=i)
    times.append(time.perf_counter()-start)
    print("Tot elapsed: " + str(round(sum(times)/3600, 2)) + " h, remaining: " + str(round(np.mean(times)/3600*(M-i),2)) + " h")

