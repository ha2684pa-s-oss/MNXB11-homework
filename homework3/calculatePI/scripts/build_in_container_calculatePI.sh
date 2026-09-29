#!/bin/sh
# This script launches the course container and builds calculatePI inside it

# These commands below run the build script using the container `mnxb11_al9.latest.sif` with minimum required parameters
# -B mounts the project directory inside the container so that is visible also inside the container
# One can add parameters to the application build script by adding them at the end of the line
# Example: apptainer run -B /projects:/projects /projects/hep/fs11/share/mnxb11/containers/mnxb11_al9.latest.sif ./calculatePI_build.sh 1e9 path-to-outputfile path-to-sources

# Passing the parameter '3e8' here to increase job duration.
# /tmp/ will contain the generated binary file, see output messages at the end of the compilation
apptainer run -B /projects:/projects /projects/hep/fs11/share/mnxb11/containers/mnxb11_al9.latest.sif ./calculatePI_build.sh 3e8 /tmp/ 

