<p>This section covers tests that are (mostly) very CPU intensive, but allow for Avida experiments that would not be possible in any other system. Basically, each time a mutation occurs, we can run the resulting organism in a test CPU, and determine if that effect of the mutation was lethal, detrimental, neutral, or beneficial. This section allows us to act on this. (Note that as soon as anything here is turned on, the mutations need to be tested. Turning multiple settings on will not cause additional speed decrease)</p>
<table border="1">
<tbody>
<tr>
<td valign="top"><strong><code> REVERT_FATAL <br />REVERT_DETRIMENTAL <br />REVERT_NEUTRAL <br />REVERT_BENEFICIAL </code></strong></td>
<td>When a mutation occurs of the specified type, the number listed next to that entry is the probability that the mutation will be reverted. That is, the child organism's genome will be restored as if the mutation had never occurred. This allows us both to manually manipulate the abundance of certain mutation types, or to entirely eliminate them.</td>
</tr>
<tr>
<td valign="top"><strong><code> STERILIZE_FATAL <br />STERILIZE_DETRIMENTAL <br />STERILIZE_NEUTRAL <br />STERILIZE_BENEFICIAL </code></strong></td>
<td>The sterilize options work similarly to revert; the difference being that an organism never has its genome restored. Instead, if the selected mutation category occurs, the child is sterilized so that it still takes up space, but can never produce an offspring of its own.</td>
</tr>
<tr>
<td valign="top"><strong><code>STERILIZE_UNSTABLE</code></strong></td>
<td>If this toggle is set, organisms <em>must</em> be able to produce exact copies of themselves or else they are sterilized and cannot produce any offspring. An organism that naturally (without any external effects) produces an inexact copy of itself is said to have implicit mutations. If this flag is set, explicit mutations (as described in the mutations section above) can still occur.  This particular setting does not seem to be terribly CPU intensive.  <strong>You must turn this setting on to ensure <a href="http://avida.devosoft.org/wiki/documentation/configuration-and-command-reference/fixed-length-organisms/" title="How to Set Up Fixed-Length Organisms">fixed-length organisms</a>.</strong></td>
</tr>
</tbody>
</table>
