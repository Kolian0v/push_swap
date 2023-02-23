#include "push_swap.h"

void	*swap_a(t_str *str)
{
	int	tmp;
	int	i;

	i = 0;
	if (!str->stack[0][0] || !str->stack[0][1])
		return (0);
	str->str1[++str->num_move] = 1;
	while (str->stack[0][i + 1])
		i++;
	tmp = str->stack[0][i];
	str->stack[0][i] = str->stack[0][i - 1];
	str->stack[0][i - 1] = tmp;
	tmp = str->stack[2][i];
	str->stack[2][i] = str->stack[2][i - 1];
	str->stack[2][i - 1] = tmp;
	return (0);
}

void	*swap_b(t_str *str)
{
	int	tmp;
	int	i;

	i = 0;
	if (!str->stack[1][0] || !str->stack[1][1])
		return (0);
	str->str1[++str->num_move] = 2;
	while (str->stack[1][i + 1])
		i++;
	tmp = str->stack[1][i];
	str->stack[1][i] = str->stack[1][i - 1];
	str->stack[1][i - 1] = tmp;
	tmp = str->stack[3][i];
	str->stack[3][i] = str->stack[3][i - 1];
	str->stack[3][i - 1] = tmp;
	return (0);
}

void	*push_b(t_str *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str->stack[0][0])
		return (0);
	str->str1[++str->num_move] = 4;
	while (str->stack[1][i])
		i++;
	while (str->stack[0][j])
		j++;
	str->stack[1][i] = str->stack[0][j - 1];
	str->stack[0][j - 1] = 0;
	str->stack[3][i] = 0;
	str->stack[2][j - 1] = 0;
	if (j < i + 1)
		str->stack_end++;
	else if (j > i + 1)
		str->stack_end--;
	str->end[0]--;
	str->end[1]++;
	check_maxin(str);
	return (0);
}

void	*push_a(t_str *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str->stack[1][0])
		return (0);
	str->str1[++str->num_move] = 3;
	while (str->stack[1][i])
		i++;
	while (str->stack[0][j])
		j++;
	str->stack[0][j] = str->stack[1][i - 1];
	str->stack[1][i - 1] = 0;
	str->stack[2][j] = str->stack[3][i - 1];
	str->stack[3][i - 1] = 0;
	if (j + 1 > i)
		str->stack_end++;
	else if (j + 1 < i)
		str->stack_end--;
	str->end[0]++;
	str->end[1]--;
	check_maxin(str);
	return (0);
}
