These settings control how creatures are born and die in Avida.

<table border="1">
<tbody>
<tr>
<td valign="top"><strong><code>BIRTH_METHOD</code></strong></td>
<td>The birth method sets how the placement of a child organism is determined. Currently, there are six ways of doing this -- the first four (0-3) are all grid-based (offspring are only placed in the immediate neighborhood), and the last two (4-5) assume a well-stirred population. In all non-random methods, empty sites are preferred over replacing a living organism.  See the avida.cfg file itself for details.</td>
</tr>
<tr>
<td valign="top"><strong><code> DEATH_METHOD <br />AGE_LIMIT </code></strong></td>
<td>By default, replacement is the only way for an organism to die in Avida. However, if a death method is set, organisms will die of old age. In method one, organisms will die when they reach the user-specified age limit. In method 2, the age limit is a multiple of their length, so larger organisms can live longer.</td>
</tr>
<tr>
<td valign="top"><strong><code>ALLOC_METHOD</code></strong></td>
<td>During the replication process in the default virtual CPU, parent organisms must allocate memory space for their child-to-be. Before the child is copied into this new memory, it must have an initial value. Setting the alloc method to zero sets this memory to a default instruction (typical nop-A). Mode 1 leaves it uninitialized (and hence keeps the contents of the last organism that inhabited that space; if only a partial copy occurs, the child is a hybrid if the parent and the dead organism, hence the name necrophilia). Mode 2 just randomizes each instruction. This means that the organism will behave unpredictably if the uninitialized code is executed.</td>
</tr>
<tr>
<td valign="top"><strong><strong><code>DIVIDE_METHOD</code></strong></strong></td>
<td>When a divide occurs, does the parent divide into two children, or else do we have a distinct parent and child? The latter method will allow more age structure in a population where an organism may behave differently when it produces its second or later offspring.</td>
</tr>
<tr>
<td valign="top"><strong><code>GENERATION_INC_METHOD</code></strong></td>
<td>The generation of an organism is the number of organisms in the chain between it and the original ancestor. Thus, the generation of a population can be calculated as the average generation of the individual organisms. When a divide occurs, the child always receives a generation one higher than the parent, but what should happen to the generation of the parent itself? In general, this should be set the same as divide method.</td>
</tr>
</tbody>
</table>

See the avida.cfg file for further settings: <code>DIVIDE_FAILURE_RESETS, PREFER_EMPTY, ALLOW_PARENT, DISPERSAL_RATE, DEATH_PROB, AGE_LIMIT, AGE_DEVIATION, EPIGENETIC_METHOD, RESET_INPUTS_ON_DIVIDE, INHERIT_MERIT,</code> and <code>INHERIT_MULTITHREAD</code>.
