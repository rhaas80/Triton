#! /usr/bin/perl

$q = $ARGV[0];
$chis = $ARGV[1];
$NSegments = $ARGV[2];
$Command = "MMContours";

# Divide up into segments
use POSIX;
#$FreqsPerSegment = 20; # By hand
$FreqsPerSegment = (121.0/($NSegments-0.0)); # Inefficent but obvious
# $FreqsPerSegment = ceil(121.0/($NSegments-0.0)); # Efficient but weird file ranges

`cp /home/boyle/Waveforms/Routines/MMContours /home/boyle/MMContours/`;

for $seg (1..$NSegments) {
    # Determine the original frequency range
    $OrigStartFreq = ceil((${seg}-1)*${FreqsPerSegment});
    $OrigEndFreq = ceil(${seg}*${FreqsPerSegment});
    
    # Look for this segment's FinishedStep
    $FinishedStep = "FinishedStep_q${q}_chis${chis}_o${OrigStartFreq}-${OrigEndFreq}";
    if ( -e ${FinishedStep} ) {
	($StartMass, $StartFreq) = split(' ', `cat ${FinishedStep}`);
	# If it is '0 0', this segment is done; skip to the next one
	if($StartFreq==0 && $StartMass==0) {
	    print "Skipping ${FinishedStep}; it appears to be done\n";
	    next;
	}
	# If it is not '0 0', those are the new starting conditions
    } else {
	# If it does not exist, start with '0 ${OrigStartFreq}'
	$StartMass = 0;
	$StartFreq = $OrigStartFreq;
    }
    
    # Do the qsub
    $command = "echo \"${Command} $q $chis $StartMass $StartFreq $OrigStartFreq $OrigEndFreq\" | qsub -l nodes=1,walltime=5:59:00 -d /home/boyle/${Command} -e q${q}_chis${chis}_${OrigStartFreq}-${OrigEndFreq}.err -o q${q}_chis${chis}_${OrigStartFreq}-${OrigEndFreq}.out -N q${q}_chis${chis}_${OrigStartFreq} -";
    print "> $command\n";
    print `$command`;
}
