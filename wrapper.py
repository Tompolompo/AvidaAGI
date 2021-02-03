import subprocess
import time
import numpy as np

def run_avida(n, m, u, i):
    subprocess.call(["./avida", "-n" + str(n), "-m" + str(m), "-u" + str(u), "-i" + str(i)], )

<<<<<<< HEAD
N=50
M=20
U=4
print("Running with " + str(N) +  " worlds,  " + str(M) + " meta generations and " + str(U) + " updates.")
=======
N=12
M=40
U=2500
print("Running with " + str(N) +  " worlds, " + str(M) + " meta generations and " + str(U) + " updates.")

times = []
>>>>>>> c35c0c9512d3b0e5cf66465d7a9331baffb0d91e
for i in range(M):
    start = time.perf_counter()
    run_avida(n=N, m=M, u=U, i=i)
    times.append(time.perf_counter()-start)
    print("Tot elapsed: " + str(round(sum(times)/3600, 2)) + " h, remaining: " + str(round(np.mean(times)/3600*(M-i),2)) + " h")

