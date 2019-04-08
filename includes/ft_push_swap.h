/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:56:40 by jritchie          #+#    #+#             */
/*   Updated: 2019/04/08 09:58:34 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>
# define MIN(x, y) (x < y ? x : y)
# define MAX(x, y) (x > y ? x : y)

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_buf
{
	int				fra;
	int				frb;
	int				srb;
	int				sra;
	int				k;
	int				i;
	int				j;
	int				mina;
	int				maxa;
	int				maxb;
	int				minb;
	int				rnd;
}					t_buf;
int					main(int ac, char **av);
void				duplicates(t_stack *a);
void				ft_error();
t_stack				*ft_listnew(void);
t_stack				*ft_listadd(t_stack *trt);
void				ft_check(t_stack *sa);
void				ft_rrr(t_stack *sb, t_stack *sa);
void				ft_rrb(t_stack	*sb);
void				ft_rra(t_stack	*sa);
void				ft_rr(t_stack *sb, t_stack *sa);
void				ft_turn_rb(t_stack	*sb);
void				ft_turn_ra(t_stack	*sa);
void				ft_pb(t_stack	**a, t_stack	**b);
void				ft_pa(t_stack	**a, t_stack	**b);
void				ft_ss(t_stack	*sa, t_stack	*sb);
void				ft_sb(t_stack	*sb);
void				ft_sa(t_stack	*a);
void				srot(t_stack *as);
t_stack				*del(int i, t_stack **head);
void				sort_a(t_stack *sa, t_stack *sb, t_buf *buf);
t_stack				*ft_listadd_start(t_stack *trt);
t_stack				*del_b(int i, t_stack *head);
void				ft_search(char *arr, t_stack *a);
void				ft_oper_check(char *arr, t_stack *a, t_stack **b);
void				ft_addb_value(int i, int j, t_stack *a, t_stack **b);
void				duplicate(t_stack *a);
void				ft_check(t_stack *sa);
void				del2(t_stack **head, t_stack **pn);
void				ft_read(t_stack *sa);
void				str_arg(t_stack *a, char *av);
void				str_check(char *av);
int					ft_lst_check(t_stack *a);
void				opeartion_check(char *arr, t_stack *a, t_stack **b);
void				ft_order(t_stack *sa);
void				find(t_stack *a, t_stack *b, t_buf *buf);
void				list_del(t_stack **alst);
void				second_rbra(t_stack *a, t_stack *b, t_buf *buf);
void				first_rbra(t_stack *a, t_stack *b, t_buf *buf);
void				min_second_rbra(t_buf *buf, int *fir);
void				min_first_rbra(t_buf *buf, int *fir);
void				cpy_head(t_stack *head, t_buf *buf, int bi);
void				cpy_head_rra(t_stack *head, t_buf *buf, int bi);
t_buf				*min_max(t_buf *buf, t_stack *a);
int					alg(t_stack *a);
int					ft_check_three(t_stack *sa);
void				alg_three(t_stack *a, t_stack *buf);
void				last_oper(t_stack *a, t_stack *b);
void				free_array(char **arr);
void				lst_opr(t_stack *a, t_stack *b);
void				cycle_three(t_stack *tmp, t_stack *a);
#endif
