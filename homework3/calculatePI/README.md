# Realistic application using container

This folder contains an example of realistic application,
a piece of C++/ROOT code that approximates Pi using a Monte Carlo method
of drawing a circle in a square, counting the dots that end
up inside the circle and multiply them by 4. 

The source code depends on the ROOT framework to run. The system must have
a working ROOT installation to compile and run the code.

For MXNB11 this code must be run inside the course container.

## Folder contents

```
.
├── CMakeLists.txt # cmake config file
├── README.md # This document
├── scripts # Folder containing BASH and SLURM scripts
│   ├── calculatePI_setup.sh # BASH script that configures output folders for calculatePI output and node information files
│   ├── run_in_container_calculatePI.sh # Shell script that runs calculatePI_setup.sh inside the MNXB11 container
│   ├── calculatePI.sbatch # SLURM script to submit run_in_container_calculatePI.sh as a SLURM batch job
│   ├── calculatePI_build.sh # Script that performs the build and copies the executable to a specified location
│   └── build_in_container_calculatePI.sh  # Shell Script that performs the build inside the MNXB11 container. Requires calculatePI_build.sh
└── src # Source code of the pi calculation program
    ├── CMakeLists.txt # cmake configuration
    ├── helper.hpp # helper header to define certain functions
    └── main.cxx # main c++ code,  based on ROOT
```

### `src` folder

You do not have to touch any of the content of this folder.

Contains the actual code that does the computations. The meaning of the
contents will be clearer to you as you progress with your knowledge of C++.

`main.cxx` contains the main program

`helper.hpp` contains certain functions and prints relevant output

`Cmakelists.txt` is used by the build system cmake to compile the program.

### scripts folder

The scripts in the `scripts` folder automate tasks that could be done
manually by a C++ programmer, and they can be used also by people with
no C++ knowledge.

The following is a description of each script:

`calculatePI_setup.sh` is a setup script that performs a few tasks prior
to running the `calculatePI` app. These are:
  - It creates a directory for the output files of `calculatePI`, using a unique timestamp
  - Writes a file `nodeinfo.txt` with information about the computing node where the app is ran
  - Runs the `calculatePI` script inside that directory so that the output files are 
    generated there.

`run_in_container_calculatePI.sh` is a shell script that executes calculatePI_setup.sh
inside the MNXB11 container.

`calculatepi.sbatch` is a SLURM batch script that needs to be fine-tuned for
the homework. Contains the parameters to request resources on computing nodes,
and then runs run_in_container_calculatePI.sh on a node.

`calculatePI_build.sh` does the following:

  1. Takes as input these parameters:
     - the number of data points
     - the destination path of the built binary file
     - a custom build directory
  2. Changes the C++ source code according to the datapoints parameter
  3. Creates a build directory in `build/` if no other directory specified, and compiles the source code.
     The resulting executable is in `build/src/main`
  4. If the destination path is specified, copies the executable there.

`build_in_container_calculatePI.sh` runs `calculatePI_build.sh` inside the MNXB11 container, 
passing the appropriate parameters.

## How to use

This code is only meant to be used via the `scripts` folder.

So make sure to be in the scripts folder to do any of the steps described below.

### 1. Testing on the frontend

#### Test executing the binary

To run the precompiled binary on the frontend, follow the homework instructions.
At the time of writing, the binary is located on COSMOS at 
`/projects/hep/fs11/share/mnxb11/bin/calculatePI`.

To run the script enter this in the terminal:

`/projects/hep/fs11/share/mnxb11/bin/calculatePI`

This should show an error since the required libraries are not present on COSMOS:

```shell
$ /projects/hep/fs11/share/mnxb11/bin/calculatePI 
/projects/hep/fs11/share/mnxb11/bin/calculatePI: error while loading shared libraries: libCore.so: cannot open shared object file: No such file or directory
```

In order to run the application for testing, you can use the `startmnxb11container.sh` script:

`startmnxb11container.sh /projects/hep/fs11/share/mnxb11/bin/calculatePI`

