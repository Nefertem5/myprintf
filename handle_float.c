#include <myprintf.h>

long long	ft_pow(long long base, long long power)
{
	long long	i;
	long long	ret;
	long long	tmp;

	i = 0;
	ret = 1;
	while (i < power && i < 19)
	{
		tmp = ret;
		ret *= base;
		if (tmp > ret)
			return (tmp);
		i++;
	}
	return (ret);
}

void		int_to_str(int number, char *str, int *i, int j)
{
	int	a;

	a = 0;
	while (j-- && (*i)--)
	{
		str[*i] = number % 10 + '0'; 
		number /= 10;
		a++;
	}
	while (a > 0)
	{
		a--;
		(*i)++;
	}
}

char		*utilftoa(long double number, t_specifier spec, char sign)
{
	int			intpart;
	float		fpart;
	int			len;
	int			i;
	int			accur;
	int			sign_len;
	int			nmbr_zeros;
	char		*str;

	intpart = (int)number;
	fpart = number - (long double)intpart;
	if (fpart >= 0.5 && spec.accur == 0)
		intpart += 1;
	sign_len = (sign ? 1 : 0);
	len = digit_len((long long)intpart, 10);
	accur = 0;
	nmbr_zeros = 0;
	if (spec.accur > 0)
		accur = spec.accur;
	else if (spec.accur == 0 && spec.flags->cage == 1 && fpart == 0)
	{	
		len += 1;
		nmbr_zeros -= 1;
	}
	else if (spec.accur == 0)
	{
		accur = 0;
		nmbr_zeros -= 1;
	}
	else
		accur = 6;
	len += sign_len + accur;
	if (spec.flags->zero == 1 && (spec.width - len > 0) && spec.accur == 0)
		nmbr_zeros = spec.width - len + 1;
	else if (spec.flags->zero == 1 && (spec.width - len > 0) && spec.accur != 0)
		nmbr_zeros = spec.width - len;
	len += nmbr_zeros;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (sign_len != 0)
	{
		str[i] = sign;
		i++;
	}
	while (--nmbr_zeros > 0)
	{
		str[i] = '0';
		i++;
	}
	i += digit_len((long long)intpart, 10);
	int_to_str(intpart, str, &i, digit_len(intpart, 10));
	if (accur > 0 && fpart)
	{
		str[i] = '.';
		i++;
		fpart = fpart * ft_pow(10, accur);
		i += accur;
		int_to_str((int)fpart, str, &i, digit_len(fpart, 10));
	}
	else if (accur == 6)
	{
		str[i] = '.';
		i++;
		while (accur--)
			str[i++] = '0';
	}
	else if (spec.accur > 0)
	{
		str[i] = '.';
		i++;
		accur = spec.accur;
		while (accur--)
			str[i++] = '0';
	}
	else if (spec.flags->cage == 1)
		str[i] = '.';
	else if (!fpart)
		return (str);
	return (str);
}	

int			handle_float(va_list list, t_specifier spec)
{
	int			result;
	int			accur;
	int			i;
	long double	n;
	char		sign;
	char		*str;

	result = 0;
	i = 0;
	if (spec.size == L || spec.size == LLL)
		n = va_arg(list, long double);
	else
		n = va_arg(list, double);
	if (spec.flags->plus == 1)
		sign = '+';
	else if (spec.flags->space == 1)
		sign = ' ';
	else
		sign = 0;
	if (n < 0)
	{
		sign = '-';
		n *= -1;
	}
	str = utilftoa(n, spec, sign);
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
