Often, you will want to run the same section of analyze code with multiple different inputs each time through, or else you might simply want a single value to be easy to change throughout the code. To facilitate such programming practices, variables are available in analyze mode that can be altered for each repitition through the code.

There are actually several types of variables, all of which are a single letter of number. For a command that requires a variable name as an input, you simply put that variable where it is requested. For example, if you were going to set the variable i to be equal to the number 12, you would type:

<code>  SET i 12 </code>

But later on in the code, how does Avida know when you type an i if you really want the letter 'i' there, or if you prefer the number 12 to be there? To distinguish these cases, you must put a dollar sign '$' before a variable wherever you want it to be translated to its value instead of just using the variable name itself.

There are a few different commands that allow you to manipulate a variable's value, and sometimes execute a section of code multiple times based off of each of the possible values. Here is one example:

<pre>
  FORRANGE i 100 199
    SET d /home/charles/dev/avida/runs/evo-neut/evo_neut_$i
    PURGE_BATCH
    LOAD $d/detail-100000.spop
    RECALCULATE
    DETAIL $d/detail.dat update length fitness sequence
  END
</pre>

The FORRANGE command runs the contents of the loop once for each possible value in the range, setting the variable i to each of these values in turn. Thus the first time through the loop, 'i' will be equal to the value '100', then '101', '102', all the way up to '199'. In this particular case, we have 100 runs (numbered 100 through 199) that we want to work with.

The first thing we do once we're inside the loop is set the value of the variable 'd' to be the name of the directory we're going to be working with. Since this is a long directory name, we don't want to have to type it over every time we need it. If we set it to the variable d, then all we need to do is type '$d' in the future, and it will be translated to the full name. Note that in this case we are setting a variable to a string instead of a number; that's just fine and Avida will figure out how to handle it properly. This directory we are working with will change each time through the loop, and that it is no problem to use one variable as part of setting another.

After we know what directory we are using, we run a PURGE_BATCH to get rid of all of the genotypes from the last time through the loop (lest we just keep building up more and more genotypes in the current batch) and then we refill the batch by using LOAD to load in all of the genotypes saved in the file detail-100000.spop within our chosen directory. The RECALCULATE command runs all of the genotypes through a test CPU so we have all the statistics we need, and finally DETAIL will print out the stats we want to the file detail.dat, again placing it in the proper directory. The END command signifies the end of the FORRANGE loop.
