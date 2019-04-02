/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:39:30 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/02 14:40:04 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	ft_rra(t_stack *sa)
{
	int	j;

	while (sa->next != NULL)
	{
		sa = sa->next;
	}
	j = sa->value;
	while (sa->prev != NULL)
	{
		sa->value = sa->prev->value;
		sa->prev->value = j;
		sa = sa->prev;
	}
}

void	ft_rrb(t_stack *sb)
{
	int i;

	if (sb)
	{
		while (sb->next != NULL)
		{
			sb = sb->next;
		}
		i = sb->value;
		while (sb->prev != NULL)
		{
			sb->value = sb->prev->value;
			sb->prev->value = i;
			sb = sb->prev;
		}
	}
}

void	ft_rrr(t_stack *sb, t_stack *sa)
{
	write(1, "rrr\n", 4);
	ft_rrb(sb);
	ft_rra(sa);
}
