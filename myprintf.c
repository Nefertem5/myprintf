#include <myprintf.h>

int		ft_printf1(va_list list, const char *format)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (format[i])
	{
		if ()
		{

		}
		i++;
	}
	return (result);
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	int			print;

	va_start(list, format);
	print = ft_printf1(list, format);
	va_end(format);
	return (print);
}
