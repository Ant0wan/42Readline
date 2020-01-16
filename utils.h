#ifndef UTILS_H
# define UTILS_H

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

#endif
