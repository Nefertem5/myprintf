#include <myprintf.h>

long long	handle_size(va_list list, t_specifier spec)
{
	long long	size;

	if (spec.size == L)
		size = va_arg(list, long);
	else if (spec.size == LL)
		size = va_arg(list, long long);
	else
		size = va_arg(list, int);
	if (spec.size == HH)
		size = (char)size;
	else if (spec.size == H)
		size = (short)size;
	return (size);
}

int			digit_len(long long a)
{
	int i;

	i = 0;
	if (a == 0)
		return (1);
	while (a)
	{
		i++;
		a /= 10;
	}
	return (i);
}

char		*utiltoa(long long a, char sign, t_specifier spec)
{
	char	*str;
	int		len;
	int		sign_len;
	int		accur;
	int		nmbr_zeros;

	len = digit_len(a);
	accur = 0;
	if (spec.accur > len)
		accur = spec.accur;
	nmbr_zeros = 0;
	if (accur > len)
		nmbr_zeros = accur - len;
	else if (!accur && spec.flags->zero == 1)
		nmbr_zeros = spec.width - len;
	sign_len = (sign ? 1 : 0);
	len = len + sign_len + nmbr_zeros;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = a % 10 + '0';
		a /= 10;
	}
	if (sign_len != 0)
		str[0] = sign;
	return (str);
}

int			handle_int(va_list list, t_specifier spec)
{
	int				result;
	int				i;
	int				accur;
	long long		number;
	char			sign;
	char			*str;

	result = 0;
	i = 0;
	number = handle_size(list, spec);
	if (spec.flags->plus == 1)
		sign = '+';
	else if (spec.flags->space == 1)
		sign = ' ';
	else
		sign = 0;
	if (number < 0)
	{
		sign = '-';
		number *= -1;
	}
	if (spec.accur > 0 && spec.flags->zero == 1)
		spec.flags->zero = 0;
	str = utiltoa(number, sign, spec);
	accur = ft_strlen(str);
	if ((spec.flags->minus != 1) && spec.width > accur)
		result += write_repeat_int(' ', spec.width - accur);
	while (str[i] != '\0' && accur > 0)
	{
			result += write_int(str[i]);
			i++;
			accur--;
	}
	if ((spec.flags->minus == 1) && spec.width > accur)
		result += write_repeat_int(' ', spec.width - accur - i);
	return (result);
}
