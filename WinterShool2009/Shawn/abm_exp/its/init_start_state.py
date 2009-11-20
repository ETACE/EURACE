#!/usr/bin/env python
# $Id: init_start_state.py 1613 2009-03-25 14:38:18Z lsc $
# 
# Copyright (c) 2009 STFC Rutherford Appleton Laboratory 
# Author: Lee-Shawn Chin 
# Date  : Nov 2009
#
# Description:
#    Quick hack to create start states (0.xml) needed by the ABM_EXP model
#
import re
import os
import sys
from math import pi
from random import randint, random

outfile = "0.xml"

# We expect 4 input arguments
if len(sys.argv) != 5:
    print >> sys.stderr, ""
    print >> sys.stderr, "Usage: %s <width> <height> <agent_count> <step_size>" % sys.argv[0]
    print >> sys.stderr, """
More info:
   <width> and <height> will determine the size of simulation space in which
   agents will be randomly placed in.

   <agent_count> specifies the number of agents to initialise.

   <step_size> determines the size of each step taken by agents
""" 
    sys.exit(1)
#/end if

width    = int(sys.argv[1])
height   = int(sys.argv[2])
acount   = int(sys.argv[3])
stepsize = float(sys.argv[4])


if acount < 5:
    print >> sys.stderr, "Error: There must be at least 5 agents"
    sys.exit(1)
#/end if
    
if width < (2*acount) or height < (2*acount):
    print >> sys.stderr, "Error: width/height must be at least double the agent count"
    sys.exit(1)
#/end if

# Open file and write preamble
print "Writing to file %s ... " % outfile,
file = open(outfile, "w")
file.write("""<states>
    <itno>0</itno>
    <environment>
        <step_size>%f</step_size>
        <width>%d</width>
        <height>%d</height>
    </environment>
    """ % (stepsize, width, height))

# write out agent data
for id in xrange(0,acount):
    
    x = float(randint(1, width - 1))
    y = float(randint(1, height - 1))
    dir = random() * 2 * pi

    friend_1 = id
    while friend_1 == id: 
        friend_1 = randint(0,acount - 1)

    friend_2 = id
    while friend_2 == id or friend_2 == friend_1: 
        friend_2 = randint(0, acount - 1)
    
    # write agent values to file
    file.write("""
    <xagent>
        <name>person</name>
        <id>%d</id>
        <x>%.2f</x>
        <y>%.2f</y>
        <direction>%f</direction>
        <friend_1>%d</friend_1>
        <friend_2>%d</friend_2>
    </xagent>
""" % (id, x, y, dir, friend_1, friend_2))

# End XML file and close
file.write("</states>\n")
file.close();

print "DONE"

