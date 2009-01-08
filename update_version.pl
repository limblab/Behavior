# $Id$
# 
# Automatically updates the version fields in words.h

use strict;

my $filename = "words.h";
my $rev = substr('$Rev$', 6, -1);

open OLD_FILE, "<$filename";
open NEW_FILE, ">new_$filename";

while (my $line = <OLD_FILE>) {
  chomp $line;
  if (substr($line, 0, 30) eq "#define BEHAVIOR_VERSION_MICRO") {
    $line = "#define BEHAVIOR_VERSION_MICRO $rev";
  }
  
  if (substr($line, 0, 30) eq "#define BEHAVIOR_VERSION_BUILD") {
    $line = "#define BEHAVIOR_VERSION_BUILD ".(substr($line, 30)+1);
  }
  
  print NEW_FILE "$line\n";
}

close OLD_FILE;
close NEW_FILE;

unlink $filename;
rename "new_$filename", $filename;

