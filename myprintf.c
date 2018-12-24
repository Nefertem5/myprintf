#include <myprintf.h>

int		ft_printf1(va_list list, const char *format, specifier_t spec_list[])
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
	va_list		list;
	int			print;

	specifier_t	spec_list[] = {
			{"c", print_char},
			{"$", print_proc},
			{"s", print_string},
			{"d", print_int},
			{"i", print_int},
			{NULL, NULL}
	};

	va_start(list, format);
	print = ft_printf1(list, format, spec_list);
	va_end(format);
	return (print);
}
