<p>These settings control how and when mutations occur in organisms.  The array of options is dizzying, but only the most commonly used are detailed here.  Except that <code>POINT_MUT_PROB</code> isn't actually commonly used.</p>
<table border="1">
<tbody>
<tr>
<td valign="top"><strong><code>POINT_MUT_PROB</code></strong></td>
<td>Point mutations (sometimes referred to as "cosmic ray" mutations) occur every update; the rate set here is a probability for each site that it will be mutated each update. In other words, this should be a very low value if it is turned on at all. If a mutation occurs, that site is replaced with a random instruction. In practice this also slows Avida down if it is non-zero because it requires so many random numbers to be tested every update.</td>
</tr>
<tr class="important">
<td valign="top"><strong><code>COPY_MUT_PROB</code></strong></td>
<td>The copy mutation probability is tested each time an organism copies a single instruction. If a mutation occurs, a random instruction is copied to the destination. In practice this is the most common type of mutations that we use in most of our experiments.  The default value is <code>0.0075</code>, but this is actually higher than you want to use; it is designed to produce pretty results when showing off the viewer.  <strong>The value we commonly use for our experiments is <code>0.0025</code>.</strong></td>
</tr>
<tr class="important">
<td valign="top"><strong><code> DIV_INS_PROB <br />DIV_DEL_PROB </code></strong></td>
<td>These probabilities are tested once per gestation cycle (when an organism is first born) at each position where an instruction could be inserted or deleted, respectively. Each of these mutations change the genome length. Deletions just remove an instruction while insertions add a new, random instruction at the position tested. Multiple insertions and deletions are possible each generation.  By default these mutations are turned off.</td>
</tr>
<tr class="important">
<td valign="top"><strong><code> DIVIDE_MUT_PROB <br />DIVIDE_INS_PROB <br />DIVIDE_DEL_PROB </code></strong></td>
<td>Divide mutation probabilities are tested when an organism is being divided off from its parent. If one of these mutations occurs, a random site is picked for it within the genome. At most one divide mutation of each type is possible during a single divide.  By default, <code>DIVIDE_MUT_PROB</code> is turned off, and both <code>DIVIDE_INS_PROB</code> and <code>DIVIDE_DEL_PROB</code> are set to <code>0.05</code>, which is a value we often use in our experiments.  If you want your organisms never to change in length, obviously, you should turn these insertion and deletion mutations off!  (This is not the only thing you need to do; see <a href="https://github.com/devosoft/avida/wiki/Setting-up-fixed-length-organisms" title="How to Set Up Fixed-Length Organisms">Fixed-Length Organisms</a>.)</td>
</tr>
</tbody>
</table>

See the avida.cfg file itself for more mutation settings (these are all off by default): <code>COPY_INS_PROB, COPY_DEL_PROB, COPY_UNIFORM_PROB, COPY_SLIP_PROB, DIV_MUT_PROB, DIV_UNIFORM_PROB, DIVIDE_UNIFORM_PROB, DIVIDE_SLIP_PROB, DIVIDE_POISSON_MUT_MEAN, DIVIDE_POISSON_INS_MEAN, DIVIDE_POISSON_DEL_MEAN, DIVIDE_POISSON_SLIP_MEAN, INJECT_INS_PROB, INJECT_DEL_PROB, INJECT_MUT_PROB, SLIP_FILL_MODE, SLIP_COPY_MODE, PARENT_MUT_PROB, SPECIAL_MUT_LINE, META_COPY_MUT, META_STD_DEV</code>, and MUT_RATE_SOURCE.  Whew.
