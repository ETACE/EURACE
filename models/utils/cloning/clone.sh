#!/bin/bash
#
# Script to clone 0.xml to make bigger populations
#
# Arguments:
#   $1 - The original 0.xml
#   $2 - Number of times to clone
#   $3 - New 0.xml file
#   $4 - -j if files are to be joined. Otherwise use <import>

if [ -e clone_parallel ]; then
  echo "Will do parallel cloning"
  echo
elif [ -e clone_serial ]; then
  echo "Will do serial cloning"
  echo
else
  echo
  echo "Neither clone_serial nor clone_parallel are available to do the cloning."
  echo "Run \"make serial\" or \"make parallel\" (requires MPI) to create one of these programs."
  echo
  exit 0
fi

# Work out the increment to add to agent ids for each clone
increment=`grep "<xagent" "$1" | wc -l`

echo "Initial 0.xml contains $increment agents"

# Link initial 0.xml to fixed file so clone_* can read it
ln -sf $1 0.xml

# If clone_parallel exists and is executable use that with mpirun
# otherwise run clone_serial many times
let "times = $2 + 1"
if [ -x clone_parallel ]; then
  mpirun -np $times ./clone_parallel $increment
elif [ -x clone_serial ]; then
  for i in `seq 0 $2`
  do
    echo "Clone iteration $i"
    ./clone_serial $increment $i
  done
fi

# Copying first set of cloned agents to new 0.xml but remove last </states> line
sed -e '/<\/states>/d' < 0_0.xml > $3

# Fix the <total_regions> tag
let "num_regions = $2 + 1"
sed "s/<total_regions>[0-9]<\/total_regions>/<total_regions>$num_regions<\/total_regions>/g" $3 > tmp
mv tmp $3

# If -j option supplied then add other data
if [ x$4 != "x" ] && [ $4 = "-j" ]; then
  for i in `seq 1 $2`
  do
    echo "Add cloned data $i"
    cat 0_$i.xml >> $3
  done
  rm 0_[0-9]*.xml
  echo New 0.xml contains `grep "<xagent" "$3" | wc -l` agents
else
  echo "Adding <import> sections"
  echo "<imports>" >> $3
  num_agents=`grep "<xagent" "$3" | wc -l`
  for i in `seq 1 $2`
  do
    echo "<import>
<location>./0_$i.xml</location>
<format>xml</format>
<type>agent</type>
</import>" >> $3
    let "num_agents = $num_agents + `grep "<xagent" 0_$i.xml | wc -l`"
  done
  echo "</imports>" >> $3
  echo New 0.xml contains $num_agents agents
  rm 0_0.xml
fi

# Put the final tag back
echo "</states>" >> $3



rm 0.xml
