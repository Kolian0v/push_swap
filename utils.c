#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	atio_dop(unsigned int i, const char *str, long *sign)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long			res;
	long			sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	i = atio_dop(i, str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i])
		exit (str_error("Error"));
	if (res * sign > 2147483647 || res * sign < -2147483648)
		exit (str_error("Error"));
	return ((int)(res * sign));
}

int	sovp(t_str *str)
{
	if (str->stack[0][str->end[0] - 2] - 1 == str->stack[0][0]
	|| str->stack[1][str->end[1]] == 1)
		return (2);
	else if (str->stack[0][str->end[0] - 1] == 1 && spp(str))
		return (1);
	else if (str->stack[0][str->end[0] - 1] - 1 == str->stack[0][0])
		return (1);
	else
		return (0);
}

int	str_error(char *s)
{
	write(1, s, ft_strlen(s));
	return (0);
}
