#include "push_swap.h"

int	check_zero(t_str *str)
{
	int	i;
	int	j;

	i = 0;
	while (str->stack[0][++i])
	{
		j = -1;
		while (++j < i)
			if (str->stack[0][i] == str->stack[0][j])
				return (1);
	}
	return (0);
}

void	parse_add(t_str *str)
{
	str->const_end = str->stack_end--;
	str->end[0] = str->stack_end;
	str->end[1] = 0;
	str->is_sovp = 0;
	str->num_move = -1;
	str->max[0] = str->stack_end;
	str->min[0] = 1;
	str->max[1] = 0;
	str->min[1] = 0;
	str->flag = 0;
}

int	ge_prs(t_str *str, int i)
{
	str->stack[0][i] = 0;
	str->stack[2][i] = 0;
	str->stack[3][i] = 0;
	str->stack[1][i] = 0;
	return (1);
}

int	parse(t_str *str, int ac, char **av)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	while (i < 100000)
		i += ge_prs(str, i);
	str->stack_end = ac;
	parse_add(str);
	while (str->stack_end--)
	{
		if (str->stack_end > 100000 || check_zero(str))
			exit (str_error("Error"));
		else
			str->stack[0][str->const_end - str->stack_end - 2]
				= ft_atoi(av[str->stack_end + 1]);
	}
	str->stack_end = str->const_end - 1;
	i = 0;
	while (i++ < str->const_end - 2)
	{
		if (str->stack[0][i - 1] < str->stack[0][i])
			point = 1;
	}
	return (point);
}

int	mid_chek(t_str *str, int mid)
{
	int	i;

	i = -1;
	while (str->stack[1][++i])
		if (str->stack[1][i] > mid)
			return (1);
	return (0);
}
