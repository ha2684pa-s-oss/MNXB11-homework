#!/bin/sh
# This script runs the calculatePI.sh script using the container `mnxb11_al9.latest.sif` with minimum required parameters
# -B mounts the project directory inside the container so that is visible also inside the container
apptainer run -B /projects:/projects /projects/hep/fs11/share/mnxb11/containers/mnxb11_al9.latest.sif ./calculatePI_setup.sh


