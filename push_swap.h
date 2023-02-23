#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_str
{
	int		is_sovp;
	int		stack[4][100000];
	int		stack_end;
	int		const_end;
	int		end[2];
	int		max[2];
	int		min[2];
	int		niz;
	int		siz;
	int		rrot;
	int		h;
	int		flag;
	int		num_move;
	int		str1[1000000];
	int		tp[2][100000];
}	t_str;

void	check_maxin_do(t_str *str, int i);
void	check_maxin(t_str *str);

void	*rotate_a(t_str *str);
void	*rotate_b(t_str *str);
void	*r_rotate_b(t_str *str);
void	*r_rotate_a(t_str *str);
void	*swap_a(t_str *str);
void	*swap_b(t_str *str);
void	*push_b(t_str *str);
void	*push_a(t_str *str);

void	duo(t_str *str, int u);
void	trio(t_str *str, int u);
int		sovo(t_str *str);
void	sovop(t_str *str);
void	t(t_str *str);
void	men_const(t_str *str);
void	tmp_const(t_str *str, int i);
void	trio_r(t_str *str);
void	less_6(t_str *str);
void	ft_strnum(int e);
int		w_write(t_str *str, int i);
void	ft_write(t_str *str);

void	push_sw(t_str *str);
int		rot_push(t_str *str, int *i);
void	push_rot(t_str *str);
void	push_reson_rot(t_str *str);
int		push_swap(t_str *str);

int		check_zero(t_str *str);
void	parse_add(t_str *str);
int		ge_prs(t_str *str, int i);
int		parse(t_str *str, int ac, char **av);
int		mid_chek(t_str *str, int mid);

void	lot_ifs(t_str *str, int i);
void	movez(t_str *str, int i, int h);
void	prosto(t_str *str);
void	moves(t_str *str, int i);

int		ft_strlen(char *s);
int		atio_dop(unsigned int i, const char *str, long *sign);
int		ft_atoi(const char *str);
int		sovp(t_str *str);
int		str_error(char *s);
void	repeat(t_str *str, int w, int i);

void	flag_stels(t_str *str);
void	duo_dou(t_str *str);
void	pre_ps(t_str *str);
int		spp(t_str *str);
int		main(int ac, char **av);

#endif
