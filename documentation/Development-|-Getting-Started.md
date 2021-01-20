These instructions will guide you through the process of setting up tools, obtaining the source code, building the suite, and provide an overview of the source code structure.

## Development Tools
Avida is a cross platform project designed to work on most POSIX-compliant systems, such as Linux, Mac OS X, Unix-variants, and Windows. You will need a development environment for your platform, such as GCC on Linux, Microsoft Visual Studio on Windows, and Apple Xcode on Mac OS X. The cross platform build system uses <a href="http://cmake.org">CMake</a>, version 2.6 or greater, to generate platform specific build files. In order to obtain the source code, you will need a recent copy of <a href="http://git-scm.com">Git</a>.

## Getting the Source Code
The Avida project uses multiple Git repositories to manage the source code. If you are new to Git, see <a href="http://avida.devosoft.org/devguide/using-git/">Using Git</a> for an overview of basic usage. When developing in Avida, you should always work from a working copy of the Git repository to ensure that you may stay up to date with recent changes. To clone the master Avida repository, move to the directory where you want to store the clone and run the following:
<pre>$ git clone https://github.com/devosoft/avida.git</pre>
Note, however, that the Avida project uses the Apto library linked as a submodule. You must initialize the submodule following the clone command above before you will be able to build the project:
<pre>$ cd avida
$ git submodule init
$ git submodule update</pre>
At this point you should be able to proceed to compiling. 

## Compiling
### Unix Command Line - CMake
You will need a copy of <a href="http://cmake.org/">CMake</a>.
<ol>
	<li>At the top level of the source code run the <code>./build_avida </code>script.</li>
        <ul><li>To compile the avida-viewer, use the flag <code>-DAVD_GUI_NCURSES</code> with <code>./build_avida</code></li></ul>
	<li>Change into the directory <code>cbuild/work</code></li>
	<li>The compiled executables (avida, avida-viewer), as well as the sample configuration files will be present in the work directory.</li>
</ol>
### Mac OS X - Xcode
<ol>
	<li>Open the Avida.xcodeworkspace file in the top level of the source code.</li>
	<li>Select the <em>avida</em> build scheme in the top left of the workspace window.</li>
	<li>Select menu option Product &gt; Archive</li>
	<li>"Distribute..." the archive, "Save Built Products"</li>
	<li>The archive contents will contain the executable in <kbd>/usr/local/bin/avida</kbd> and the example configuration files in <kbd>/usr/local/share/avida</kbd></li>
</ol>

### Windows - Visual Studio
<ol>
	<li>Open the CMake GUI</li>
	<li>Select the top level <em>avida</em> source code directory for the "Where is the source code" option.</li>
	<li>Specify a director to build the project files and binaries. It is recommended that you create a new empty directory for this path.</li>
	<li>Select your desired development system (Visual Studio version), if prompted or necessary.</li>
	<li>Click Configure twice, then click Generate to generate the project files.</li>
	<li>Open the generated Visual Studio solution file that should now be in your build folder.</li>
	<li>Build the solution (build the install target, don't use build all).</li>
	<li>You should find a <em>work</em> directory in your build folder containing the avida.exe and default configuration files.</li>
</ol>
Some other notes:
<ol>
	<li>In the options panel only APTO_LIB_SHARED, APTO_LIB_STATIC and AVD_CMDLINE should be 'On'. The viewer does not appear to build on Windows at the moment.</li>
	<li>Can't find the executable? Check the bin/DEBUG or bin/RELEASE directories.</li>
</ol>

## Project Structure
The Avida project master repository has been organized in the structure described below. This overview should help locate where the sub-projects you are interested in may be found. See specific sub-project pages for further information.

<dl><dt>Applications - <kbd>/apps</kbd></dt><dd><dl><dt>Mac OS Viewer - <kbd>/apps/viewer-macos</kbd> </dt><dd>Cocoa-based GUI application supporting Avida and Avida-ED</dd></dl></dd><dt>Avida Core - <kbd>/avida-core</kbd> </dt><dd>The <a href="http://avida.devosoft.org/devguide/projects/avida-core">avida-core</a> and <a href="http://avida.devosoft.org/devguide/projects/avida-viewer">avida-viewer</a> libraries. The heart of Avida.</dd><dt>Libraries - <kbd>/libs</kbd></dt><dd><dl><dt>Apto - <kbd>/libs/apto</kbd> <em>submodule</em></dt><dd>Apto C++ tools library. Data structures and cross-platform support layer.</dd></dl></dd></dl>

## Contributing to the Repositories
There are two main ways to contribute code changes to the repositories of the Avida project. The community at large is encouraged to fork the repositories on <a href="http://github.com/devosoft/avida/">GitHub</a> and to submit pull requests as appropriate. More details about using GitHub is available on their site.

Core developers who have been granted direct push access will need to utilize the authenticated remote repository path. The authenticated repository is <code>git@github.com:devosoft/avida.git</code>. If you are working from a standard clone of the source code, you may update your <em>push</em> URLs with the following commands:
<pre>$ git remote set-url --push origin git@github.com:devosoft/avida.git</pre>