Note that the precompiled binary is intentionally time consuming and slow.
If you experience that the frontend is becoming slow, kill the process
by pressing CTRL+C .

To test the setup script, run

`startmnxb11container.sh ./calculatePI_setup.sh`

This will create a folder that contains some information about the node
where the job runs and then will run the app.
Note that also in this case you may be forced to exit with CTRL+C .
Read the BASH code to guess where the folder could be. 
At least the file nodeinfo.txt should be created there.

The container script `run_in_container_calculatePI.sh` is meant to 
replace `startmnxb11container.sh` for a more specific use just for this code.
This will do exactly the same as the previous command, just automated
in a BASH script. Test by executing:

```shell
./run_in_container_calculatePI.sh
```

#### Optional: Test compiling the code

To test the compilation script on the frontend, run

`startmnxb11container.sh ./calculatePI_build.sh`
The default is 1000000 iterations.
This should generate a `calculatePI` executable in the current directory.

A heavier computation with more iterations can be compiled using the script
`build_in_container_calculatePI.sh` which is a _wrapper script_ that 
automatically runs the compilation script inside the container and 
configures the build script to change the code with a larger number of iterations (300000000)
The resulting binary will appear in the current directory also as `calculatePI`.
Note that running this after the other script will overwrite any existing
`calculatePI` executable without warning.
This script has been used to generate the current binary located on COSMOS in
`/projects/hep/fs11/share/mnxb11/bin/calculcatePI`

Run with:

```shell
./build_in_container_calculatePI.sh
```

### 2. Worker node execution or compilation

#### 2.1 Running on a worker node

To run on a worker node using SLURM:

  1. edit and modify the provided sbatch script `calculatepi.sbatch`
  2. execute the command `sbatch calculatepi.sbatch`
  3. check the slurm stdout file
  4. check the contents of the folder generated by `calculatePI_setup.sh`

#### 2.2 Optional: Compilation on a worker node

To compile on a worker node:

  1. edit and modify the provided sbatch script `calculatepi.sbatch`  
    1.1. Substitute the script `run_in_container_calculatePI.sh` with `build_in_container_calculatePI.sh`
  2. execute the command `sbatch calculatepi.sbatch`
  3. check the slurm stdout file
  4. The resulting binary `calculatePI` should appear in the folder where you launched `sbatch`

### 3. Inspecting results

If the app is ran in the frontend, you will see the execution output on the screen.

If the app is run in SLURM, the code output will be in the `slurm-<jobidcode>.out` file
as during the tutorial. You can change the name of the SLURM output file in `calculatepi.sbatch` if you wish.

The execution results will be an image of the points used to determine pi, `pi_hit_miss.png`
that can be found in the current folder if the program is run direcly.

If the script `calculatePI_setup.sh` was used, then the image will be found
in the folder created by `calculatePI_setup.sh` along with the information file `nodeinfo.txt`

## Profiling required time and memory:

**Profiling** is the action of trying to understand how many resources does
a piece of software require to run.

You can use the GNU `time` application to profile how much time and memory you need 
to request on a worker node. 

For example run the program on the frontend with:

```shell
/usr/bin/time -v run_in_container_calculatePI.sh
```

wait for the output (it may take long time!!)

`GNU time` writes its results to standard error, so if you want to write
the output to a file and don't want to see it on the terminal, you
could run in the background and pipe standard output and error to a file:

```shell
/usr/bin/time -v run_in_container_calculatePI.sh &> GNUtimeresults.txt &
```

Once you have the output on the terminal or inside the `GNUtimeresults.txt` file,
search for the following strings:

`Elapsed (wall clock) time (h:mm:ss or m:ss):` average time required by the program  
`Maximum resident set size (kbytes):` maximum memory required to run the program

These numbers can differ depending on how busy the frontend is.

Once you get these numbers, you will need to try them in `calculatepi.sbatch` 
to be sure that it will run on a worker node. Maybe you need a bit more,
maybe a bit less. Try!

NOTE: there is a builtin BASH `time` command that does similar things, but not what we need!
be sure to use `/usr/bin/time` application instead!
