/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alog2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:28:49 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/02 17:29:18 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

t_buf	*min_max(t_buf *buf, t_stack *a)
{
	buf->mina = a->value;
	buf->maxa = a->value;
	while (a != NULL)
	{
		if (a->value < buf->mina)
			buf->mina = a->value;
		else if (a->value > buf->maxa)
			buf->maxa = a->value;
		buf->i++;
		a = a->next;
	}
	return (buf);
}

void	cpy_head_rra(t_stack *head, t_buf *buf, int bi)
{
	t_stack *last;

	while (head)
	{
		last = head;
		while (last->next != NULL)
			last = last->next;
		if (bi < head->value && bi > last->value)
			break ;
		buf->j++;
		ft_rra(head);
	}
}