The events file controls events that need to occur throughout the course of a run. This includes the output of data files as well as active events that effect the population (such as extinction events or changes to the mutation rate).

 

File Formats

This file consists of a list of events that will be triggered either singly or periodically. The format for each line is:

<code>type  timing  event  arguments</code>

The type determines what kind of timings the event will be based off of. This can be immediate [i], based on update [u], or based on generation [g].

The timing should only be included for non-immediate events. If a single number is given for timing, the event occurs at that update/generation. A second number can be included (separated by a colon ':') to indicate how often the event should be repeated. And if a third number is listed (again, colon seperated) this will be the last time the event can occur on. For example, the type and timing `u 100:100:5000` would indicate that the event that follows first occurs at update 100, and repeats every 100 updates thereafter until update 5000. A type timing of g 10:10 would cause the event to be triggered every 10 generations for the entire run.

The event is simply the name of the action that should be performed, and the arguments detail exactly how it should work when it is triggered. Each action has its own arguments. See the <a href="List-of-actions">List of Actions</a> for details about all of the available options.

Some examples:

<code>i Inject</code> 
Inject an additional start creature immediately.

<code>u 100:100 PrintAverageData </code>
Print out all average measurements collected every one hundred updates, starting at update 100.

<code>g 10000:10:20000 PrintData dom_info.dat update,dom_fitness,dom_depth,dom_sequence </code>
Between generations 10,000 and 20,000, append the specified information to the file dom_info.dat every ten generations. Specifically, the first column in the file would be update number, second is the fitness of the dominant genotype, followed by the depth in the phylogentic tree of the dominant genotype, and finally its genome sequence.

[List of Actions](List-of-actions)
