Avida 3 will include and be built around a flexible, extensible application programming interface (API).  The intention of the API is to provide a powerful, stable interface to core Avida functionality.

The API will be broken up into multiple modules that will be connected together to create rich experiments and powerful analyses. The development of this API is very active right now.  The following provides an overview of existing components and an estimation of their completeness and stability.

### API Modules
* core
* data
* environment
* systematics
* util
* viewer

### Notes
The following are miscellaneous notes, which may or may not be relevant to the current Avida 3.0 plans. Preserved for consideration.

* Get rid of merit.  Organisms have energy (which they absorb by performing reactions) and metabolic rate, which determines how quickly they use that energy to execute instructions.
* Each thread in an organism is placed into the scheduler.  When a thread is created, the scheduler assigns it a process ID, and that ID is then freed up with the thread is removed.  A thread must keep track of its own ID. When a thread is removed, its ID is placed in a container of free IDs.  Only when that container is empty are new IDs created.  This will happen rarely enough that its okay if its a slow process.
* New analyze mode!  This should be interesting...  Require lex & yacc?
* Implement new method of performing mutations.  The old stuff should be entirely removed.
* This version will be optimized for stack-based CPUs, but the old register based CPUs should still function fine.
* Make sure all output files have headers.  There should be a central object that all files are output through that will make sure this is the case.
* Make events just call analyze scripts.  Re-design entire event structure.

### Mutations.cfg ideas
<pre>
# @CAO : THIS IS A PROTOTYPE FILE FOR HOW I'D LIKE TO SEE MUTATIONS WORK

# This file is used to configure the mutations that occur during an avida
# run.  The format is simple:
#
#   MUTATION <name> <trigger> <scope> <type> <rate>
#
# The "trigger" determines when the mutation should be tested for. 
# Possibilities are -
#
#   update  : Test for these mutations each update
#   divide  : Test during the successful birth of an offspring
#   parent  : Test on a parent during a divide operation
#   write   : Test each time an instruction is written to memory
#   read    : Test whenever an instruction is read from memory.
#   exec    : Test while an instruction is being processed by the hardware
#
# A copy command will perform both a read and a write.  A read mutation will
# affect the site being read, and are therefore particulaly dangerous.
#
# The scope of a mutation type determines how much will be mutated.  There
# are currently a few options -
#
#   genome  : A single mutation occurs in the whole genome.
#   local   : Mutations occur at a local position.  If no local position can
#             be specified in the trigger (i.e. 'parent') nothing happens.
#   prop    : Proportional: same as local, but the rate used is normalized to
#             1/genome_length
#   global  : Same as local, but *all* positions in the genome are tested.
#   spread  : Same as prop, but all positions are tested.
#
# The type of mutation determines what happens when a mutation does occur
# at a site -
#
#   point    : Change the affected locus to a random instruction.
#   insert   : Insert a random instruction at this poistion.
#   delete   : Remove the instruction currently at this position.
#   head_inc : Advance heads at this position.
#   head_dec : Retreat heads at this position.
#   temp     : Don't change the genome, but temporarily act as if a change has
#              occured.  This is only relevent for types "read" and "exec".
#   kill     : Sterilize the organism affected so that it is effectively dead.
#
# Finally, the rate indicates the frequency at which mutations occur.
#
# EXAMPLES:
#
# Old stype copy mutation rate of 0.0075:
#
#   MUTATION copy_mutation write local point 0.0075
#
# Old style divide insertion of 0.05:
#
#   MUTATION divide_ins divide genome insert 0.05
#
# Keeping an average genome mutation rate at 2.0 with copy mutations...
#
#   MUTATION copy_spread write prop point 2.0
#
# Most types of mutations that people want should be possible.
#
# CONFLICTS:
#  Only local & spread scopes can interact with head/temp types.
#  Divide trigger cannot work with local & spread scopes.
</pre>


### Stack-based Instruction Set
<pre>
# This new CPU has 8 heads, 2 of each main type, and otherwise has four
# stacks (A, B, C, and D) and no registers.

