# Avida: Beginner User Documentation

As you’re beginning to use Avida to answer research questions, it can be easy to get lost in the extensive amount of variables and settings you can use in Avida. The purpose of this documentation is to identify the features that are most important for you to consider before running an experiment in Avida. For each feature, this documentation will explain what it controls, what options you have, and how and where you set those options.

## **1. Set up the environment.**
_Why you need to do this_

Setting up the environment tells Avida how big your universe is and what shape you want your universe to take. This will be important in determining a) the population cap for your experiment, b) how much (if any) empty space exists in your world, and c) how proportionally (or not) the organisms in your experiment have access to other organisms and resources. What you choose in this portion of the experiment will affect how organisms in your Avida universe interact with each other and, indirectly, the carrying capacity of your Avida universe.

_What you can do_

Avida allows you to customize both the world size and the world geometry. The world size determines the carrying capacity of your Avida world. In Avida (which is based on a grid system), each grid block can be occupied by only one Avida organism. So if you set the Avida grid height to 120 and the Avida grid width to 120, your Avida universe would have a carrying capacity of 14,400.

World geometry determines what shape your Avida grid will take. By default, the Avida universe is set to taking a toroidal (doughnut) shape. The creators of Avida chose this so that there are no edges in the universe and so that each organism has equal access to resources and neighbors. If, however, having boundaries and edges in your universe is important, you can change the shape of the Avida world to a bounded grid, hexagonal, random connected, and more. Details for what options exist for this setting and what they mean can be found in the avida.cfg file.

_Where to do it_

Both world size and world geometry are set in the avida.cfg file. World size is controlled by the WORLD_X and WORLD_Y controls; world geometry is controlled by the WORLD_GEOMETRY control. Similar to most grid systems, the width is controlled by the WORLD_X control and the height is controlled by the WORLD_Y control.

_How to do it_

To make changes to the default settings for world size and world geometry, 1) find the variables mentioned above in the avida.cfg file, 2) highlight and replace the current values with the ones you selected, and 3) save the file with your new changes.

## 2. Stock the environment with organisms.

_Why you need to do this_

An experiment can’t run without any organisms to evolve. If you don’t load an organism into the Avida config file, it would be like conducting a culture experiment— without any organisms in the petri dish.

_What you can do_

Avida comes with a number of different organisms you can use to populate your Avida world. Most experiments will use the basic Avida organism (default­heads.org). This organism is haploid and asexual. For your first Avida experiments, it is highly recommended that you use the basic Avida organism. Only if your experiment explicitly calls for a different organism should you consider using a different Avida organism.

_Where to do it_

Organisms are stocked (or “injected”) into Avida in the events.cfg file. The command that controls what organisms are injected is the “Inject” function located here.

![Events File Screenshot](http://devosoft.org/wp-content/uploads/2015/08/EventsFile2.png)

_How to Do it_

By default, Avida will inject the basic Avida organism (default­heads.org). Unless you are changing this to a different organism, feel free to leave the file as­is.

## 3. Decide how organisms will be born and how organisms will die.

_Why you need to do it_

The functions described in this setting give you control over how organisms enter and leave your Avida universe. Birth method determines where on the Avida grid new organisms are placed. Having control over this function allows you to mimic biological communities (if that’s important to your experiment) or to decide how organisms are dispersed across the Avida universe.

Death method allows you to determine whether organisms in your world can die from old age or not. This distinction may be crucial for experiments that investigate longevity issues. Population cap controls determine how many organisms are allowed to exist in your Avida universe and, if the population cap is reached, the population cap eldest control will determine if a) the oldest organism in the universe dies or b) a random organism from the universe dies.

_What you can do_

When it comes to placing new organisms in your Avida world, the birth method feature in Avida gives you a few options for where those organisms are placed. By default, new organisms are placed randomly onto the Avida grid. You can change this option, however, via the eleven birth method options found in the avida.cfg file next to the BIRTH_METHOD control. Some options include having new organisms facing the parent organism, replacing the oldest age in the neighborhood, or replacing the oldest within the entire population.

The death method setting allows you to decide if an organism in your Avida world can die of old age or not. Avida has one setting for turning off this function— meaning that an organism will never die of old age. Avida has another setting for turning this function on, meaning that organisms who complete a certain number of instructions (i.e., AGE_LIMIT) will die.

The population cap controls allow you to set a limit on how many organisms can exist in your Avida universe. While this is also partially controlled by the world size (see explanation in Step 1), the population cap can allow you to set an even smaller population maximum in your Avida world if having space and empty squares on the Avida grid is important to you. For example, let’s say I set my Avida world size to be 60 units high and 60 units wide. This would mean that I have set a de facto population cap of 3,600 (60 X 60) because Avida will only allow one organism to occupy a grid cell.

