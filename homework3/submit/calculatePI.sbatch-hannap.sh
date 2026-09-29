#!/bin/sh

#SBATCH -J "MNXB11 Pi homework" # job name
#SBATCH --time=00:10:00 # runtime
#SBATCH --mem=30G # memory
#SBATCH --output=calcPi-%j.out # job output

# Launch the calculatePI.sh application script using the container script
run_in_container_calculatePI.sh
