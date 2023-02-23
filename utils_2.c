#include "push_swap.h"

void	repeat(t_str *str, int w, int i)
{
	int	j;

	j = 0;
	while (++j <= i)
	{
		if (w == 1)
			push_a(str);
		if (w == 2)
			rotate_b(str);
		if (w == 3)
			r_rotate_a(str);
	}
}
