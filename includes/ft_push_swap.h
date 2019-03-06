/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:56:40 by jritchie          #+#    #+#             */
/*   Updated: 2019/03/06 15:24:09 by rywisozk         ###   ########.fr       */
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

typedef struct	a_stack
{
	int					a;
	struct	a_stack 	*next;
	struct	a_stack 	*prev;
}				t_stacka;

typedef struct	b_stack
{
	int				b;
	struct b_stack	*next;
	struct b_stack	*prev;
}				t_stackb;

int		main(int ac, char **av);
void 	duplicates(t_stacka *a);
void 	ft_error();
t_stacka	*ft_listnew(void);
t_stacka *ft_listadd(t_stacka *trt);
void    ft_check(t_stacka  *sa);
#endif
