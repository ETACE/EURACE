#!/bin/bash

######### CREATION OF latex document ###############################################
# Script to create a latex document summarizing the plots in a folder hierarchy
# - Create folders ./plots/duration_x/intensity_y/frequency_z
# - Copy PNG plots to these folders
# - Generate a plot.tex file inside the folder
# - Generate a main.tex file in the top-level ./plot folder
########################################################################################

######### STEP 2: CREATION OF EXPERIMENT FOLDER HIERARCHY #####################################################
bash ./latex_script_copy_figs.sh

######### STEP 3: CREATION OF THE SPECIFIC SETTINGS XML FILE ##################################################
bash ./latex_script_tex_figs.sh

