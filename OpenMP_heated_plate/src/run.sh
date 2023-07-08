#!/bin/bash

#PBS -l walltime=00:05:00
#PBS -m be
#PBS -l select=1
#PBS -A DD-22-67


module intel
module GCC

cd $HOME/heatedplate

export OMP_NUM_THREADS=4

./main 1
