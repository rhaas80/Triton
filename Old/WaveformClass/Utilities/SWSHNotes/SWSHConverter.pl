#! /usr/bin/perl

open(SWSHIn,  "<SWSHCalculatorOutput.cpp");
open(SWSHOut, ">../SWSHs.cpp");

while(<SWSHIn>) {
    my($line) = $_;
    chomp($line);
    $line =~ s/Sqrt */sqrt/g;
    $line =~ s/Power */pow/g;
    $line =~ s/Sin */sin/g;
    $line =~ s/Cos */cos/g;
    $line =~ s/Pi/M_PI/g;
    $line =~ s/ 1\*/ /;
    $line =~ s/ -1\*/ -/;
    $line =~ s/([^,][0-9]+)([\/\*])/\1.0\2/g;
    $line =~ s/([0-9]+) ([+-]) /\1.0 \2 /g;
    $line =~ s/\.0\.0/.0/g;
    $line =~ s/([0-9])\.([^0])/\1.0\2/g;
    $line =~ s/\.0\.0/.0/g;
    $line =~ s/=\.0\*varphi;/= 0.0;/g;
    print(SWSHOut "${line}\n");
}

close(SWSHIn);
close(SWSHOut);
