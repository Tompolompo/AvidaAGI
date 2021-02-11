In analyze mode, we can load genotypes into multiple batches and we then operate on a single batch at a time. So, for example, if we wanted to only consider the dominant genotypes at time points 100 updates apart, but all we had to work with were the detail files (containing all genotypes at each time point) we might write a program like:

<pre>
  SET d /home/charles/avida/runs/mydir/here-it-is
  SET_BATCH 0
  FORRANGE u 100 100000 100            # Cycle through updates
    PURGE_BATCH                        # Purge current batch (0)
    LOAD $d/detail-$u.spop  # Load in the population at this update
    FIND_GENOTYPE num_cpus             # Remove all but most abundant genotype
    DUPLICATE 0 1                      # Duplicate batch 0 into batch 1
  END
  SET_BATCH 1                          # Switch to batch 1
  RECALCULATE                          # Recalculate statistics...
  DETAIL dom.dat fitness sequence      # Print info for all dominants!
</pre>

This program is slightly more complicated than the other examples, so I added in comments directly inside it. Basically, what we do here is use batch 0 as our staging area where we load the full detail dumps, strip them down to only the single most abundant genotype, and then copy that genotype over into batch 1. By the time we're done, we have all of the dominant genotypes inside of batch 1, so we can print anything we need right from there.
