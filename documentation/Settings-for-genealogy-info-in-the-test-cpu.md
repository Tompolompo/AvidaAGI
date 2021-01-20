<p>These settings control how Avida monitors and deals with genotypes in the Test CPU.</p>
<table border="1">
<tbody>
<tr>
<td valign="top"><strong><code>THRESHOLD</code></strong></td>
<td>For some statistics, we only want to measure organisms that we are sure are alive, but its not worth taking the time to run them all in isolation, without outside effect (and in some eco-system situations that isn't even possible!). For these purposes, we call a genotype "threshold" if there have ever been more than a certain number of organisms of that genotype. A higher number here ensures a greater probability that the organisms are indeed "alive".</td>
</tr>
<tr>
<td valign="top"><strong><code>TEST_CPU_TIME_MOD</code></strong></td>
<td>Many of our analysis methods require that we be able to run organisms in isolation. Unfortunately, some of these organisms we test might be non-viable. At some point, we have to give up the test and label it as non-viable, but we can't give up too soon or else we might miss a viable, though slow, replicator. This setting is multiplied by the length of the organism's genome in order to determine how many CPU-cycles to run the organism for. A setting of 20 effectively means that the average instruction must be executed twenty times before we give up. In practice, most organisms have an efficiency here of about 5, so 20 works well, but for accurate tests on some pathological organisms, we will be required to raise this number.</td>
</tr>
</tbody>
</table>
