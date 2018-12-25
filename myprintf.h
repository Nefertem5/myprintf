#ifndef MYPRINTF_H
# define MYPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

/*
**	%[flags][width][.accur][size]type
*/

typedef struct	s_specifier
{
	int					flags;
	int					width;
	int					accur;
	t_size_modifier		size;
	char				*type;
}				t_specifier;

/*
**  L(l) = указатель на long int
**  HH(hh) = указатель на signed char
**  H(h) = указатель на short int
**  LL(ll) = указатель на long long int
*/

typedef enum 	s_size_modifier
{
	L = 1;
	HH = 2;
	H = 3;
	LL = 4;
	NO = 0;
}				t_size_modifier;	

/*
** from myprintf.c
*/

int		ft_printf(const char *format, ...);
int		ft_printf1(va_list list, const char *format);


/*
** from print.c
*/


/*
** from valid.c
*/

int		is_flag(const char c);
int		is_width(const char c);
int		is_size(const char c);
int		is_type(const char c);
int		is_ok(const char c);

#endif