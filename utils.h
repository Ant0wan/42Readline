#ifndef UTILS_H
# define UTILS_H

# include "input.h"

int		output(int c);
int		rl_toupper(int c);
int		rl_tolower(int c);
int		isoctal(int c);
int		isxdigit(int c);
int		hexvalue(int c);
int		metachar(int c);
int		isprintchr(int c);
int		isstdkey(int c);
int		ismetachar(union u_buffer c);
int		isctrlkey(union u_buffer c);
int		mvctrlkey(union u_buffer c);
int		enter_rc(union u_buffer c);

#endif