But this also means that, unless other factors (such as competition or a population cap) come into play, the population will continue growing until it fills each of the 3,600 cells. IF, however, I wanted there to be some extra space protected in the Avida world— if my experiment called for there to be extra room between organisms — I could set a population cap of 3,000 organisms. This means that, no matter how large my world is, there will only ever be a maximum 3,000 organisms in the Avida universe. Setting a population cap allows you to protect empty space and/or to keep a more precise control over your maximum potential population size.

Similarly, Avida allows you some flexibility over what happens to your Avida organisms when the population cap is reached. You can choose to a) kill off the oldest organism in the population or b) kill off a random member of the population. This choice is more or less critical depending on your research question(s), but should be thought over carefully when setting up your Avida experiment.

_Where you do it_

The birth method and death method settings are found in the reproduction section of the avida.cfg file. Birth method is controlled by the BIRTH_METHOD variable and the death method is controlled by the DEATH_METHOD variable. Controls for the population cap settings, including POPULATION_CAP and POP_CAP_ELDEST, are located in the “general group” section of the avida.cfg file.

_How you do it_

To change Avida’s birth method (i.e., where new organisms are placed in the Avida grid), choose the option you would prefer from the avida.cfg documentation (located next to the BIRTH_METHOD control). Highlight and replace the pre­selected option (in this case, number 7) with the option you would prefer for your experiment. Be sure to save the file with your changes.

To change the death method, locate the DEATH_METHOD variable in the avida.cfg file. By default, Avida is set to death method setting 2, which has a death­by­old­age feature. If you wish to turn this off, highlight and replace the 2 with a 0 (0 is the setting for no death by old age). If you wish to have organisms die from old age, keep the file the same.

To set a population cap, find the POPULATION_CAP control in the avida.cfg file, highlight the 0 (Avida defaults to 0/no population cap), and replace it with your population cap number (from our example above, this would be 3000). Do not use commas when writing in your population cap number in Avida. Once you’ve made your changes, save the avida.cfg file.

The POP_CAP_ELDEST control works by entering in either a 0 (default) or 1 after the control name in the avida.cfg file. Select 0 for a random organism or 1 for the oldest organism to die if the population reaches the carrying capacity (i.e., population cap) you set for the population in the previous step.

## 4. Stock the environment with resources.

_Why you need to do this_

Just like in biological systems, Avida works by using competition for resources as a motivation for organisms to evolve characteristics that help them secure more resources and, thus, make them more likely to reproduce. In Avida, you have some control over how many resources are available to organisms in your experiment as well as how evenly (or not) those resources are distributed across the Avida grid.

_What you can do_

By default, resources in Avida are infinite and undepletable. This means that there is never a shortage of a resource and that organisms are competing to acquire the most resources out of the infinite resource pool. They are not competing against each other for a limited number of resources. Furthermore, resources are, by default, dispersed evenly within the Avida environment. This means that there is no clustering of resources in a particular area. Organisms placed anywhere on the Avida grid will have equal access to resources.

While most experiments work well with the default settings, you can change both the amount of resources available (i.e., create a depletable resource) or the dispersal pattern of the resources (i.e., create high and low resource concentration areas) to better answer your research questions.

_Where you do this_

Any changes to the default settings of infinite and evenly dispersed resources are made in the environment.cfg file.
How you do this
Since most experiments don’t require changes to the default settings, changing the dispersal pattern and/or limiting the availability of resources requires more complex instructions. Those instructions, along with more description about what options are available to you, are located on the Avida documentation wiki [here](https://github.com/devosoft/avida/wiki/Environment-file).

## 5. Decide what task(s) organisms will use to compete for resources and how they will/will not be rewarded for those tasks.

_Why you need to do this_

In Avida, organisms complete logic functions to increase their merit. The more merit an organism in Avida has, the more CPU cycles it will receive. This means that the organism can reproduce faster and, eventually, become a more fit organism. As a researcher, you get to make choices about what logic tasks organisms in your Avida world will be asked to complete and how they will/will not be rewarded for completing these tasks. This will impact what types of behavior(s) you see evolving during your experiment.

_What you can do_

It is important that you decide 1) what kinds of logic tasks organisms in your experiment(s) will be asked to complete, 2) how organisms in your experiment will be rewarded for completing those various tasks, and 3) how an organism’s merit gets added to its pre-­existing merit when it successfully completes a logic task.

### Kinds of logic tasks

