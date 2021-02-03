import subprocess

def run_avida(n, m, u, i):
    subprocess.call(["./avida", "-n" + str(n), "-m" + str(m), "-u" + str(u), "-i" + str(i)], )

N=50
M=20
U=4
print("Running with " + str(N) +  " worlds,  " + str(M) + " meta generations and " + str(U) + " updates.")
for i in range(M):
    run_avida(n=N, m=M, u=U, i=i)

