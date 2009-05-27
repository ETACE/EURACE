# Script to clone 0.xml to make bigger populations
Usage: 
./clone_parallel base_0.xml number_of_clones new_0.xml -j

Arguments:
   $1 - The original 0.xml
   $2 - Number of times to clone
   $3 - New 0.xml file
   $4 - -j if files are to be joined. Otherwise use <import>

Example:
./clone_parallel 0_eurace_minimal.xml 2 0_clone2.xml -j

DESCRIPTION
Use make to compile in serial, or 'make parallel' to compile parallel code.

This cloning code works with the clone.sh script both in serial or parallel versions of the code.

If the parallel code is used, the cloning algorithm uses multiple processes to create the cloned populations.
After all cloned regions are created, the script can join the files to one file using the -j optional argument.

The list of agent names (agent types) to be cloned should be in agent_list.txt, one per
line.

The example in test_0.xml and agent_list.txt should help you to
understand what's required of the initial 0.xml.

The code is pretty well commented if you need to change it. If you want
to use the old household cloning (cloning household agents only), edit clone_serial.c and clone_parallel.c to
uncomment the clone_households line and comment out the clone_region line.


