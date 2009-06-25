# Script to clone 0.xml to make bigger populations

Usage: 
./clone.sh base_0.xml number_of_clones new_0.xml [-j|-r]

Arguments:
   $1 - The original 0.xml
   $2 - Number of times to clone
   $3 - New 0.xml file (ignored with -r option)
   $4 - -j if files are to be joined OR -r if you want region partitioned input files. Otherwise use <import>

Example:
./clone.sh 0_eurace_minimal.xml 2 0_clone2.xml -j

DESCRIPTION

Compiling
Use 'make' to compile in serial, or use 'make parallel' to compile parallel code.

Cloning
This cloning code works with the clone.sh script both in serial or parallel versions of the code.
If the parallel code is used, the cloning algorithm uses multiple processes to create the cloned populations.
After all cloned regions are created, the script can join the files to one file using the -j optional argument.

Agent list
The list of agent names (agent types) to be cloned should be in agent_list.txt, one type name per
line.

The example in test_0.xml and agent_list.txt should help you to
understand what's required of the initial 0.xml.

The code is pretty well commented if you need to change it. If you want
to use the old household cloning (cloning household agents only), edit clone_serial.c and clone_parallel.c to
uncomment the clone_households line and comment out the clone_region line.


