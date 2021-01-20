<p>These place limits on when an organism can successfully issue a divide command to produce an offspring.</p>
<table border="1">
<tbody>
<tr class="important">
<td valign="top"><strong><code>OFFSPRING_SIZE_RANGE</code></strong></td>
<td>This is the maximal difference in genome size between a parent and offspring. The default of 2.0 means that the genome of the child must be between one-half and twice the length of the parent. This it to prevent out-of-control size changes. Setting this to 1.0 will ensure fixed length organisms (as long as you also change the other settings detailed in <a title="How to Set Up Fixed-Length Organisms" href="https://github.com/devosoft/avida/wiki/Setting-up-fixed-length-organisms">How to Set Up Fixed-Length Organisms</a>).</td>
</tr>
<tr>
<td valign="top"><strong><code> MIN_COPIED_LINES <br />MIN_EXE_LINES </code></strong></td>
<td>These settings place limits on what the parent must have done before the offspring can be born; they set the minimum fraction of instructions that must have been copied into the offspring (vs. left as default) and the minimum fraction of instructions in the parent that must have been executed. If either of these are not met, the divide will fail. These settings prevent organisms from producing pathological offspring. In practice, either of them can be set to 0.0 to turn them off.</td>
</tr>
<tr>
<td valign="top"><strong><code>REQUIRE_ALLOCATE</code></strong></td>
<td>Is an allocate required between each successful divide (in virtual hardware types where allocate is meaningful)? If so, this will limit the flexibility of how organisms produce children (they can't make multiple copies and divide them off all at once, for example). But if we don't require allocates, the resulting organisms can be a lot more difficult to understand.</td>
</tr>
<tr>
<td valign="top"><strong><code>REQUIRED_TASK</code></strong></td>
<td>This is a bit of a hack. It allows the user to set the ID number for a task that <em>must</em> occur for a divide to be successful. At -1, no tasks are required. Ideally, this should be incorporated into the environment configuration file. NOTE: A task can fire without triggering a reaction. To add a required reaction see below.</td>
</tr>
<tr>
<td valign="top"><strong><code>IMMUNITY_TASK</code></strong></td>
<td>Allows user to set the ID number for a task which, if it occurs, provides immunity from the required task (above) -- divide will proceed even if the <code>REQUIRED_TASK</code> is not done if <code>IMMUNITY_TASK</code> <em>is</em> done. Defaults to -1, no immunity task present.</td>
</tr>
<tr>
<td valign="top"><strong><code>REQUIRED_REACTION</code></strong></td>
<td>Allows the user to set the ID number for a reaction that <em>must</em> occur for a divide to be successful. At -1, no reactions are required.</td>
</tr>
<tr>
<td valign="top"><strong><code>IMMUNITY_REACTION</code></strong></td>
<td>Allows the user to set the ID number for a reaction that, if it occurs, provides immunity from the required reaction (above) -- divide will proceed even if the <code>REQUIRED_REACTION</code> has not been performed as long as the <code>IMMUNITY_REACTION</code> <em>has</em> been performed. Defaults to -1, no immunity reaction present.</td>
</tr>
<tr>
<td valign="top"><strong><code>REQUIRE_EXACT_COPY</code></strong></td>
<td>Requires the offspring to be an exact copy of the parent -- <em>before</em> divide mutations are imposed. At first glance this setting looks very similar to the <code>STERILIZE_UNSTABLE</code> setting in the Mutation Reversion group of settings. However, <code>REQUIRE_EXACT_COPY</code> allows any kind of divide mutation (see <a title="Mutation Settings" href="http://avida.devosoft.org/wiki/documentation/configuration-and-command-reference/avida-cfg-the-avida-configuration-file/mutation-settings/">Mutation Settings</a>)-- point, insertion, deletion, slip, etc. It does not allow before-divide mutations such as copy mutations. On the other hand, <code>STERILIZE_UNSTABLE</code> allows <em>any</em> kind of mutation, as long as the organism would be able to perfectly copy itself in the absence of mutations.</td>
</tr>
</tbody>
</table>
<p>Many other requirements can be imposed. See avida.cfg for <code>MIN_GENOME_SIZE, MAX_GENOME_SIZE, REQUIRE_SINGLE_REACTION, REQUIRED_BONUS, REQUIRED_RESOURCE, REQUIRED_RESOURCE_LEVEL, REQUIRED_PRED_HABITAT, REQUIRED_PRED_HABITAT_VALUE, IMPLICIT_REPRO_BONUS, IMPLICIT_REPRO_CPU_CYCLES, IMPLICIT_REPRO_TIME, IMPLICIT_REPRO_END</code>, and <code>IMPLICIT_REPRO_ENERGY</code>.</p>
