#include "push_swap.h"

void	duo(t_str *str, int u)
{
	if (str->stack[u][0] > str->stack[u][1])
		rotate_b(str);
}

void	rot_swap_b(t_str *str, int i)
{
	if (i == 0)
	{
		rotate_b(str);
		swap_b(str);
	}
	else
	{
		swap_b(str);
		rotate_b(str);
	}
}

void	trio(t_str *str, int u)
{
	if (str->stack[u][0] < str->stack[u][1] && str->stack[u][0]
		< str->stack[u][2])
	{
		if (str->stack[u][1] > str->stack[u][2])
			swap_b(str);
	}
	else if (str->stack[u][0] > str->stack[u][2] && str->stack[u][0]
		< str->stack[u][1])
		r_rotate_b(str);
	else if (str->stack[u][0] < str->stack[u][2] && str->stack[u][0]
		> str->stack[u][1])
		rot_swap_b(str, 0);
	else if (str->stack[u][0] > str->stack[u][1] && str->stack[u][0]
		> str->stack[u][2])
	{
		if (str->stack[u][1] < str->stack[u][2])
			rotate_b(str);
		else
			rot_swap_b(str, 1);
	}
}

int	sovo(t_str *str)
{
	int	i;

	if (str->stack[1][0])
		return (0);
	i = -1;
	while (str->stack[0][++i + 1])
	{
		if (str->stack[0][i] < str->stack[0][i + 1])
			return (0);
	}
	ft_write(str);
	exit(0);
}

void	sovop(t_str *str)
{
	int	i;

	i = -1;
	while (sovp(str))
	{
		if (sovp(str) == 1)
		{
			str->niz++;
			r_rotate_a(str);
		}
		if (sovp(str) == 2)
		{
			str->niz++;
			swap_a(str);
			r_rotate_a(str);
		}
		sovo(str);
		if (++i > str->stack_end - 1)
			break ;
	}
	sovo(str);
}
