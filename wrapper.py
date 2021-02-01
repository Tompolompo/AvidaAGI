import os
import subprocess

def run_avida(n, m, u):
    subprocess.call(["./avida", "-n" + str(n), "-m" + str(m), "-u" + str(u)], )

N=8
M=10
U=200
print("Running with " + str(N) +  " worlds, " + str(M) + " meta generations and " + str(U) + " updates.")
for i in range(M):
    run_avida(n=N, m=i, u=U)

