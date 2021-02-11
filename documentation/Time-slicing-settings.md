<p>These settings describe exactly what an update is, and how CPU time is allocated to organisms during that update.</p>
<table border="1">
<tbody>
<tr>
<td valign="top"><strong><code>AVE_TIME_SLICE</code></strong></td>
<td>This sets the average number of instructions an organism should execute each update. Organisms with a low merit will consistently obtain fewer, while organisms of a higher merit will receive more.</td>
</tr>
<tr>
<td valign="top"><strong><code>SLICING_METHOD</code></strong></td>
<td>This setting determines the method by which CPU time is handed out to the organisms. Method 0 ignores merit, and hands out time on the CPU evenly; each organism executes one instruction for the whole population before moving onto the second. Method 1 is probabilistic; each organism has a chance of executing the next instruction proportional to it merit. This method is slow due to the large number of random values that need to be obtained and evaluated (and it only gets slower as merits get higher). Method 2 is fully integrated; the organisms get CPU time proportional to their merit, but in a fixed, deterministic order.</td>
</tr>
<tr>
<td valign="top"><strong><code>BASE_MERIT_METHOD</code></strong></td>
<td>This setting determines the base value of an organism's merit. Merit is typically proportional to genome length otherwise there is a strong selective pressure for shorter genomes (shorter genome =&gt; less to copy =&gt; reduced copying time =&gt; replicative advantage). Unfortunately, organisms will cheat if merit is proportional to the full genome length -- they will add on unexecuted and uncopied code to their genomes creating a code bloat. This isn't the most elegant fix, but it works.</td>
</tr>
<tr>
<td valign="top"><strong><code>MAX_LABEL_EXE_SIZE</code></strong></td>
<td>Labels are sequences of nop (no-operation) instructions used only to modify the behavior of other instructions. Quite often, an organism will have these labels in their genomes where the nops are used by another instruction, but never executed directly. To represent the executed length of an organism correctly, we need to somehow count these labels. Unfortunately, if we count the entire label, the organisms will again "cheat" artificially increasing their length by growing huge labels. This setting limits the number of nops that are counted as executed when a label is used.</td>
</tr>
<tr>
<td valign="top"><strong><code>MAX_CPU_THREADS</code></strong></td>
<td>Determines the number of simultaneous processes that an organism can run. That is, basically, the number of things it can do at once. This setting is meaningless unless threads are supported in the virtual hardware and the instructions are available within the instruction set.</td>
</tr>
</tbody>
</table>

See the avida.cfg file for more options: <code>SLICING_BURST_SIZE, BASE_CONST_MERIT, MERIT_BONUS_INST, MERIT_BONUS_EFFECT, FITNESS_VALLEY, FITNESS_VALLEY_START, FITNESS_VALLEY_STOP, DEFAULT_BONUS, MERIT_DEFAULT_BONUS, MERIT_INC_APPLY_IMMEDIATE, TASK_REFRACTORY_PERIOD, FITNESS_METHOD, FITNESS_COEFF_1, FITNESS_COEFF_2, THREAD_SLICING_METHOD, NO_CPU_CYCLE_TIME, PRECALC_PHENOTYPE, FASTFORWARD_UPDATES, FASTFORWARD_NUM_ORGS</code>, and <code>GENOTYPE_PHENPLAST_CALC</code>.
