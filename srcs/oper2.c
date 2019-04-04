/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:19:31 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/03 21:31:13 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	ft_pb(t_stack **a, t_stack **b)
{
	if (!(*b))
	{
		(*b) = ft_listnew();
	}
	else
	{
		(*b) = ft_listadd_start((*b));
	}
	if (a)
	{
		while ((*a)->prev != NULL)
		{
			(*a) = (*a)->prev;
		}
		(*b)->value = (*a)->value;
	}
}

void	ft_turn_ra(t_stack *sa)
{
	int i;

	while (sa->prev != NULL)
		sa = sa->prev;
	i = sa->value;
	while (sa->next != NULL)
	{
		sa->value = sa->next->value;
		sa->next->value = i;
		sa = sa->next;
	}
}

void	ft_turn_rb(t_stack *sb)
{
	int	j;

	if (sb)
	{
		j = sb->value;
		while (sb->next != NULL)
		{
			sb->value = sb->next->value;
			sb->next->value = j;
			sb = sb->next;
		}
	}
}

void	ft_rr(t_stack *sb, t_stack *sa)
{
	ft_turn_rb(sb);
	ft_turn_ra(sa);
}
