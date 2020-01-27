#ifndef UTILS_H
# define UTILS_H

# include "input.h"

int		output(int c);
size_t		len(const char *str);
char		*savestring(const char *str);
char		*get_env_value(const char *name);
int		cmp(const char *s1, const char *s2);
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
int		enter_rc(union u_buffer c);
void		rl_bzero(void *s, size_t n);
char		*rl_strncpy(char *dst, const char *src, size_t len);

#endif