# Base Instruction Set
# Nops (1-4)
Nop-A      1   # Associated with the Instruction Pointers
Nop-B      1   # Associated with the Read Heads
Nop-C      1   # Associated with the Write Heads
Nop-D      1   # Associated with the Flow Heads

# Other control functions (5)
Toggle     1  # Causes all instructions to swap to a complementary behavior
              # affects only the instruction that immediately follows it.
              # A nop indicates that the associate head should be toggled
              # to its alternate.  Two toggles will reset all toggled states

# Single input Math -- *modifies* top of ?Stack-B? (6-7)
Val-Shift  1  # shirt-r before toggle, shift-l after.
Val-Inc    1  # inc before toggle, dec after

# Double input math -- uses top of Stack-A and Stack-B; pushes result onto
# the top of Stack-B (8-9)
Val-Nand   1  # unaffected by toggle
Val-Add    1  # add before toggle, sub after

# Biological  (10-13)
SetMemory  1  # Set the write head at the beginning of a memory space.  Up
              #   to four memory spaces can be used at once.  Nop-A is the
              #   main genome, and the other nops are possible offspring.
              #   A nop argument will indicate a space; no nops will find
              #   an "unclaimed" memory space (if possible)
              #   Perhaps Toggle can be used for recombination somehow??
Divide     1  # Divide off offspring memory.  After toggle becomes Inject.
              #   If threads are active a successful inject will also cause
              #   a fork.  In either case, it uses the memory that contains
              #   the active write head.
Inst-Read  1  # Push the instruction at ?read-head? into Stack-A (advance 
              #   head) Toggle to move head back by one rather than advance.
Inst-Write 1  # Pop Stack-A into position at ?write-head? (advance head)
              #   Toggle to move head back by one rather than advance.

# Flow Control (14-15)
If-Equal   1  # Compares top of ?Stack-A? with successor (Default: Stack-B)
              #   Becomes If-NEqual after toggle
If-Less    1  # Compares top of ?Stack-A? with successor (Default: Stack-B)
              #   Becomes If-Greater after toggle

# Head Control (16-19)
Head-Push  1  # Push position of ?IP? head onto Stack-B.
              #   Toggle to use Stack-D
Head-Pop   1  # Move ?flow-head? to address in Stack-B (pop Stack-B)
              #   Toggle to use Stack-D

Head-Move  1  # Move ?IP? head to flow-head
              #   - if flow-head is given as nop, advance flow-head
              #   Toggle to decrement flow-head when given as nop.
Search     1  # Search for matching template, set flow head to last line,
              #   template size to Stack-A and template distance to Stack-B
	         #   If no template, move flow-head to next line, set A&B=0.
              #   Toggle to NOT leave size&distance

# Stack Control (20-24)
Push-Next  1   # Pop off ?Stack-A? and push on successor   (Default: Stack-B)
Push-Prev  1   # Pop off ?Stack-B? and push on predecessor (Default: Stack-A)
Push-Comp  1   # Pop off ?Stack-B? and push on complement  (Default: Stack-D)
Val-Delete 1   # Pop off (and lose) top value of ?Stack-B?
Val-Copy   1   # Duplicate the contents at the top of ?Stack-B?

# CPU:
#  Stack-A (Used in copying & math)
#  Stack-B (Used for positioning and math)
#  Stack-C (Input)      -- Filled on birth
#  Stack-D (Output)     -- Scanned (and emptied) on divide
#
# Four nops.  Each nop has a predecessor, successor and complement (opposite)
#
#  nop-A -> IP
#  nop-B -> Read Head
#  nop-C -> Write Head
#  nop-D -> Flow Head
#
# Note lack of allocate instruction!
# The organism has additional memory space that the write heads starts out
# at the beginning of.  It is treated as an extension of the main memory,
# BUT is local to each thread if there is more than one.

