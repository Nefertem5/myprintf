#include <myprintf.h>

int ft_write(const char *str, const size_t size)
{
	write(1, str, size);
	return (size);
}

int	print_string(va_list list, t_specifier spec)
{
	
}
