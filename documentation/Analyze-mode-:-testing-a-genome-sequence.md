The following program will load in a genome sequence, run it through a test CPU, and output the information about it in a couple of formats.

<pre>
  VERBOSE
  LOAD_SEQUENCE rmzavcgmciqqptqpqcpctletncogcbeamqdtqcptipqfpgqxutycuastttva
  RECALCULATE
  DETAIL detail_test.dat fitness merit gest_time length viable sequence
  TRACE
  PRINT
</pre>

This program starts off with the VERBOSE command so that Avida will print to the screen all of the details about what is going on as it runs the analyze script; I recommend you begin all of your programs this way for debugging purposes. The program then uses the LOAD_SEQUENCE command to allow the user to enter a specific genome sequence in its compressed format. This will translate the genome into the proper genotype as long as you are using the correct instruction set file, since that file determines the mappings of letters to instructions).

The RECALCULATE command places the genome sequence into a test CPU, and determines its fitness, merit, gestation time, etc. so that the DETAIL command that follows it can have access to all of this information as it prints it to the file "detail_test.dat" (its first argument). The TRACE and PRINT commands will then print individual files about this genome, the first tracing its execution line-by-line, and the second summarizing all sorts of statistics about it and displaying the genome. Since no directory was specified for these commands, archive/ is assumed, and the filenames are org-S1.trace and org-S1.gen. If a genotype has a name when it is loaded, that name will be kept, but if it doesn't, it will be assigned a name starting at org-S1, then org-S2, and so on counting higher. The TRACE and PRINT commands add their own suffixes to the genome's name to determine the filename they will be printed as.
