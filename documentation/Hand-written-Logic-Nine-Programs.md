These programs were written as supplementary material for The Evolutionary Origin of Complex Features from 2003: http://myxo.css.msu.edu/papers/nature2003/. Here are programs that will trigger the nine default logic tasks with the default instruction set.  


<!-- saved from url=(0061)http://myxo.css.msu.edu/papers/nature2003/logic_programs.html -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1"></head><body bgcolor="#FFFFFF">

<p>
    <big>
    The following hand-written programs perform the various one- and
    two-input logic operations.  These programs appear to be the shortest
    ones to perform these operations that do not depend on the initial
    content of stacks and registers (whose initial contents are represented
    by a '?' below).  However, it has not been proven that these are the
    shortest programs.  None of these programs permit self-replication;
    rather, they merely perform a calculation.
    </big>

<br><br>
</p><center>

<table border="1" width="90%">
<tbody><tr><th colspan="7" bgcolor="CCCCFF"><big>ECHO</big>
</th></tr><tr><th> #</th><th>Inst </th><th>AX </th><th>BX </th><th>CX  </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO   </th><td>?  </td><td>X  </td><td> ?  </td><td>? </td><td> ?
</td></tr><tr><th> 2</th><th>IO   </th><td>?  </td><td>Y  </td><td> ?  </td><td>? </td><td> X

</td></tr><tr><td colspan="7">&nbsp;
</td></tr><tr><th colspan="7" bgcolor="CCCCFF"><big>NOT</big>
</th></tr><tr><th> #</th><th>Inst  </th><th>AX </th><th>BX </th><th>CX </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO    </th><td>?  </td><td>X  </td><td>?  </td><td>?     </td><td> ?
</td></tr><tr><th> 2</th><th>push  </th><td>?  </td><td>X  </td><td>?  </td><td>X, ?  </td><td>&nbsp;
</td></tr><tr><th> 3</th><th>pop   </th><td>?  </td><td>X  </td><td>X  </td><td>?     </td><td>&nbsp;
</td></tr><tr><th> 4</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th> 5</th><th>nand  </th><td>?  </td><td>~X </td><td>X  </td><td>?     </td><td>&nbsp;
</td></tr><tr><th> 6</th><th>IO    </th><td>?  </td><td>Y  </td><td>X  </td><td>?     </td><td> ~X

</td></tr><tr><td colspan="7">&nbsp;
</td></tr><tr><th colspan="7" bgcolor="CCCCFF"><big>NAND</big>
</th></tr><tr><th> #</th><th>Inst  </th><th>AX       </th><th>BX     </th><th>CX      </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO    </th><td>?  </td><td>X  </td><td>?  </td><td>? </td><td> ?
</td></tr><tr><th> 2</th><th>IO    </th><td>?  </td><td>X  </td><td>Y  </td><td>? </td><td> ?
</td></tr><tr><th> 3</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th> 4</th><th>nand  </th><td>?  </td><td>X nand Y </td><td>Y  </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 5</th><th>IO    </th><td>?  </td><td>Z  </td><td>Y  </td><td>? </td><td> X nand Y

</td></tr><tr><td colspan="7">&nbsp;
</td></tr><tr><th colspan="7" bgcolor="CCCCFF"><big>OR_N</big>
</th></tr><tr><th> #</th><th>Inst  </th><th>AX </th><th>BX     </th><th>CX      </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO    </th><td>?  </td><td>X         </td><td>?  </td><td>? </td><td> ?
</td></tr><tr><th> 2</th><th>IO    </th><td>?  </td><td>X         </td><td>Y  </td><td>? </td><td> ?
</td></tr><tr><th> 3</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th> 4</th><th>nand  </th><td>?  </td><td>X nand Y  </td><td>Y  </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 5</th><th>nand  </th><td>?  </td><td>X or ~Y   </td><td>Y  </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 6</th><th>IO    </th><td>?  </td><td>Z         </td><td>Y  </td><td>? </td><td> X or ~Y

