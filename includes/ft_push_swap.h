/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:56:40 by jritchie          #+#    #+#             */
/*   Updated: 2019/03/29 13:57:40 by rywisozk         ###   ########.fr       */
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

typedef struct		stack
{
	int				value;
	struct	stack 	*next;
	struct	stack 	*prev;
}					t_stack;

typedef struct		buf
{
	int				mina;
	int				maxa;
	int				maxb;
	int				minb;
	int				rnd;
}					t_buf;
int				main(int ac, char **av);
void			duplicates(t_stack *a);
void			ft_error();
t_stack			*ft_listnew(void);
t_stack			*ft_listadd(t_stack *trt);
void			ft_check(t_stack  *sa);
void			ft_rrr(t_stack	*sb, t_stack   *sa);
void			ft_rrb(t_stack	*sb);
void			ft_rra(t_stack	*sa);
void			ft_rr(t_stack *sb, t_stack *sa);
void			ft_turn_rb(t_stack	*sb);
void			ft_turn_ra(t_stack	*sa);
void			ft_pb(t_stack	**a, t_stack	**b);
void			ft_pa(t_stack	**a, t_stack	**b);
void			ft_ss(t_stack	*sa, t_stack	*sb);
void			ft_sb(t_stack	*sb);
void			ft_sa(t_stack	*a);
void			srot(t_stack *as);
t_stack			*del(int i, t_stack **head);
void			sort_a(t_stack *sa, t_stack *sb, t_buf *buf);
t_stack			*ft_listadd_start(t_stack *trt);
t_stack			*del_b(int i, t_stack *head);
void			ft_search(char *arr, t_stack *a);
void			ft_oper_check(char *arr, t_stack *a, t_stack **b);
void			ft_addb_value(int i, int j, t_stack *a, t_stack **b);
void			duplicate(t_stack *a);
void			ft_check(t_stack *sa);
void			del2(t_stack **head, t_stack **pn);
void			ft_read(t_stack *sa);
void			str_arg(t_stack *a, char *av);
void			str_check(char *av);
int				ft_lst_check(t_stack *a);
void			opeartion_check(char *arr, t_stack *a, t_stack **b);
void			ft_order(t_stack *sa);
void			find(t_stack *a, t_stack *b);
// void    ft_check2(t_stack  *sa);
#endif
