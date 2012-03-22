#! /usr/bin/perl

open(SWSHIn,  "<WignerDMatrix_Q_Output.ipp");
open(SWSHOut, ">../WignerDMatrix_Q.ipp");

while(<SWSHIn>) {
    my($line) = $_;
    chomp($line);
    $line =~ s/Power/::pow/g;
    $line =~ s/ 1\*/ /;
    $line =~ s/ -1\*/ -/;
    $line =~ s/Mag30/Mag_R_0_3/g;
    $line =~ s/Mag12/Mag_R_1_2/g;
#     $line =~ s/([^,][0-9]+)([\/\*])/\1.0\2/g;
#     $line =~ s/([0-9]+) ([+-]) /\1.0 \2 /g;
#     $line =~ s/\.0\.0/.0/g;
#     $line =~ s/([0-9])\.([^0])/\1.0\2/g;
#     $line =~ s/\.0\.0/.0/g;
#     $line =~ s/=\.0\*varphi;/= 0.0;/g;
    print(SWSHOut "${line}\n");
}

close(SWSHIn);
close(SWSHOut);