</td></tr><tr><td colspan="7">&nbsp;
</td></tr><tr><th colspan="7" bgcolor="CCCCFF"><big>AND</big>
</th></tr><tr><th> #</th><th>Inst  </th><th>AX       </th><th>BX     </th><th>CX      </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO    </th><td>?  </td><td>X        </td><td>?        </td><td>? </td><td> ?
</td></tr><tr><th> 2</th><th>IO    </th><td>?  </td><td>X        </td><td>Y        </td><td>? </td><td> ?
</td></tr><tr><th> 3</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th> 4</th><th>nand  </th><td>?  </td><td>X nand Y </td><td>Y        </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 5</th><th>push  </th><td>?  </td><td>X nand Y </td><td>Y        </td><td>X nand Y, ? </td><td>&nbsp;
</td></tr><tr><th> 6</th><th>pop   </th><td>?  </td><td>X nand Y </td><td>X nand Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 7</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th> 8</th><th>nand  </th><td>?  </td><td>X and Y  </td><td>X nand Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 9</th><th>IO    </th><td>?  </td><td>Z        </td><td>X nand Y </td><td>? </td><td> X and Y

</td></tr><tr><td colspan="7">&nbsp;
</td></tr><tr><th colspan="7" bgcolor="CCCCFF"><big>OR</big>
</th></tr><tr><th> #</th><th>Inst  </th><th>AX       </th><th>BX     </th><th>CX      </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO    </th><td>?  </td><td>X  </td><td>?  </td><td>? </td><td> ?
</td></tr><tr><th> 2</th><th>push  </th><td>?  </td><td>X  </td><td>?  </td><td>X, ?       </td><td>&nbsp;
</td></tr><tr><th> 3</th><th>pop   </th><td>?  </td><td>X  </td><td>X  </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 4</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th> 5</th><th>nand  </th><td>~X </td><td>X  </td><td>X  </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 6</th><th>nop-A </th><td colspan="5">&nbsp;
</td></tr><tr><th> 7</th><th>IO    </th><td>~X </td><td>Y  </td><td>X  </td><td>? </td><td> X
</td></tr><tr><th> 8</th><th>push  </th><td>~X </td><td>Y  </td><td>X  </td><td>Y, ?       </td><td>&nbsp;
</td></tr><tr><th> 9</th><th>pop   </th><td>~X </td><td>Y  </td><td>Y  </td><td>? </td><td>&nbsp;
</td></tr><tr><th>10</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th>11</th><th>nand  </th><td>~X </td><td>~Y </td><td>Y  </td><td>? </td><td>&nbsp;
</td></tr><tr><th>12</th><th>swap  </th><td>Y  </td><td>~Y </td><td>~X </td><td>? </td><td>&nbsp;
</td></tr><tr><th>13</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th>14</th><th>nand  </th><td>Y  </td><td>X or Y </td><td>~X  </td><td>? </td><td>&nbsp;
</td></tr><tr><th>15</th><th>IO    </th><td>Y  </td><td>Z      </td><td>~X  </td><td>? </td><td> X or Y

</td></tr><tr><td colspan="7">&nbsp;
</td></tr><tr><th colspan="7" bgcolor="CCCCFF"><big>AND_N</big>
</th></tr><tr><th> #</th><th>Inst  </th><th>AX       </th><th>BX     </th><th>CX      </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO    </th><td>?  </td><td>X         </td><td>?       </td><td>? </td><td> ?
</td></tr><tr><th> 2</th><th>IO    </th><td>?  </td><td>X         </td><td>Y       </td><td>? </td><td> ?
</td></tr><tr><th> 3</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th> 4</th><th>nand  </th><td>?  </td><td>X nand Y  </td><td>Y       </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 5</th><th>nand  </th><td>?  </td><td>X or ~Y   </td><td>Y       </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 6</th><th>push  </th><td>~X </td><td>X or ~Y   </td><td>Y       </td><td>~X or Y, ? </td><td>&nbsp;
</td></tr><tr><th> 7</th><th>pop   </th><td>~X </td><td>X or ~Y   </td><td>X or ~Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 8</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th> 9</th><th>nand  </th><td>?  </td><td>~X and Y  </td><td>X or ~Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th>10</th><th>IO    </th><td>?  </td><td>Z         </td><td>X or ~Y </td><th>? </th><td> ~X and Y

