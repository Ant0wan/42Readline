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

#### Working With Processes

> Use the following shortcuts to manage running processes.

`Ctrl+C` Interrupt (kill) the current foreground process running in in the terminal. This sends the SIGINT signal to the process, which is technically just a request—most processes will honor it, but some may ignore it.

`Ctrl+Z` Suspend the current foreground process running in bash. This sends the SIGTSTP signal to the process. To return the process to the foreground later, use the fg process_name command.

`Ctrl+D` Close the bash shell. This sends an EOF (End-of-file) marker to bash, and bash exits when it receives this marker. This is similar to running the exit command.


#### Controlling the Screen

> The following shortcuts allow you to control what appears on the screen.

`Ctrl+L` Clear the screen. This is similar to running the “clear” command.


#### Moving the Cursor

> Use the following shortcuts to quickly move the cursor around the current line while typing a command.

`Ctrl+A` or `Home` Go to the beginning of the line.

`Ctrl+E` or `End` Go to the end of the line.

`Ctrl+Left Arrow` Go left (back) one word.

`Ctrl+B` of `Left Arrow` Go left (back) one character.

`Ctrl+Right Arrow` Go right (forward) one word.

`Ctrl+F` of `Right Arrow` Go right (forward) one character.

`Ctrl+XX` Move between the beginning of the line and the current position of the cursor. This allows you to press Ctrl+XX to return to the start of the line, change something, and then press Ctrl+XX to go back to your original cursor position. To use this shortcut, hold the Ctrl key and tap the X key twice.


#### Deleting Text

> Use the following shortcuts to quickly delete characters.

`Ctrl+D` or `Delete` Delete the character under the cursor.

`Ctrl+H` or `Backspace` Delete the character before the cursor.


#### Fixing Typos

> These shortcuts allow you to fix typos and undo your key presses.

`Alt+T` Swap the current word with the previous word.

`Ctrl+T` Swap the last two characters before the cursor with each other. You can use this to quickly fix typos when you type two characters in the wrong order.

`Ctrl+_` (not yet implemented) Undo your last key press. You can repeat this to undo multiple times.


#### Cutting and Pasting

> Bash includes some basic cut-and-paste features.

`Ctrl+W` Cut the word before the cursor, adding it to the clipboard.

`Ctrl+K` Cut the part of the line after the cursor, adding it to the clipboard.

`Ctrl+U` Cut the part of the line before the cursor, adding it to the clipboard.

`Ctrl+Y` Paste the last thing you cut from the clipboard. The y here stands for “yank”.


#### Tab Completion

> Tab completion is a very useful bash feature. While typing a file, directory, or command name, press Tab and bash will automatically complete what you’re typing, if possible. If not, bash will show you various possible matches and you can continue typing and pressing Tab to finish typing.

`Tab` Automatically complete the file, directory, or command you’re typing.


#### Working With Command History (need tests)

> Quickly scroll through your recent commands, which are stored in your user account’s bash history file.

`Ctrl+P` or `Up Arrow` Go to the previous command in the command history. Press the shortcut multiple times to walk back through the history.

`Ctrl+N` or `Down Arrow` Go to the next command in the command history. Press the shortcut multiple times to walk forward through the history.

`Alt+R` Revert any changes to a command you’ve pulled from your history if you’ve edited it.

> Bash also has a special “recall” mode you can use to search for commands you’ve previously run.

`Ctrl+R` Recall the last command matching the characters you provide. Press this shortcut and start typing to search your bash history for a command.

`Ctrl+O` Run a command you found with Ctrl+R.

`Ctrl+G` Leave history searching mode without running a command.
