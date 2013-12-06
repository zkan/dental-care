#!/usr/bin/perl

#	----------------------------------------------------------------	#
#	Purpose: To analyze the ROC curve by resulting the				 	#
#						data in the format for plotting a graph 		#
#						in Matlab/Octave								#
#	Author: Kan Ouivirach (kan at ieee dot org)							#
#	Usage: perl computeROC.pl <data file> [interval for thresholding] [number of dimensions]	#
#	Example: perl computeROC.pl data/test 0.5 3							#
#	----------------------------------------------------------------	#

# Perl trim function to remove whitespace from the start and end of the string
# credit: http://www.somacon.com/p114.php
sub trim( $ ) {
	my $string = shift;
	$string =~ s/^\s+//;
	$string =~ s/\s+$//;
	return $string;
}
# Left trim function to remove leading whitespace
sub ltrim( $ ) {
	my $string = shift;
	$string =~ s/^\s+//;
	return $string;
}
# Right trim function to remove trailing whitespace
sub rtrim( $ ) {
	my $string = shift;
	$string =~ s/\s+$//;
	return $string;
}
#	---------------------------------------------------

# Function to compute the accuracy taking TP, FP, TN, and FN as input
sub computeACC {
	my ( @val ) = @_;
	my $TP = $val[0];
	my $FP = $val[1];
	my $TN = $val[2];
	my $FN = $val[3];
	return ( $TP + $TN )/( $TP + $FN + $FP + $TN );
}
# Function to compute the true positive rate taking TP, and FN as input
sub computeTPR {
	my ( @val ) = @_;
	my $TP = $val[0];
	my $FN = $val[1];
	return $TP/( $TP + $FN );
}
# Function to compute the false positive rate taking FP, and TN as input
sub computeFPR {
	my ( @val ) = @_;
	my $FP = $val[0];
	my $TN = $val[1];
	return $FP/( $FP + $TN );
}
# Function to compute the F1 value taking TP, FP, and FN as input
sub computeF1 {
	my ( @val ) = @_;
	my $TP = $val[0];
	my $FP = $val[1];
	my $FN = $val[2];
	return ( 2 * $TP )/( ( $TP + $FN ) + ( $TP + $FP ) );
}

print "-= ROC Analysis Program =-\n\n";
my $file_name = $ARGV[0];
my $interval = $ARGV[1];
if( $interval eq "" ) {
	$interval = 0.1;
}
my $dim = $ARGV[2];
if( $dim eq "" ) {
	$dim = 1;
}
print "Processing on the file: '$file_name' \n";

# To read the data file and store data in a 2D array
my @data;
my @each_data;
open( FILE, $file_name ) or die( "Cannot open file: $file_name" );
my @raw_data = <FILE>;
my $num_of_lines = 0;
foreach $text_line ( @raw_data ) {
	$text_line =~ s/\n/ /g;
	my @output = split( "\t", $text_line );
	
	$num_of_dim = @output - 1;
#	print $num_of_dim . "\n";
#	print $dim . "\n";
	if( $num_of_dim < $dim ) {
		die( "Error: The number of dimensions in the file must be more than or equal to what you need!" );
	}
	
	for( $i = 0; $i < $dim; $i++ ) {
		$each_data[$i] = trim( $output[$i] );
	}
#	print $i . "\n";
	$each_data[$i] = trim( $output[$num_of_dim] );
#	print @each_data . "\n";
	
#	print $each_data[0] . " " . $each_data[1] . "\n";
	@data[$num_of_lines] = [ @each_data ];
	
	$num_of_lines++;
}
=loop for printing the array elements
for( $i = 0; $i < @data; $i++ ) {
	for( $j = 0; $j < $#{$data[$i]}+1; $j++ ) {
		print $data[$i][$j] . "\t";
	}
	print "\n";
}
=cut

print "Size of data: " . @data . "\n";
print "Result format: [Prob.\tActual\tPrediction\tResult]\n\n";

# Finding the min and max value
my $min = $data[0][0];
my $max = $data[0][0];
for( $i = 0; $i < scalar @data; $i++ ) {
	if( $data[$i][0] > $max ) {
		  $max = $data[$i][0];
	}
	elsif( $data[$i][0] < $min ) {
		  $min = $data[$i][0];
	}
}
$min -= $interval;
$max += $interval;

#print "The maximum is " . $max . "\n";
#print "The minimum is " . $min . "\n\n";

# To calculate TPR and FPR by increasing the threshold from the minimum value
my @ROC_graph;
my @each_point;
my $Th;	# abnormal if the value is below threshol
my $count = 0;
for( $Th = $min; $Th <= $max; $Th += $interval ) {
	print "Threshold: $Th\n";
	my $TP = 0;
	my $FP = 0;
	my $TN = 0;
	my $FN = 0;
	for( $i = 0; $i < scalar @data; $i++ ) {
		#	Predict as positive
		if( $data[$i][0] < $Th ) {
			print $data[$i][0] . "\t" . $data[$i][1] . "\tp";
			if( $data[$i][1] eq "p" ) {
				print "\tTP\n";
				$TP++;
			}
			else {
				print "\tFP\n";
				$FP++;
			}
		}
		#	Predict as negative
		else {
			print $data[$i][0] . "\t" . $data[$i][1] . "\tn";
			if( $data[$i][1] eq "p" ) {
				print "\tFN\n";
				$FN++;
			}
			else {
				print "\tTN\n";
				$TN++;
			}
		}
	}
	print "\n-- Result --\n";
	print "TP = $TP\n";
	print "FP = $FP\n";
	print "TN = $TN\n";
	print "FN = $FN\n\n";
	
	$TPR = computeTPR( $TP, $FN );
	$FPR = computeFPR( $FP, $TN );
	$F1 = computeF1( $TP, $FP, $FN );
	$ACC = computeACC( $TP, $FP, $TN, $FN );
	print "TPR = " . $TPR . "\n";
	print "FPR = " . $FPR . "\n";
	print "F1 = " . $F1 . "\n";
	print "ACC = " . $ACC . "\n\n";
	
	$each_point[0] = $FPR;
	$each_point[1] = $TPR;
	$each_point[2] = $Th;
	@ROC_graph[$count] = [ @each_point ];
	$count++;
}

print "-- ROC Curve --\n";
print "x = [ ";
for( $i = 0; $i < $count; $i++ ) {
	print $ROC_graph[$i][0] . " ";
}
print "];\n";

print "y = [ ";
for( $i = 0; $i < $count; $i++ ) {
	print $ROC_graph[$i][1] . " ";
}
print "];\n";
print "plot( x, y );\n";
print "xlabel( 'False Positive Rate' );\n";
print "ylabel( 'True Positive Rate' );\n";
print "title( 'ROC Curve' );\n\n";









