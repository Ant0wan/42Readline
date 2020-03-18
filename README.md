# 42Readline

42Readline is a library [a 42 side-project] coded in C and providing a set of functions for use by applications that allow users to edit command lines as they are typed in. Both Emacs and Vi editing modes are available. The Readline library includes additional functions to maintain a list of previously-entered command lines, to recall and perhaps reedit those lines, and perform csh-like history expansion on previous commands.

---

## Requirements

Termcap lib:
`apt-get install libncurses-dev`

Termcap doc:
`apt-get install ncurses-doc`

---

## Description

### Command Line Features

Following are the Command Line Features :

1. Command History

> History option enables recording of all the commands which are executed in the history list. You can use UP-arrow or DOWN-arrow keys to traverse the history list. You can traverse the history list and modify or execute the command.


2. Command Completion

> Typing a letter (starting letter of the command) and pressing Tab key completes the command code. If more than one command code is registered starting with the typed letter, then all the matching ones are listed. Pressing the Tab key after entering the full command code displays the command syntax.


3. Command Line Editing

> Commands can be edited from command line using LEFT arrow key, RIGHT arrow key, and \<DEL\> key.


### Keyboard Shortcuts

- #### Working With Processes

> Use the following shortcuts to manage running processes.

`Ctrl+C` Interrupt (kill) the current foreground process running in in the terminal. This sends the SIGINT signal to the process, which is technically just a request—most processes will honor it, but some may ignore it.

`Ctrl+Z` Suspend the current foreground process running in bash. This sends the SIGTSTP signal to the process. To return the process to the foreground later, use the fg process_name command.

`Ctrl+D` Close the bash shell. This sends an EOF (End-of-file) marker to bash, and bash exits when it receives this marker. This is similar to running the exit command.

- #### Controlling the Screen

> The following shortcuts allow you to control what appears on the screen.

`Ctrl+L` Clear the screen. This is similar to running the “clear” command.

- #### Moving the Cursor

> Use the following shortcuts to quickly move the cursor around the current line while typing a command.

`Ctrl+A` or `Home` Go to the beginning of the line.

`Ctrl+E` or `End` Go to the end of the line.

`Alt+B` Go left (back) one word.

`Ctrl+B` Go left (back) one character.

`Alt+F` Go right (forward) one word.

`Ctrl+F` Go right (forward) one character.

`Ctrl+XX` Move between the beginning of the line and the current position of the cursor. This allows you to press Ctrl+XX to return to the start of the line, change something, and then press Ctrl+XX to go back to your original cursor position. To use this shortcut, hold the Ctrl key and tap the X key twice.