</td></tr><tr><td colspan="7">&nbsp;
</td></tr><tr><th colspan="7" bgcolor="CCCCFF"><big>NOR</big>
</th></tr><tr><th> #</th><th>Inst  </th><th>AX       </th><th>BX     </th><th>CX      </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO    </th><td>?  </td><td>X  </td><td>?  </td><td>? </td><td> ?
</td></tr><tr><th> 2</th><th>push  </th><td>?  </td><td>X  </td><td>?  </td><td>X, ?       </td><td>&nbsp;
</td></tr><tr><th> 3</th><th>pop   </th><td>?  </td><td>X  </td><td>X  </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 4</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th> 5</th><th>nand  </th><td>~X </td><td>X  </td><td>X  </td><td>? </td><td>&nbsp;
</td></tr><tr><th> 6</th><th>nop-A </th><td colspan="5">&nbsp;
</td></tr><tr><th> 7</th><th>IO    </th><td>~X </td><td>Y  </td><td>X  </td><td>? </td><td> X
</td></tr><tr><th> 8</th><th>push  </th><td>~X </td><td>Y  </td><td>X  </td><td>Y, ?       </td><td>&nbsp;
</td></tr><tr><th> 9</th><th>pop   </th><td>~X </td><td>Y  </td><td>Y  </td><td>? </td><td>&nbsp;
</td></tr><tr><th>10</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th>11</th><th>nand  </th><td>~X </td><td>~Y </td><td>Y  </td><td>? </td><td>&nbsp;
</td></tr><tr><th>12</th><th>swap  </th><td>Y  </td><td>~Y </td><td>~X </td><td>? </td><td>&nbsp;
</td></tr><tr><th>13</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th>14</th><th>nand  </th><td>Y  </td><td>X or Y  </td><td>~X     </td><td>? </td><td>&nbsp;
</td></tr><tr><th>15</th><th>push  </th><td>Y  </td><td>X or Y  </td><td>X      </td><td>X or Y, ? </td><td>&nbsp;
</td></tr><tr><th>16</th><th>pop   </th><td>Y  </td><td>X or Y  </td><td>X or Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th>17</th><th>nop-C </th><td colspan="5">&nbsp;
</td></tr><tr><th>18</th><th>nand  </th><td>Y  </td><td>X nor Y </td><td>X or Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th>19</th><th>IO    </th><td>Y  </td><td>Z       </td><td>X or Y </td><td>? </td><td> X nor Y

</td></tr><tr><td colspan="7">&nbsp;
</td></tr><tr><th colspan="7" bgcolor="CCCCFF"><big>XOR</big>
</th></tr><tr><th> #</th><th>Inst </th><th>AX      </th><th>BX      </th><th>CX      </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO   </th><td>?       </td><td>X       </td><td>?       </td><td>? </td><td> ?
</td></tr><tr><th> 2</th><th>IO   </th><td>?       </td><td>X       </td><td>Y       </td><td>? </td><td> ?
</td></tr><tr><th> 3</th><th>nop-C</th><td colspan="5">&nbsp;
</td></tr><tr><th> 4</th><th>push </th><td>?       </td><td>X       </td><td>Y       </td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 5</th><th>nand </th><td>?       </td><td>X nand Y</td><td>Y       </td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 6</th><th>swap </th><td>?       </td><td>Y       </td><td>X nand Y</td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 7</th><th>nand </th><td>?       </td><td>X or ~Y </td><td>X nand Y</td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 8</th><th>swap </th><td>X or ~Y </td><td>?       </td><td>X nand Y</td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 9</th><th>nop-A</th><td colspan="5">&nbsp;
</td></tr><tr><th>10</th><th>pop  </th><td>X or ~Y </td><td>X       </td><td>X nand Y</td><td>? </td><td>&nbsp;
</td></tr><tr><th>11</th><th>nand </th><td>X or ~Y </td><td>Y or ~X </td><td>X nand Y</td><td>? </td><td>&nbsp;
</td></tr><tr><th>12</th><th>swap </th><td>X nand Y</td><td>Y or ~X </td><td>X or ~Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th>13</th><th>nop-C</th><td colspan="5">&nbsp;
</td></tr><tr><th>14</th><th>nand </th><td>X nand Y</td><td>X xor Y </td><td>X or ~Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th>15</th><th>IO   </th><td>X nand Y</td><td>Z       </td><td>X or ~Y </td><td>? </td><td> X xor Y


