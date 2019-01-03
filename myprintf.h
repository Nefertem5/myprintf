#ifndef MYPRINTF_H
# define MYPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

/*
**	%[flags][width][.accur][size]specifier
*/

typedef struct	s_flags
{
	int plus:2;
	int minus:2;
	int zero:2;
	int space:2;
	int cage:2;
}				t_flags;

/*
**  L(l) = long int
**  HH(hh) = signed char
**  H(h) = short int
**  LL(ll) = long long int
**  LLL(L) = long double
*/

typedef enum 	s_size_modifier
{
	L = 1,
	HH = 2,
	H = 3,
	LL = 4,
	LLL = 5,
	NO = 0
}				t_size_modifier;

typedef struct	s_specifier
{
	t_flags				*flags;
	int					width;
	int					accur;
	t_size_modifier		size;
	char				specifier;
}				t_specifier;

/*
** structure for replace conversion
*/

typedef struct s_convert
{
	char	specifier;
	int		(*f)(va_list, t_specifier);
}				t_convert;


/*
** from get_specifier.c
*/

int			get_accur(char *fmt, int *i);
int			get_width(char *fmt, int *i);
int			get_sizemodifier(char *fmt, int *i);
int			get_spec(char *str, int *i);
t_flags		*get_flags(char *spec, int *i);

/*
** from convert.c
*/

int			ft_convert(t_specifier spec, va_list list);
t_specifier	*convert_big(t_specifier *spec);

/*
** from handle_char_and_str.c
*/

int			write_int(char c);
int			write_repeat_int(char c, int len);
int			handle_char(va_list list, t_specifier spec);
int			handle_str(va_list list, t_specifier spec);

/*
** from handle_int.c
*/

int			digit_len(long long a);
char		*utiltoa(long long a, char sign, t_specifier spec);
int			handle_int(va_list list, t_specifier spec);
long long	handle_size(va_list list, t_specifier spec);

/*
** from handle_float.c
*/


/*
** from myprintf.c
*/

t_specifier	*create_specifier(char *fmt, int *i);
int			check_spec(va_list list, int *counter, char *fmt);
int			ft_printf1(va_list list, char *format);
int			ft_printf(char *format, ...);

/*
** from utils.c
*/

int			is_valid_spec(t_specifier **sp, int	*done);
void		handle_error(int code, t_specifier **sp);
void		flag_undefined(char flag, char spec);
void		spec_del(t_specifier **sp);
int			ft_atoi_i(const char *str, int *result, int *i);

/*
** from valid.c
*/

int			is_flag(char c);
int			is_width(char c);
int			is_size(char c);
int			is_type(char c);
int			is_ok(char c);

#endif
