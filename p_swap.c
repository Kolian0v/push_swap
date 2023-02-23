#include "push_swap.h"

void	push_sw(t_str *str)
{
	if (str->stack[1][2] && !str->stack[1][3])
	{
		trio(str, 1);
		repeat(str, 1, 3);
		sovo(str);
		if (sovp(str) == 1)
		{
			repeat(str, 3, 3);
			str->niz += 3;
		}
		sovo(str);
	}
	else if (str->stack[1][1])
	{
		duo_dou(str);
	}
	else
		push_a(str);
	sovop(str);
}

int	rot_push(t_str *str, int *i)
{
	sovop(str);
	flag_stels(str);
	*i = -1;
	return ((str->max[1] - str->min[1]) / 2 + str->min[1]);
}

void	push_rot(t_str *str)
{
	int	mid;
	int	i;
	int	x;

	x = str->end[1];
	while (str->stack[1][3])
	{
		mid = rot_push(str, &i);
		while (++i < x)
		{
			if (str->stack[1][str->end[1] - 1] > mid)
			{
				push_a(str);
			}
			else
				if (str->stack[1][1] && mid_chek(str, mid))
					r_rotate_b(str);
		}
	}
	push_sw(str);
}

void	push_reson_rot(t_str *str)
{
	int	i;
	int	mid;

	str->rrot = 0;
	i = -1;
	mid = (str->max[0] - (str->min[0] + str->niz)) / 2 + (str->min[0]
			+ str->niz);
	while (++i + str->niz < str->const_end)
	{
		if (str->stack[0][str->end[0] - 1] <= mid
			&& str->stack[0][str->end[0] - 1] != 1)
			push_b(str);
		else
		{
			str->rrot++;
			r_rotate_a(str);
		}
	}
	if (str->rrot < str->end[0] / 2)
		while (str->rrot--)
			rotate_a(str);
	else
		while (str->rrot++ < str->end[0])
			r_rotate_a(str);
}

int	push_swap(t_str *str)
{
	sovop(str);
	if (str->stack[2][str->end[0] - 1])
	{
		while (str->stack[2][str->end[0] - 1] == str->stack[2][str->end[0] - 2])
			push_b(str);
		push_b(str);
	}
	else
		push_reson_rot(str);
	push_rot(str);
	if (!spp(str))
		return (0);
	return (1);
}
