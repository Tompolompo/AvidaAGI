One really useful feature in analyze mode is the ability for the user to construct a variety of their own commands without modifying the source code. This is done with the FUNCTION command. For example, if you know you will always need a file called lineage.html with very specific information in it, you might write a helper command for yourself as follows:

<pre>
  FUNCTION MY_HTML_LINEAGE  # arg1=run_directory
    PURGE_BATCH
    LOAD $1/detail-100000.spop
    FIND_LINEAGE num_cpus
    RECALCULATE
    DETAIL $1/lineage.html depth parent_dist length fitness html.sequence
  END
</pre>

This works identically to how we found lineages and printed their data in the section above. Only this time, it has created the new command called MY_HTML_LINEAGE that you can use anytime thereafter. Arguments to functions work similar to variables, but they are numbers instead of letters. Thus $1 translates to the first arguments, $2 becomes the second, and so on. You are limited to 9 arguments at this point, but that should be enough for most tasks. $0 is the name of the function you are running, in case you ever need to use that.

You may be interested in also using functions in conjunction with the SYSTEM command. Anything you type as arguments to this command gets run on the command line, so you can make functions to do anything that could otherwise be done were you at the shell prompt. For example, imagine that you were going to use a lot of compressed files in your analysis that you would first need to uncompress. You might right a function like:

<pre>
  FUNCTION UNZIP   # Arg1=filename
    SYSTEM gunzip $1
  END
</pre>

This is a shorter example than you might typically want to write a function for, but it does get the point across. This would allow you to just type UNZIP  whenever you needed to uncompress something.

Functions are particularly useful in conjunction with the INCLUDE command. You can create a file called something like my_functions.cfg in your Avida work directory, define a bunch of functions there, and then start all of your analyze.cfg files with the line:

<code>  INCLUDE my_functions.cfg </code>

and you will have access to all of your functions thereafter. Ideally, as this language becomes more flexible, so will your ability to create functions within the language, so you will be able to develop flexible and useful libraries for yourself.
