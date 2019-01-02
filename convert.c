#include <myprintf.h>

t_specifier	*convert_big(t_specifier *spec)
{
	if (spec->specifier == 'D' || spec->specifier == 'S' ||
			spec->specifier == 'C' || spec->specifier == 'O' ||
			spec->specifier == 'U')
		spec->size = L;
	if (spec->specifier == 'D')
		spec->specifier = 'd';
	if (spec->specifier == 'S')
		spec->specifier = 's';
	if (spec->specifier == 'C')
		spec->specifier = 'c';
	if (spec->specifier == 'O')
		spec->specifier = 'o';
	if (spec->specifier == 'U')
		spec->specifier = 'u';
	return (spec);
}

int			ft_convert(t_specifier spec, va_list list)
{
	int	i;
	static t_convert	(convert[14]) = {
		{ .specifier = 's', .f = handle_str },
		{ .specifier = 'S', .f = handle_str },
		{ .specifier = 'c', .f = handle_char },
		{ .specifier = 'C', .f = handle_char },
		{ .specifier = 'd', .f = handle_char },
		{ .specifier = 'i', .f = handle_char },
		{ .specifier = 'x', .f = handle_char },
		{ .specifier = 'X', .f = handle_char },
		{ .specifier = 'p', .f = handle_char },
		{ .specifier = 'u', .f = handle_char },
		{ .specifier = 'U', .f = handle_char },
		{ .specifier = 'o', .f = handle_char },
		{ .specifier = 'b', .f = handle_char },
		{ .specifier = 'f', .f = handle_char }
	};

	i = -1;
	while (++i < 14)
	{
		if (spec.specifier == convert[i].specifier)
			return(convert[i].f(list, spec));
	}
	return (0);
}
