#!/bin/bash

#Set directories:
BASE=$PWD
POP_GUI_DIR='/cygdrive/d/Docs/EURACE/X-models/SVN/Pop_GUI'
SIM_DIR='/cygdrive/d/Docs/EURACE/X-models/SVN/eurace/EURACE_Model/branches/Integrated_Model'

#CLONE_SCRIPT_DIR='/cygdrive/d/Docs/EURACE/X-models/SVN/eurace/utils/cloning'
#PREPARTITION_DIR='/cygdrive/d/Docs/EURACE/X-models/SVN/eurace/utils/prepartitioning'
#JOIN_DIR='/cygdrive/d/Docs/EURACE/X-models/SVN/eurace/utils/join'

CLONE_SCRIPT_DIR='../cloning'
PREPARTITION_DIR='../prepartitioning'
JOIN_DIR='../join'

#Set parameters
NR_NODES=4
NR_ITS=10
NR_CLONES=2

#Create standard pop from PopGUI (1 region)

#Add markers:
#python $POP_GUI_DIR/instantiate.py -r 0.pop 0_markers.xml

#Clone regions:
cd $CLONE_SCRIPT_DIR
bash clone.sh $BASE/0_markers.xml $NR_CLONES $BASE/0_cloned.xml -j
cd -

#Partitioning:
#cd $PREPARTITION_DIR
#python prepartition_statefile.py $BASE/0_cloned.xml $BASE/0_partition.xml region_id name $NR_NODES
#python prepartition_statefile.py $BASE/0.xml $BASE/0_partition.xml region_id name $NR_NODES
#cd -

#Simulation:
#cd $SIM_DIR
#mpiexec -n $NR_NODES $SIM_DIR/main $NR_ITS 0_partition.xml -r -f 20
#cd -

#Joining output:
#cd $JOIN_DIR
#bash join.sh $SIM_DIR/its $NR_NODES
#cd -
