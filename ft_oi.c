#include "push_swap.h"

void	ft_strnum(int e)
{
	char	s[100];
	int		i;

	i = -1;
	while (++i < 100)
		s[i] = 0;
	i = 0;
	while (e)
	{
		s[i++] = e % 10 + '0';
		e = e / 10;
	}
	while (i--)
		write(1, &(s[i]), 1);
}

int	w_write(t_str *str, int i)
{
	if (str->hiy[i] == 1)
		write(1, "sa\n", 3);
	if (str->hiy[i] == 2)
		write(1, "sb\n", 3);
	if (str->hiy[i] == 3)
		write(1, "pa\n", 3);
	if (str->hiy[i] == 4)
		write(1, "pb\n", 3);
	if (str->hiy[i] == 5)
		write(1, "rra\n", 4);
	if (str->hiy[i] == 6)
		write(1, "rrb\n", 4);
	if (str->hiy[i] == 7)
		write(1, "ra\n", 3);
	if (str->hiy[i] == 8)
		write(1, "rb\n", 3);
	if (str->hiy[i] == 9)
		write(1, "rr\n", 3);
	if (str->hiy[i] == 10)
		write(1, "rrr\n", 4);
	if (str->hiy[i] == 11)
		write(1, "ss\n", 3);
	return (1);
}

void	ft_write(t_str *str)
{
	int	i;

	i = str->stack_end - 1;
	prosto(str);
	i = 0;
	while (str->hiy[i])
		i += w_write(str, i);
}
