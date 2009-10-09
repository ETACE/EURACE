#!/bin/bash

#Set directories:
BASE=$PWD
POP_GUI_DIR='/media/DOCS/Docs/EURACE/X-models/SVN_linux/guis/popgui-trunk'
SIM_DIR='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/its'

#CLONE_SCRIPT_DIR='~/cloning/utils/cloning'
#PREPARTITION_DIR='~/cloning/utils/prepartitioning'
#JOIN_DIR='~/cloning/utils/join'

CLONE_SCRIPT_DIR='../cloning'
PREPARTITION_DIR='../prepartitioning'
JOIN_DIR='../join'

#Set parameters
NR_NODES=4
NR_ITS=10
NR_CLONES=2

#Create standard pop from PopGUI (1 region)

#Standard command line instantiation:
python $POP_GUI_DIR/popcmdline.py $SIM_DIR/0.pop $SIM_DIR/0_standard.xml
#python $POP_GUI_DIR/popcmdline.py $SIM_DIR/0_bench_July_24_large.pop $SIM_DIR/0_bench_July_24_large.xml

#Add markers:
#python $POP_GUI_DIR/instantiate.py -r $SIM_DIR/0.pop $SIM_DIR/0_markers.xml

#Clone regions:
#cd $CLONE_SCRIPT_DIR
#bash clone.sh $SIM_DIR/0_markers.xml $NR_CLONES $SIM_DIR/0_cloned.xml -j
#cd -

#Partitioning:
#cd $PREPARTITION_DIR
#python prepartition_statefile.py $SIM_DIR/0_cloned.xml $SIM_DIR/0_partition.xml region_id name $NR_NODES
#python prepartition_statefile.py $SIM_DIR/0_standard.xml $SIM_DIR/0_partition.xml region_id name 4
#cd -


#Simulation:
#cd $SIM_DIR/..
#mpiexec -n $NR_NODES $SIM_DIR/main $NR_ITS 0_partition.xml -r -f 20
#cd -

#Joining output:
#cd $JOIN_DIR
#bash join.sh $SIM_DIR/its $NR_NODES
#cd -