# SAMPLE ORGANISM:
#
# Search       #  1:  Find organism end.
# Nop-C        #  2:  - Match A:A
# Nop-C        #  3:
# Head-Push    #  4:  Save end position to Stack-B
# Nop-D        #  5:  - Flow head is at end...
# Push-Prev    #  6:  Move end position to Stack-A
# SetMemory    #  7:  Place write-head in memory space for offspring
# Search       #  8:  Drop flow head at start of copy loop
# Inst-Read    #  9:
# Inst-Write   # 10: 
# Head-Push    # 11:  Get current position of...
# Nop-C        # 12:  - Read-Head
# If-Equal     # 13:  Test if we are done copying...
# Divide       # 14:  ...If so, divide.
# Head-Move    # 15:  ...If not, continue with loop.
# Nop-A        # 16:
# Nop-A        # 17:

# Other possible, special instructions...
# ScanWorld  1   # Environment-specific scanning instruction...
# Val-Swap   1   # Swap top contents of ?Stack-A? with successor (Default: B)
                 #  Toggle will swap with complement.
# Inst-Copy  1   # Combine read and write
# Inst-Move  1   # Like Inst-Copy, but actually deletes original and can
                 #   move multiple lines at once (as indicated by ?Stack-B?)
# SearchOut  1   # Like search, but in faced creature.  Needs exact match!
# Rotate     1   # Rotate to neighbor with template (toggle reverses dir)
                 #   in mass action, find randomly in population.
# If-Bit-1   1   # Is last bit of ?Stack-B? a one? (toggle to If-Bit-0)
# If-Zero    1   # Toggle to If-N-Zero
# If-InstEqu 1   # Does contents of ?read-head? match successor (write-head)
                 #   (toggle to If-InstNEqu)
# Order      1   # Put top two numbers in ?Stack-B? into numerical order
# Push-Zero  1   # Push a zero onto the top of ?Stack-B?
# Replicate  1   # Make a full offspring

 
# ------- THREADING --------
# There can only be up to four threads in an organism, specified as
# Thead-A through Thread-D

# Hardware:
#  For threads, Stacks A and B are local, while C and D are global.
#  All heads are local to each thread.
#   - Read and Flow heads will initialize to fork.
#   - Write head will initialize on new offspring memory.
#  Each thread has its own offspring memory.
#  Each thread keeps its own list of toggled instructions.

# Instructions:
#  ThreadFork 1   # Create a new thread.  By default this will be the next
                  #   available thread ID, but if a nop follows it will
                  #   indicate the thread instead.  If a thread is specified
                  #   that already exists, its priority will increase to a
                  #   maximum.  On the original thread executes the next
                  #   instruction.  Toggle to ThreadKill ?cur-Thread?, which
                  #   will decrement a thread one step, to a min of 0.
#  If-Thread  1   # Only execute next instruction if this is ?Thread-A?
                  #   Toggle to IfNThread
#  ThreadCopy 1   # Make this thread an exact copy of ?Thread A? including
                  #   working on the same memory space.  Toggle to ThreadClr
                  #   which will reset the specifed thread (default current)

# SAMPLE PARASITE
#
# Nop-A        #  1: Some nop to extend the template above
# Toggle       #  2: Toggle the Divide command...
#  Divide      #  3:   ... to become "Inject"
# Toggle       #  4: Toggle the If-Equal command...
#  If-Equal    #  5:   ... to become "If-NEqual"
# Search       #  6: Locate the end, so we know when to stop.
# Nop-C        #  7:
# Nop-D        #  8:
# Head-Push    #  9: Save the location of the flow head to mark the end.
# Nop-D        # 10:
# Push-Prev    # 11:  Move end position to Stack-A
# SetMemory    # 12:  Claim and empty memory space
# Search       # 13:  Drop flow head at start of copy loop
# Inst-Read    # 14:
# Inst-Write   # 15: 
# Head-Push    # 16:  Get current position of...
# Nop-C        # 17:  - Read-Head
# If-Equal     # 18:  Test if we are done copying... (If-NEqual)
# Head-Move    # 19:  ...If not, continue with loop.
# Divide       # 20:  ...If so, Inject!
# Nop-C        # 21:     ... Into the very end of the host.
# Nop-C        # 22
# Head-Move    # 23: Go to the beginning of the copy loop and start over!
# Nop-A        # 24: End Template
# Nop-B        # 25:
</pre>