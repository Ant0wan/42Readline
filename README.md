# 42Readline

ToDo:
- Signals -> SIGWINCH,...
- tputs padding settings
- g_tc.termcap binding instead of tgetstr
- VIM binding translator + vim_keymaps.c
- History file for each tty + `CTRL+R` + fc ?
- Autocompletion of files, bin, path,...

---

## REQUIREMENTS

Termcap lib:
`apt-get install libncurses-dev`

Termcap doc:
`apt-get install ncurses-doc`

---

## Description

### Command Line Features


Following are the Command Line Features :

1. Command History

History option enables recording of all the commands which are executed in the history list. You can use UP-arrow or DOWN-arrow keys to traverse the history list. You can traverse the history list and modify or execute the command.


2. Command Completion

Typing a letter (starting letter of the command) and pressing Tab key completes the command code. If more than one command code is registered starting with the typed letter, then all the matching ones are listed. Pressing the Tab key after entering the full command code displays the command syntax.


3. Command Line Editing

Commands can be edited from command line using LEFT arrow key, RIGHT arrow key, and \<DEL\> key.


4. Complete Command Syntax (oncoming feature)

Typing a command and pressing Tab key lists the complete command along with the usage for the command.

### Keyboard Shortcuts

https://www.howtogeek.com/howto/ubuntu/keyboard-shortcuts-for-bash-command-shell-for-ubuntu-debian-suse-redhat-linux-etc/


---
