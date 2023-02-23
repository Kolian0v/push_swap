#include "push_swap.h"

void	flag_stels(t_str *str)
{
	int	i;

	i = -1;
	while (str->stack[1][++i])
		str->stack[3][i]++;
}

void	duo_dou(t_str *str)
{
	duo(str, 1);
	repeat(str, 1, 2);
	sovo(str);
	if (sovp(str) == 1)
	{
		repeat(str, 3, 2);
		str->niz += 2;
	}
	sovo(str);
}

void	pre_ps(t_str *str)
{
	int	mid;
	int	i;

	i = -1;
	mid = str->max[0] / 2 + str->min[0];
	while (++i < str->const_end - 1)
	{
		if (str->stack[0][str->end[0] - 1] <= mid)
			push_b(str);
		else
			r_rotate_a(str);
	}
	push_rot(str);
}

int	spp(t_str *str)
{
	int	i;
	int	t;

	t = 0;
	i = -1;
	while (++i < str->end[0] - 2)
	{
		if (str->stack[0][i] - 1 != str->stack[0][i + 1])
			t = 1;
	}
	if (str->stack[0][str->const_end - 2] && !(str->stack[0][i] - i == 0))
		t = 1;
	return (t);
}

int	main(int ac, char **av)
{
	t_str	str;

	if (ac < 2 || av[1][0] == '0')
		return (0);
	if (!parse(&str, ac, av))
		return (0);
	sovo(&str);
	men_const(&str);
	if (ac < 5)
		sovop(&str);
	if (ac == 5)
		trio_r(&str);
	if (ac == 6)
		less_6(&str);
	pre_ps(&str);
	while (1)
		if (!push_swap(&str))
			break ;
	ft_write(&str);
	return (0);
}
