#! /usr/bin/perl

## ADJUST THE FOLLOWING VARIABLES:

# Path to SpEC/Support/WaveExtrapolation/Waveforms/bin/:
$Waveforms = "~/Waveforms/bin/";

# Where to keep the NINJA-format data:
$KrakenRepos = "../../KrakenRepos/Case1";

# Relative path name of relevant bbh file:
$BBHFile = "SpEC_Case1.bbh";

# Relative subdirectories, each holding a copy of $DataFileName:
@Subdirs = ("GW-Lev1.1.1", "GW-Lev2.2.2", "GW-Lev3.3.3");

# Name of the file in each Subdir to extract to NINJA format:
$DataFileName = "rh_R0400m.dat";




## (PROBABLY) DON'T ADJUST THE FOLLOWING:
foreach $subdir (@Subdirs) {
    system("mkdir -p ${KrakenRepos}/${subdir}");
    system("cp ${BBHFile} ${KrakenRepos}/${subdir}/${BBHFile}");
    system("${Waveforms}OutputToNINJA ${subdir}/${DataFileName} ${KrakenRepos}/${subdir}/${BBHFile} ReIm");
}
