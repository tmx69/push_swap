/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:48:17 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/02 14:25:17 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	ft_sa(t_stack *a)
{
	int i;

	while (a->prev != NULL)
	{
		a = a->prev;
	}
	i = a->value;
	if (a->next != NULL)
	{
		a->value = a->next->value;
		a->next->value = i;
	}
}

void	ft_sb(t_stack *sb)
{
	int	i;

	if (sb)
	{
		i = sb->value;
		sb->value = sb->next->value;
		sb->next->value = i;
	}
}

void	ft_ss(t_stack *sa, t_stack *sb)
{
	ft_sa(sa);
	ft_sb(sb);
}

t_stack	*ft_add_start(t_stack *trt)
{
	t_stack	*buf;
	t_stack	*new;

	new = ft_listnew();
	buf = trt;
	while (buf->prev != NULL)
		buf = buf->prev;
	buf->prev = new;
	new->next = buf;
	new->prev = NULL;
	return (new);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	if (b)
	{
		while ((*b)->prev != NULL)
		{
			(*b) = (*b)->prev;
		}
		(*a) = ft_listadd_start(*a);
		(*a)->value = (*b)->value;
	}
}