By default, Avida will ask the organisms in your experiment to complete a series of nine logic tasks. This is often referred to in the Avida literature as the “default logic­9 environment.” These nine logic tasks are listed in the environment.cfg file and move from relatively simple functions to more complex functions. For most experiments, the default logic­9 environment provides a sufficiently complex environment. You can make the environment more complex, however, by adding additional logic tasks. There is a logic­77 environment that adds such complexity but, again, most experiments work successfully with the default logic­9 environment.

Conversely, if you’re not really interested in looking at tasks or looking at evolved behavior, you can remove some logic tasks or remove the logic tasks all together. This can make your data easier to analyze and will prevent you from having to factor in evolvability later on in your experiment.

### How organisms are rewarded
Avida allows you to control how organisms are rewarded for completing logic tasks. For every different logic task you ask your organisms to complete, you get to decide a point value reward for completing that task. By default, simple logic tasks receive less reward points than the more complex logic tasks. This is to ensure that organisms have sufficient motivation to attempt to complete the more complicated logic tasks. You can choose, however, to undo this default setting and reward all tasks the same. If you were interested in how a particular behavior evolves you could arbitrarily set the reward value for a certain function significantly higher and see how that impacts evolution. Because the options here are endless, it’s important to keep your research question(s) in mind when deciding how rewards are distributed in Avida.

### How an organism’s merit is accumulated

Every time an organism in Avida completes a logic task, it receives increased merit. You have to decide how that newly earned merit will be combined with the organism’s previously accumulated merit. By default, an organism’s merit increases exponentially. This encourages organisms to spend time solving more complicated logic tasks (even though they take more time) because the reward for completing those tasks is exponentially higher than the reward they would receive from completing simpler logic tasks. This also prevents an organism that completes many simple logic tasks from acquiring more merit than an organism who completes a few difficult logic tasks.

While most experiments find the default settings to be a conducive way of encouraging the evolution of more complicated behavior, there are other settings that may be more appropriate for your particular research goals. More information about what other options are available and how they can be used in your experiment is located on the Avida documentation wiki [here](https://github.com/devosoft/avida/wiki/Environment-file).

_Where you can do it_

All of the settings for logic tasks and task reward are located in the environment.cfg file. When you open the file, you will see the nine default logic tests laid out as in the following example:

`REACTION NOT not process:value=1.0:type=pow requisite:max_count=1`

Each line that starts with REACTION marks a different logic task. The variables listed after REACTION in each line determine the reward value, type, and restrictions for that logic task. Here’s an example of how to read these variables.

In the examples above “NOT” would be the name of the logic task and “not” would be the type of logic task (often, these are the same). So this tells you that this logic function is named “NOT” and will ask the organisms in your experiment to solve a logic problem that requires them to complete a “not” logic task. (In Avida, this would be an organism correctly knowing to convert the sequence 001101 to 110010).

The “process:value=1.0:type=pow” is the part of the REACTION line that determines how much merit an organism receives for completing that task and how that merit gets added to the organism’s pre­existing merit. The “value=1.0” part of the code assigns how much reward value (i.e., increased merit) an organism would receive from successfully completing that task. In this case, an organism gets 1.0 merit points for completing the task. The “type=pow” part of the code determines how newly earned merit from completing this task will be combined with the organism’s pre­existing merit. In this example, an organisms merit is increased exponentially (the “pow” stands for power). This would mean that an organism would receive a 2^bonus or 2^1 for completing this task.

The final part of this REACTION line— “requisite:max_count=1” — sets a limit for how many times an organism can receive increased merit from completing this task. By default, this is set to 1, meaning that an organism would only receive increased merit the first time it completed that logic task. After that, the organism would not receive increased merit from repeating the same function. While this default setting encourages organisms to attempt increasingly complex behaviors, it may not work for all experiments and can be replaced with any value you choose. If your experiment requires that there is no merit cap on a particular logic function, you can delete the max_count=1 function completely so that the new code would read:

`REACTION NOT not process:value=1.0:type=pow`

_How you do it_

As we’ve seen in other portions of the Avida program, you make changes to these settings by highlighting the default value you wish to change and replacing it with your new value. For example, if I wanted to change how much merit an organism received from completing the NOT function in my experiment, I would highlight the source code where it says “1.0” and replace it with a higher value, such as “2.0” so that the final code would read like this (*'s to show changes):

`REACTION NOT not process:value=**2.0**:type=pow requisite:max_count=1`

If I also wanted to have the merit an organism receives from completing the NOT function to be
added to their previous merit (as opposed to being increased exponentially), I would highlight 7
where it says “pow” in the documentation and replace it with “add.” Again, the new REACTION line would read like this:

`REACTION NOT not process:value=2.0:type=**add** requisite:max_count=1`

If your experiment calls for less logic functions, you can delete a logic task by highlighting and
deleting the undesired logic task. Be sure to delete the _entire_ line, not just part of the command.

It is also important that you not change either the task name (i.e., NOT) or task type (i.e., not) in the environment.cfg file. This will cause an error with your experiment. When you are done editing this file remember to save your changes.

## 6. Decide how long your experiment will last.

_Why you need to do this_

By default, Avida will run an experiment for 100,000 updates, where 10 updates are roughly equal to 1 generation. Depending on what type of experiment you’re doing, you may want to lengthen or shorten the default experiment run­time. Setting the experiment update time is like deciding how long you want a certain bacteria to culture and/or how many generations of fruit flies you’re going to analyze. Shorter experiment times in Avida will take less time and will be much less data to analyze and store; however, longer experiments will allow you to see more long­term
evolutionary patterns and population dynamics.

_Where to do this_

The variable that controls the experiment length is located in the event.cfg file and is labeled “EXIT” (will be located near the bottom of the file).

![Events File](http://devosoft.org/wp-content/uploads/2015/08/EventsFile2.png)

_How to do this_

You can change the experiment update length by selecting the number 100000 and replacing it by typing in any positive whole number you select. Be sure to save the file before closing to update your changes.

## 7. Decide what types of data you will collect from your experiment.

_Why you need to do this_

Avida can collect and print a number of different types of data reports on any experiment. Depending on what your experiment is investigating, different types of data reports may or may not be as useful to you in answering your research question(s). Some of these data files are complex, take a long time to print, and use up a lot of computing/memory power on your device. Therefore, you can save yourself a lot of time and technological resources by intentionally selecting only the files you need Avida to print from your experiment.

In addition to selecting what files to print, it is also important to select the frequency at which Avida prints your data files. By default, Avida prints a complete set of data files after every 100 updates for the entire duration of your experiment. Depending on how long your experiment lasts and/or if you’re looking at short­term or long­term evolutionary patterns, this default print frequency might not make sense for your research.

_What you can do_

The types of data files Avida can print are split into two groups: standard data files and non­standard data files. The standard data files are printed by default in Avida and will save basic data about what is happening in your experiment (more information about what is collected in each of the standard data files is located in the events.cfg file).

The non­standard data files keep track of more nuanced and specific data. These files are not printed by default in Avida. Because these files often require that Avida make more calculations, these files take up more computational/memory space on your device. Therefore, it is recommended that you only print the non­standard data files that are essential to your experiment. Most experiments, especially at the beginner level, do not require any additional data files from the non­standard data files group.

Avida also gives you a lot of control over when and how often the program prints data files. In particular, you can control three factors: 1) when Avida starts printing data files, 2) how many update cycles between data file printing, and 3) when Avida stops printing data files.

