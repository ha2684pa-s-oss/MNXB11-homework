#!/bin/bash
# This script creates a temporary folder for the calculatePI
# application output files and writes some information in it.

echo "Creating temporary folder for output files..."
# Create temporary output directory to save the generated image file and node information
CP_TIMESTAMP=$(date +%s)
DESTINATION=$HOME/tmp.calculatePI/$CP_TIMESTAMP

mkdir -p $DESTINATION

# If the folder was created, enter it, otherwise exit with error
if [ $? -eq 0 ]; then
   cd $DESTINATION
else
   echo "Failed to create temporary folder, exiting..."
   exit 1
fi

# Save computing node hostname and unique ID
echo "Saving node information..."
echo "Running on $(hostname) $(hostid)" > $DESTINATION/nodeinfo.txt

# Start calculation
echo "Starting calculation..."
/projects/hep/fs11/share/mnxb11/bin/calculatePI
