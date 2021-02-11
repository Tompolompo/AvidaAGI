Quite often, the portion of an Avida run that we will be most interested in is the lineage from the final dominant genotype back to the original ancestor. As such, there are tools in Avida to get at this information.

<pre>
  FORRANGE i 100 199
    SET d /home/charles/dev/avida/runs/evo-neut/evo_neut_$i
    PURGE_BATCH
    LOAD $d/detail-100000.spop
    FIND_LINEAGE num_cpus
    RECALCULATE
    DETAIL lineage.$i.html depth parent_dist length fitness html.sequence
  END
</pre>

This program looks very similar to one in the <a href="http://avida.devosoft.org/wiki/documentation/configuration-and-command-reference/sample-programs-from-analyze-mode/using-variables/" title="Using Variables">Using Variables</a> example. The first four lines are actually identical. A .spop detail file contains all of the genotypes that were currently alive in the population at the time it was printed, and by default all of the genotypes that are direct ancestors of those that were still alive. (If you used the save_historic=1 option when you saved this population, the .spop contains only the currently-alive genomes, and you will not find much of a lineage!)

The .spop file therefore gives us the lineages of the entire population back to the original ancestor. Since we are only interested in a single lineage, the next thing we do is run the FIND_LINEAGE command to pick out a single genotype, and discard everything else except for its lineage. In this case, we pick the genotype with the highest abundance (the most virtual CPUs associated with it) at the time of printing.

As before, the RECALCULATE command gets us any additional information we may need about the genotypes, and then we print that information to a file using the DETAIL command. The filenames that we are using this time have the format lineage.$i.html, so they are all being written to the current directory with filenames that incorporate the run number right in them. Also, because the filename ends in the suffix '.html', Avida knows to print the file in a proper html format. Note that the specific values that we choose to print take advantage of the fact that we have a lineage (and hence measured things like the genetic distance to the parent) and are in html mode (and thus can print the sequence using colors to specify where exactly mutations occurred).
