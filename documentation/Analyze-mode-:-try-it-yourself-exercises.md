Here are a couple of example problems you can try to see how well you can use analyze mode. These should get you used to working with it for future projects.

Problem 1. A detail file in Avida contains one line associated with each genotype, in order from the most abundant to the least. Currently, the LOAD command will load the entire file's worth of genotypes into the current batch, but what if you only wanted the top few? You should write a function called LOAD_DETAIL_TOP that takes two arguments. The first ($1) is the name file that needs to be loaded in (just as in the original command), and the second is the number of lines you want to load.

The easiest way to go about doing this is by using the SYSTEM command along with the Unix command head which will output the very top of a file. If you typed the line:

<code>  head -42 detail-1000.spop &gt; my_temp_file
</code>

The file my_temp_file would be created, and its contents would be the first 42 lines of detail-1000.spop. So, what you need this function to do is create a temporary file with proper number of lines from the detail file in it, load that temp file into the current batch, and then delete the file (using the rm command). Warning: be very careful with the automated deletions -- you don't want to accidentally remove something that you really need! I recommend that you use the command rm -i until you finish debugging. This problem may end up being a little tricky for you, but you should be able to work your way through it.

Problem 2. Now that you have a working LOAD_DETAIL_TOP command, you can run LOAD_DETAIL_TOP  1 in order to only load the most dominant genotype from the detail file. Rewrite the example program from the section "Working with Batches" above such that you now only need to work within a single batch.
