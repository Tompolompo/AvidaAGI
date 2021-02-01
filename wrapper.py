import os
import subprocess

def run_avida(n, m, u):
    subprocess.call(["./avida", "-n" + str(n), "-m" + str(m), "-u" + str(u)], )

N=8
M=2
U=1000
for i in range(M):
    print("Running with " + str(N) +  " worlds,  " + str(M) + " meta generations and " + str(U) + " updates.")
    run_avida(n=N, m=i, u=U)

