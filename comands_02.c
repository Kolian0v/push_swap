#include "push_swap.h"

void	*rotate_a(t_str *str)
{
	int	tmp;
	int	tmp2;
	int	i;

	if (!str->stack[0][0] || !str->stack[0][1])
		return (0);
	tmp = str->stack[0][0];
	tmp2 = str->stack[2][0];
	str->hiy[++str->num_move] = 5;
	i = -1;
	while (++i < str->const_end && str->stack[0][i])
	{
		str->stack[0][i] = str->stack[0][i + 1];
		str->stack[2][i] = str->stack[2][i + 1];
	}
	str->stack[0][i - 1] = tmp;
	str->stack[2][i - 1] = tmp2;
	return (0);
}

void	*rotate_b(t_str *str)
{
	int	tmp;
	int	tmp3;
	int	i;

	if (!str->stack[1][0] || !str->stack[1][1])
		return (0);
	i = -1;
	tmp = str->stack[1][0];
	tmp3 = str->stack[3][0];
	str->hiy[++str->num_move] = 6;
	while (++i < str->const_end && str->stack[1][i])
	{
		str->stack[1][i] = str->stack[1][i + 1];
		str->stack[3][i] = str->stack[3][i + 1];
	}
	str->stack[1][i - 1] = tmp;
	str->stack[3][i - 1] = tmp3;
	return (0);
}

void	*r_rotate_b(t_str *str)
{
	int	tmp;
	int	tmp3;
	int	i;

	if (!str->stack[1][0] || !str->stack[1][1])
		return (0);
	i = str->end[1] - 1;
	tmp = str->stack[1][i];
	tmp3 = str->stack[3][i];
	str->stack[1][i] = 0;
	str->hiy[++str->num_move] = 8;
	while (i > 0)
	{
		str->stack[1][i] = str->stack[1][i - 1];
		str->stack[3][i] = str->stack[3][i - 1];
		i--;
	}
	str->stack[1][0] = tmp;
	str->stack[3][0] = tmp3;
	return (0);
}

void	*r_rotate_a(t_str *str)
{
	int	tmp;
	int	tmp2;
	int	i;

	if (!str->stack[0][0] || !str->stack[0][1])
		return (0);
	i = str->end[0] - 1;
	tmp = str->stack[0][i];
	tmp2 = str->stack[2][i];
	str->stack[0][i] = 0;
	str->hiy[++str->num_move] = 7;
	while (i > 0)
	{
		str->stack[0][i] = str->stack[0][i - 1];
		str->stack[2][i] = str->stack[2][i - 1];
		i--;
	}
	str->stack[0][0] = tmp;
	str->stack[2][0] = tmp2;
	return (0);
}
