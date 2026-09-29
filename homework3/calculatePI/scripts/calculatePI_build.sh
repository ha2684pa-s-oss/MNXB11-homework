#!/bin/bash

# This wrapper script builds the binary needed to calculate PI.

# CODEPARAM contains the N value to be injected in the C++ code 
# before building.
# 1e6 is the default.
# 3e8 makes a long enough generation happen.
# Can be changed with the first parameter.
CODEPARAM=${1:-1e6}

# Extracts the full path of this script
SCRIPTPATH=$(realpath $0)
echo "SCRIPTPATH is $SCRIPTPATH"
# extracts just the directory where this script is
SCRIPTDIR=$(dirname $SCRIPTPATH)
# changes to one level up
cd $SCRIPTDIR/..
# saves the base directory for the source code
BASEDIR=$(pwd)
echo "BASEDIR is $BASEDIR"

# Path to Cmake build directory, can be passed as third parameter
BUILDPATH=${3:-$BASEDIR/build}
# Path where executable will be generated, obtained looking
# at the cmake scripts
EXECPATH=$BUILDPATH/src/main
echo "BUILD path is $BUILDPATH"

# Destination dir for the binary. 
# Default is the path where this script is launched.
# Can be changed using the second parameter
DESTDIR=${2:-$SCRIPTDIR}
# Path of the final binary
DESTEXEC=$DESTDIR/calculatePI

usage(){
  echo ""
  echo "This script builds the calculatePI binary from sources"
  echo "Usage:"
  echo "  $0 <precision> <destination binary path> <build path>"
  echo "     <precision> is a number in exponential notation."
  echo "          Default: 1e6"
  echo "     <destination binary path> is where the executable will be placed."
  echo "          Default: $DESTEXEC"
  echo "     <source code path> is where the build files should go"
  echo "          Default: $BUILDPATH"
  echo ""
}

# Print some help including defaults if requested
if [ "$1" == '-h' ] || [ "$1" == '--help' ]; then
   usage
   exit
fi

# This is a trick to change the C++ code on the fly, since
# the provided code is not smart enough to accept command
# line parameters. Definitely an hackish way of developing!
# But showcases the power of string handling in BASH.
echo "Modifying source code with parameter: $CODEPARAM"
echo "A backup if the original code will be in $BASEDIR/src/main.cxx.backup"
sed -i'.backup' 's/  constexpr long long N = .*;/  constexpr long long N = '"$CODEPARAM"';/' $BASEDIR/src/main.cxx

# Create the build path directory, skip if it already exists
echo "Creating directories and compiling"
if [[ ! -d $BUILDPATH ]]; then 
   echo "Creating build path"
   mkdir $BUILDPATH
else
   echo "Build path already existing"
fi

# Move to the build path
cd $BUILDPATH

# Build code according to developer's instructions
echo "Building code..."
make clean
cmake $BUILDPATH/..
make

if [[ $? -ne 0 ]]; then
   echo "Compilation failed, see compilation errors. Exiting..."
   exit 1
fi

# Show path of executed binary and copy over current directory
echo "Built executable $EXECPATH"
echo "Copying executable at destination as $DESTDIR/calculatePI"
cp $EXECPATH $DESTEXEC

if [ $? -ne '0' ]; then  
   echo "Failed to copy $EXECPATH to $DESTEXEC"
   exit 1
fi
