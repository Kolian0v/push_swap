#include "push_swap.h"

void	t(t_str *str)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	while (++i < str->stack_end)
	{
		j = -1;
		p = 1;
		while (++j < str->stack_end)
		{
			if (str->stack[0][i] == str->tp[0][j] && p)
			{
				str->stack[0][i] = str->tp[1][j];
				p = 0;
			}
		}
	}
}

void	tmp_const(t_str *str, int i)
{
	int	j;
	int	tmp;

	j = -1;
	while (++j < str->stack_end - i - 1)
	{
		if (str->tp[0][j] > str->tp[0][j + 1])
		{
			tmp = str->tp[0][j];
			str->tp[0][j] = str->tp[0][j + 1];
			str->tp[0][j + 1] = tmp;
		}
		else if (str->tp[0][j] == str->tp[0][j + 1])
			exit (str_error("Error"));
	}
}

void	men_const(t_str *str)
{
	int	i;

	i = -1;
	while (++i < str->stack_end)
	{
		str->tp[0][i] = str->stack[0][i];
		str->tp[1][i] = i + 1;
	}
	i = -1;
	while (++i < str->stack_end - 1)
		tmp_const(str, i);
	t(str);
}

void	trio_r(t_str *str)
{
	sovop(str);
	if (str->stack[0][3] != 1)
		push_b(str);
	else
	{
		swap_a(str);
		push_b(str);
	}
	sovop(str);
	if (str->stack[1][0] == 2)
	{
		sovop(str);
		r_rotate_a(str);
		sovop(str);
	}
	push_a(str);
	sovop(str);
}

void	less_6(t_str *str)
{
	int	i;
	int	mid;

	if (spp(str) || !str->stack[0][str->const_end - 2])
	{
		i = -1;
		mid = (str->max[0] + 1) / 2;
		while (++i < str->const_end - 1)
		{
			if (str->stack[0][str->end[0] - 1] <= mid)
				push_b(str);
			else
				r_rotate_a(str);
		}
		if (str->stack[0][str->end[0] - 1] == 5)
			swap_a(str);
		trio(str, 1);
		repeat(str, 1, 3);
		sovo(str);
		repeat(str, 3, 3);
		sovo(str);
	}
	ft_write(str);
	exit(0);
}
