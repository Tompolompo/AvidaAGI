<p>This section covers all of the basic variables that describe the Avida run. <strong>You will probably not need to change these settings.</strong></p>
<table border="1">
<tbody>
<tr>
<td valign="top"><strong><code> RANDOM_SEED </code></strong></td>
<td>The random number seed initializes the random number generator. You should alter only this seed if you want to perform a collection of replicate runs. Setting the random number seed to zero (or a negative number) will base the seed on the starting time of the run -- effectively a random random number seed. In practice, you want to always be able to re-do an exact run in case you want to get more information about what happened.</td>
</tr>
<tr>
<td valign="top"><strong><code> POPULATION_CAP </code></strong></td>
<td>The carrying capacity of the population (in number of organisms), removing random organisms when new organisms are born. Use 0 for no cap.</td>
</tr>
<tr>
<td valign="top"><strong><code> POP_CAP_ELDEST </code></strong></td>
<td>Also applies a population cap, but removes the oldest organisms in the world.</td>
</tr>
</tbody>
</table>
<p>Other general settings are described in the avida.cfg file itself: <code>VERBOSITY, SPECULATIVE,</code> and <code>POP_CAP_ELDEST</code>.</p>
