import os
import subprocess

def run_avida():
    print("starting avida")
    subprocess.call(["./avida"])
    print("stopping avida")

for i in range(500):
    run_avida()