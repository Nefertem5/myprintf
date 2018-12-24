#include <myprintf.h>

int		ft_printf1(va_list list, const char *format)
{
	int result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			
			format++;
		}
		format++;
	}
	return (result);
}

int		ft_printf(const char *format, ...)
{
	va_list	list;
	int		print;

	va_start(list, format);
	print = ft_printf1(list, format);
	va_end(format);
	return (print);
}
