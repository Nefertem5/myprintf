#include <myprintf.h>

int is_flag(const char c)
{
	return (ft_strchr("-+ #0", c) != NULL);
}

int is_width(const char c)
{
	return (ft_strchr(".$*", c) != NULL);
}

int is_type(const char c)
{
	return (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL);
}

int is_size(const char c)
{
	return (ft_strchr("lh", c) != NULL);
}

int is_ok(const char c)
{
	return (is_size(c) || is_type(c) || is_width(c) || is_flag(c));
}