You can choose any update cycle to begin and end data collection, and can print data files as frequently (i.e., every 10 updates) or infrequently (i.e., every 10,000 updates) as needed.

_Where you can do this_

All settings to control data file printing are found in the events.cfg file. The standard data files are grouped together towards the beginning of the document and the non­standard data files are group together towards the end of the document. The print timing and frequency controls are located next to each data file in this document.

_How you can do this_

Each data file is listed in the events.cfg file like this:

 `u 0:100:end PrintAverageData`

To turn a data file on (i.e., print the file) remove the # from before the file name. Notice that the files in the standard file group don’t have a # at the beginning of the file name; that’s because they are printed (turned on) by default. If you choose to not print a certain data file, add a # to the beginning of the file name that you wish to turn off. For example, if you didn’t want to print the PrintAverageData file, you would insert an # before the u (i.e., `# u 0:100:end PrintAverageData`). The non­standard data files do have a # before their file name (i.e., `# u 100:100:end PrintTotalsData`). This means that, unless you remove the #, that file will not print.

When Avida starts printing data, how often Avida prints a data file, and when Avida ends printing data are controlled by the three variables within colons. Taking our example from above,

`u 0:100:end PrintAverageData`

the “0” would be when Avida starts printing this data file (i.e., at the 0th update), the “100” would be the frequency at which Avida prints this data file (i.e., every 100 updates), and the “end” would be when Avida stops printing this data file (i.e., when the experiment ends). Re­writing this example to the following,

`u: 100:1000:10000 PrintAverageData`

would tell Avida to a) start printing this file at the 100th update, b) print this data file every 1,000 updates, and c) stop printing this file at 10,000 updates (even if the experiment is still running).

This documentation was produced by Rebecca Zantjer with consultation from members of the Devolab.