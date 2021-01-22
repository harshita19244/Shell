# Shell
File name: shell.c(Main file)
External files:
1. ls.c
1. mkdir.c
1. rm.c
1. cat.c
1. date.c

## Text files used:
1. his.txt(To append the output of the history command)
1. mkdir.txt(contains help information of the mkdir command)
1. pwd.txt(contains help information of the pwd command)
1. cd.txt(contains help information of cd command)
 
Makefile:Makefile

Makefile successfully used for compilation at each step:
1. Pre-Processing
1. Compilation
1. Assembly
1. Linking
The Makefile also successfully compiles each of the external c command files to be utilised
in shell.The program compiles successfully with no warnings.

## Options implemented in shell:
All options implemented in the shell suppourt default working and specified flags.
In order to see the working of the flags, kindly supply the commands in the syntax specified below.
1. cd: Changes the working directory from the current to the argument provided in the command.
Flags implememted:
* cd - L: Moves to the home directory.
* cd ~: Moves to the home directory.
* cd ..: Moves to the one directory up the level directory.
* cd /: Change to root directory.
* cd - help:Displays help information about the cd command.

1. pwd:Prints the current working directory
Flags implemented:
* pwd -L: Displays the current the working directory of the file, with symbolic links.
* pwd - help: Displays help information about the pwd command.

1. echo:Prints arguments to console
Flags implemented:
* echo -n [text]: Prints the specificied text on the console without a newline character.
* echo -e \a echo -e [text]: Prints the specificied text on the console with a newline character and
                    creates an alert sound.
* echo *: Behaves like ls and displays all files in a directory.

1. help: Prints all the current available commands in the shell.
  This command does not accept any flags.

2. history: Prints the commands executed in the shell in all executions of the shell.The 
history file contains data of execution corresponding to each run of the shell. 
NOTE:The commands are appended for a particular run of the shell after the shell has exited,
i.e after the loop has finished. After a run of the shell, we can view all the commands
executed throughout the shell.
Flags implemented:
* history - r: Appends the commands executed from the history file to the history list.
* history - c: Clears history of all commands executed.


3. mkdir:Creates a directory with the supplied name in the directory of execution of the shell.
Flags implemented:
* mkdir - help: Specifies the details of the mkdir command in the shell.
* mkdir - v [directoryname]: Creates a directory in the verbose mode, i.e prints a 
                            message after creation of each directory.
* mkdir name1 \b name2 \b name3: The given format is suppourted for creating a directory with spaces in name.
                                In this case, the \b acts an as an escape character for space.
                                The user can enter a maximum of three strings seperated by space and backslash(\b)
                                to create a directory with spaces in the title.

4. rm: Removes the specified file
Flags implemented:
* rm - d: Removes the directory(If the flag is not specified we can only remove files, not directories)
* rm - i [filename]: Removes files in the interactive mode. Prompts the user before the removal of every file. 
                    If the user types a "y" on the screen, the file is removed, otherwise not.

5. date: Prints the current date in day date time format
Flags implemented:
* date - u: This command displays the date in the UTC format.
* date - help: This command specifies the details of the date command, flags utilised 
               and arguments accepted.

6. cat: Prints the contents of the file specified by the user.
Flags implemented:
* cat - n [filename]: Displays the contents on the file on the console in a numbered format.
* cat - E [filename]: Displays a '$' at the end of each line of the file to display file termination.


7. ls:Lists all documents/files and directories present in the current working directory.
Flags implemented:
* ls - s: Lists the block size allocated to each file.
* ls - R: Lists all files and directories in recursive manner.


8. exit:Exits the shell with an exit status depending on successful/unsuccessful execution.
Flags implemented:
* exit [n]: Exits the shell with the value specified by the user.
* exit - help: Displays help information about the exit command.


## Error Handling:
In the following cases, errors are thrown as user messages:

1. If a user types a command that cannot be found in the shell:
  "No such command found in my_shell"

2. If a forking process fails and the parent fails to spawn the child process:
  "Fork failed"

3. In case if the user enters commands with unsuppourted flags in the shell:
  "Flag not found"

4. In case if the number of arguments suppiled is less than the requirement
  "Provide file or directory"

5. If the file supplied cannot be found in the directory:
  "No such file or directory found"
  
* Each of these errors have been handled for the options and their specified flags.
