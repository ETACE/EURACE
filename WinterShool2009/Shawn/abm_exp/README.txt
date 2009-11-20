THE MODEL:
----------

This model attepts to simulate the ABM experiement as presented in the introduction slide of ABM.
It is currently simulating RULE 1 where we expect the agents to just move about in the simulation space.
Uncomment the lines after the commented RULE 2 block to simulate RULE 2, where agents will attract each other
and the group 'implodes'.


INITIAL DATA:
-------------

To generate the initial data, use the init_start_state.py in its/

  cd its
  ./init_start_state 400 400 30 1


RUNNING:
--------

Just like any other FLAME simulation:

  ./main 500 its/0.xml


VISUALISATION:
--------------

There is a (badly hacked) java application in percovis that can be used to visualise the simulation.

The percovis/ directory needs some setting up before you run it the first time

a) The code must be compiled before first run. 
b) It expects the results to be in an its/ directory within the same path. Easiest would be to create
   a symbolic link to the actual results directory. 

In other words, if it is the first time you are using the program :

  cd percovis
  javac *.java
  ln -s ../its .

To launch the visualisation, you need to tell the program the number of iterations to process:
  
  java Percovis 500

Press "a" to start the simulation. The printout on the console will list other possible options.

