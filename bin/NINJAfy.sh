#! /bin/bash

## Use this script to convert SpEC-format waveforms to NINJA-format,
## and append a given metadata file appropriately.

##################################
## ADJUST THE FOLLOWING VARIABLES:
##################################
# Path to SpEC/Support/WaveExtrapolation/Waveforms/bin/:
Waveforms=~/Waveforms/bin

# Where to put the NINJA-format data:
KrakenRepos=../../KrakenRepos/Case1

# Relative path name of relevant metadata template file:
BBHFile=SpEC_Case1.bbh

# Subdirectories (relative to pwd), each holding a copy of the data files:
Levs=( "GW-Lev1.1.1" "GW-Lev2.2.2" "GW-Lev3.3.3" )

# Files with names of "rh_R${radius}m.dat" will be extracted in each subdirectory of $Levs
Radii=( "0400" "0100" )

# Files with names of "rhOverM_ExtrapolatedN${radius}.dat" will be extracted in each subdirectory of $Levs
ExtrapN=( "2" "3" "4" "5" )



#########################################
## (PROBABLY) DON'T ADJUST THE FOLLOWING:
#########################################
for lev in "${Levs[@]}"
do
    # Create the directory and copy the metadata file
    subdir=${KrakenRepos}/${lev}
    mkdir -p ${subdir}
    cp ${BBHFile} ${subdir}/
    
    # Loop over finite-radius waveforms
    for radius in "${Radii[@]}"
    do
	# Run the routine to convert to NINJA format and append the metadata file
	${Waveforms}/OutputToNINJA ${lev}/rh_R${radius}m.dat ${subdir}/${BBHFile} ReIm ${radius} R${radius}m
    done
    
    # Loop over extrapolated waveforms
    for N in "${ExtrapN[@]}"
    do
	# Run the routine to convert to NINJA format and append the metadata file
	${Waveforms}/OutputToNINJA ${lev}/rhOverM_ExtrapolatedN${N}.dat ${subdir}/${BBHFile} MagArg "extrapolated # N=${N}" ExtrapolatedN${N}
    done
done
