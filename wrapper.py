import os
import subprocess

def run_avida(n, m, u, i):
    subprocess.call(["./avida", "-n" + str(n), "-m" + str(m), "-u" + str(u), "-i" + str(i)], )

N=8
M=2
U=100
print("Running with " + str(N) +  " worlds,  " + str(M) + " meta generations and " + str(U) + " updates.")
for i in range(M):
    run_avida(n=N, m=M, u=U, i=i)

