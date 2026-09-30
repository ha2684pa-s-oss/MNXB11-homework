#!/bin/sh


# dummy waste script
#SBATCH -J "WASTED" # job name
#SBATCH --time=00:15:00 # runtime
#SBATCH --mem=32G # memory
#SBATCH --output=calcPi-%j.out # job output

sleep 600 # job runs for 10 min
