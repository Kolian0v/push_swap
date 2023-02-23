#include "push_swap.h"

void	check_maxin_do(t_str *str, int i)
{
	str->max[1] = 0;
	while (str->stack[1][++i])
		if (str->max[1] < str->stack[1][i])
			str->max[1] = str->stack[1][i];
	str->min[1] = 100000;
	i = -1;
	while (str->stack[1][++i])
		if (str->min[1] > str->stack[1][i])
			str->min[1] = str->stack[1][i];
	str->max[0] = 0;
	while (str->stack[0][++i])
		if (str->max[0] < str->stack[0][i])
			str->max[0] = str->stack[0][i];
	str->min[0] = 100000;
	i = -1;
	while (str->stack[0][++i])
		if (str->min[0] > str->stack[0][i])
			str->min[0] = str->stack[0][i];
}

void	check_maxin(t_str *str)
{
	int	i;

	i = -1;
	if (!str->stack[1][0])
	{
		str->max[1] = 0;
		str->min[1] = 0;
		str->max[0] = str->stack_end - 1;
		str->min[0] = 1;
	}
	else
		check_maxin_do(str, i);
}
