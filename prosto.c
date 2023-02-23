#include "push_swap.h"

void	moves(t_str *str, int i)
{
	str->num_move -= 2;
	str->str1[i] = -1;
	str->str1[i + 1] = -1;
}

void	lot_ifs(t_str *str, int i)
{
	if ((str->str1[i] == 5 && str->str1[i + 1] == 7) || (str->str1[i] == 7
			&& str->str1[i + 1] == 5))
		moves(str, i);
	if ((str->str1[i] == 6 && str->str1[i + 1] == 8) || (str->str1[i] == 8
			&& str->str1[i + 1] == 6))
		moves(str, i);
	if (str->str1[i] == 1 && str->str1[i + 1] == 1)
		moves(str, i);
	if (str->str1[i] == 2 && str->str1[i + 1] == 2)
		moves(str, i);
	if ((str->str1[i] == 3 && str->str1[i + 1] == 4) || (str->str1[i] == 4
			&& str->str1[i + 1] == 3))
		moves(str, i);
}

void	movez(t_str *str, int i, int h)
{
	str->num_move -= 1;
	str->str1[i] = -1;
	str->str1[i + 1] = h;
}

void	prosto(t_str *str)
{
	int	i;

	i = -1;
	while (++i < str->num_move * 2)
	{
		if (!str->str1[i])
			break ;
		lot_ifs(str, i);
		if ((str->str1[i] == 8 && str->str1[i + 1] == 7) || (str->str1[i] == 7
				&& str->str1[i + 1] == 8))
			movez(str, i, 9);
		if ((str->str1[i] == 5 && str->str1[i + 1] == 6) || (str->str1[i] == 6
				&& str->str1[i + 1] == 5))
			movez(str, i, 10);
		if ((str->str1[i] == 1 && str->str1[i + 1] == 2) || (str->str1[i] == 2
				&& str->str1[i + 1] == 1))
			movez(str, i, 11);
	}
}
