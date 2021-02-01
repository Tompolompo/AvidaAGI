import os
import subprocess

def run_avida(m):
    subprocess.call(["./avida", "-n10", "-m" + str(m), "-u100"], )

for i in range(3):
    run_avida(i)

