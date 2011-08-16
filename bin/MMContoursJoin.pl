#! /usr/bin/perl

$System = $ARGV[0];
@FileGroups = ("Frequencies_", "Masses_", "MismatchesMax_",
	       "MismatchesT1-NR_", "MismatchesT1-T2_", "MismatchesT1-T3_", "MismatchesT1-T4_",
	       "MismatchesT2-NR_", "MismatchesT2-T3_", "MismatchesT2-T4_",
	       "MismatchesT3-NR_", "MismatchesT3-T4_",
	       "MismatchesT4-NR_");

sub o1 {
  my($x);
  ($x) = @_;
  $x =~ s/.*_o(.*?)-.*/\1/;
  $x;
}

system("/bin/rm -f Data_${System}.zip");

foreach $FileGroup (@FileGroups) {
    $FileGroup .= $System;
    @Files = split(' ', `ls ${FileGroup}_o*`);
    @Files = sort { o1($a) <=> o1($b) } @Files;
    print "Joining '@{Files}'\n";
    system("cat @{Files} > ${FileGroup}.dat");
    system("zip Data_${System}.zip ${FileGroup}.dat");
}
