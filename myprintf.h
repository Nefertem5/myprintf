#ifndef MYPRINTF_H
# define MYPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

struct specifier
{
	char *sym;
	int (*f)(va_list);
};
typedef struct specifier specifier_t;


int		ft_printf(const char *format, ...);

#endif