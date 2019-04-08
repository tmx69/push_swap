/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:39:56 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/08 10:03:45 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	lst_opr(t_stack *a, t_stack *b)
{
	write(1, "sb\n", 3);
	ft_sb(b);
	a = ft_listadd_start(a);
	write(1, "pa\n", 3);
	ft_pa(&a, &b);
	b = del(b->value, &b);
	write(1, "ra\n", 3);
	ft_turn_ra(a);
	a = ft_listadd_start(a);
	write(1, "pa\n", 3);
	ft_pa(&a, &b);
	b = del(b->value, &b);
}

void	last_oper(t_stack *a, t_stack *b)
{
	if (b->value > b->next->value)
	{
		a = ft_listadd_start(a);
		ft_pa(&a, &b);
		write(1, "pa\n", 3);
		b = del(b->value, &b);
		write(1, "ra\n", 3);
		ft_turn_ra(a);
		a = ft_listadd_start(a);
		write(1, "pa\n", 3);
		ft_pa(&a, &b);
		b = del(b->value, &b);
	}
	else
	{
		lst_opr(a, b);
	}
}

void	second_oper(t_stack *a, t_stack *b, t_buf *buf, t_stack *tmp)
{
	while (buf->i-- >= 0)
	{
		if (a->value == buf->mina || a->value == buf->maxa)
		{
			ft_pb(&a, &b);
			write(1, "pb\n", 3);
			a = del(a->value, &a);
		}
		else
		{
			write(1, "ra\n", 3);
			ft_turn_ra(a);
		}
	}
	while (a->prev != NULL)
		a = a->prev;
	tmp = a;
	while (a->next != NULL)
		a = a->next;
	alg_three(a, tmp);
	last_oper(a, b);
}

void	alg_five(t_stack *a, t_stack *tmp)
{
	t_stack	*b;
	t_buf	*buf;

	buf = (t_buf *)malloc(sizeof(t_buf));
	buf->i = 0;
	while (a->prev != NULL)
		a = a->prev;
	buf = min_max(buf, a);
	b = ft_listnew();
	while (a->prev)
		a = a->prev;
	second_oper(a, b, buf, tmp);
	list_del(&b);
	free(buf);
}

int		alg(t_stack *a)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	while (a->prev != NULL)
		a = a->prev;
	tmp = a;
	while (a->next)
	{
		j++;
		a = a->next;
	}
	if (j == 2)
	{
		while (a->next != NULL)
			a = a->next;
		alg_three(a, tmp);
	}
	if (j == 4)
		alg_five(a, tmp);
	while (a->prev)
		a = a->prev;
	while (tmp->prev)
		tmp = tmp->prev;
	return (j == 2 || j == 4 ? 1 : 0);
}
