#! /usr/bin/perl
#
# Use this script to convert output file to more standard-looking c++
# Run with something like
#   ThisScript < PNResummedAmplitudeTerms_Output.hpp > PNResummedAmplitudeTerms.hpp

while ($Line = <>) {
    chomp ($Line);
    $Line =~ s/else if\(L==2\)/if(L==2)/;
    $Line =~ s/Pi/M_PI/g;
    $Line =~ s/Log/log/g;
    $Line =~ s/Sqrt/sqrt/g;
    $Line =~ s/Power/pow/g;
    if($Line =~ m/amp = Complex\(0,-/) {
	$NextLine = <>;
	chomp($NextLine);
	$NextLine =~ s/Pi/M_PI/g;
	$NextLine =~ s/Log/log/g;
	$NextLine =~ s/Sqrt/sqrt/g;
	$NextLine =~ s/Power/pow/g;
	$Line =~ s/amp = Complex\(0,-/amp = (/;
	$NextLine =~ s/phi = /phi = -M_PI\/2.0 + /;
	print "$Line\n$NextLine\n";
    } elsif($Line =~ m/amp = \(Complex\(0,-/) {
	$NextLine = <>;
	chomp($NextLine);
	$NextLine =~ s/Pi/M_PI/g;
	$NextLine =~ s/Log/log/g;
	$NextLine =~ s/Sqrt/sqrt/g;
	$NextLine =~ s/Power/pow/g;
	$Line =~ s/amp = \(Complex\(0,-/amp = ((/;
	$NextLine =~ s/phi = /phi = -M_PI\/2.0 + /;
	print "$Line\n$NextLine\n";
    } elsif($Line =~ m/amp = Complex\(0,/) {
	$NextLine = <>;
	chomp($NextLine);
	$NextLine =~ s/Pi/M_PI/g;
	$NextLine =~ s/Log/log/g;
	$NextLine =~ s/Sqrt/sqrt/g;
	$NextLine =~ s/Power/pow/g;
	$Line =~ s/amp = Complex\(0,/amp = (/;
	$NextLine =~ s/phi = /phi = M_PI\/2.0 + /;
	print "$Line\n$NextLine\n";
    } elsif($Line =~ m/amp = \(Complex\(0,/) {
	$NextLine = <>;
	chomp($NextLine);
	$NextLine =~ s/Pi/M_PI/g;
	$NextLine =~ s/Log/log/g;
	$NextLine =~ s/Sqrt/sqrt/g;
	$NextLine =~ s/Power/pow/g;
	$Line =~ s/amp = \(Complex\(0,/amp = ((/;
	$NextLine =~ s/phi = /phi = M_PI\/2.0 + /;
	print "$Line\n$NextLine\n";
    } elsif($Line =~ m/amp = -/) {
	$NextLine = <>;
	chomp($NextLine);
	$NextLine =~ s/Pi/M_PI/g;
	$NextLine =~ s/Log/log/g;
	$NextLine =~ s/Sqrt/sqrt/g;
	$NextLine =~ s/Power/pow/g;
	$Line =~ s/amp = -/amp = /;
	$NextLine =~ s/phi = /phi = M_PI + /;
	print "$Line\n$NextLine\n";
    } else {
	print "$Line\n";
    }
}