</td></tr><tr><td colspan="7">&nbsp;
</td></tr><tr><th colspan="7" bgcolor="CCCCFF"><big>EQU</big>
</th></tr><tr><th> #</th><th>Inst </th><th>AX      </th><th>BX      </th><th>CX      </th><th>Stack   </th><th> Output
</th></tr><tr><th> 1</th><th>IO   </th><td>?       </td><td>X       </td><td>?       </td><td>? </td><td> ?
</td></tr><tr><th> 2</th><th>IO   </th><td>?       </td><td>X       </td><td>Y       </td><td>? </td><td> ?
</td></tr><tr><th> 3</th><th>nop-C</th><td colspan="5">&nbsp;
</td></tr><tr><th> 4</th><th>push </th><td>?       </td><td>X       </td><td>Y       </td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 5</th><th>nand </th><td>?       </td><td>X nand Y</td><td>Y       </td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 6</th><th>swap </th><td>?       </td><td>Y       </td><td>X nand Y</td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 7</th><th>nand </th><td>?       </td><td>X or ~Y </td><td>X nand Y</td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 8</th><th>swap </th><td>X or ~Y </td><td>?       </td><td>X nand Y</td><td>X, ? </td><td>&nbsp;
</td></tr><tr><th> 9</th><th>nop-A</th><td colspan="5">&nbsp;
</td></tr><tr><th>10</th><th>pop  </th><td>X or ~Y </td><td>X       </td><td>X nand Y</td><td>? </td><td>&nbsp;
</td></tr><tr><th>11</th><th>nand </th><td>X or ~Y </td><td>Y or ~X </td><td>X nand Y</td><td>? </td><td>&nbsp;
</td></tr><tr><th>12</th><th>swap </th><td>X nand Y</td><td>Y or ~X </td><td>X or ~Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th>13</th><th>nop-C</th><td colspan="5">&nbsp;
</td></tr><tr><th>14</th><th>nand </th><td>X nand Y</td><td>X xor Y </td><td>X or ~Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th>15</th><th>push </th><td>X nand Y</td><td>X xor Y </td><td>X or ~Y </td><td>X xor Y, ?</td><td>&nbsp;
</td></tr><tr><th>16</th><th>pop  </th><td>X nand Y</td><td>X xor Y </td><td>X xor Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th>17</th><th>nop-C</th><td colspan="5">&nbsp;
</td></tr><tr><th>18</th><th>nand </th><td>X nand Y</td><td>X equ Y </td><td>X xor Y </td><td>? </td><td>&nbsp;
</td></tr><tr><th>19</th><th>IO   </th><td>X nand Y</td><td>Z       </td><td>X xor Y </td><td>? </td><td> X equ Y

</td></tr></tbody></table>

</center><span id="buffer-extension-hover-button" style="display: none;position: absolute;z-index: 8675309;width: 100px;height: 25px;background-image: url(chrome-extension://noojglkidnpfjbincgijbaiedldjfbhh/data/shared/img/buffer-hover-icon@1x.png);background-size: 100px 25px;opacity: 0.9;cursor: pointer;"></span></body></html>