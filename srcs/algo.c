/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:08:52 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/08 09:19:57 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	second_rbra(t_stack *a, t_stack *b, t_buf *buf)
{
	while (buf->srb-- > 0)
	{
		write(1, "rb\n", 3);
		ft_turn_rb(b);
	}
	while (buf->sra-- > 0)
	{
		write(1, "rra\n", 4);
		ft_rra(a);
	}
}

void	first_rbra(t_stack *a, t_stack *b, t_buf *buf)
{
	while (buf->frb-- > 0)
	{
		write(1, "rb\n", 3);
		ft_turn_rb(b);
	}
	while (buf->fra-- > 0)
	{
		write(1, "ra\n", 3);
		ft_turn_ra(a);
	}
}

void	min_second_rbra(t_buf *buf, int *fir)
{
	buf->i = 0;
	buf->sra = fir[0];
	buf->srb = 0;
	while (buf->i < buf->k)
	{
		if (fir[buf->i] + buf->i < buf->sra && fir[buf->i] > -1)
		{
			buf->sra = fir[buf->i];
			buf->srb = buf->i;
		}
		buf->i++;
	}
}

void	min_first_rbra(t_buf *buf, int *fir)
{
	buf->i = 0;
	buf->fra = fir[buf->i];
	buf->frb = 0;
	while (buf->i < buf->k)
	{
		if (fir[buf->i] + buf->i < buf->fra && fir[buf->i] > -1)
		{
			buf->fra = fir[buf->i];
			buf->frb = buf->i;
		}
		buf->i++;
	}
}

void	cpy_head(t_stack *head, t_buf *buf, int bi)
{
	t_stack	*last;

	while (head)
	{
		last = head;
		while (last->next != NULL)
			last = last->next;
		if (bi < head->value && bi > last->value)
			break ;
		buf->j++;
		ft_turn_ra(head);
	}
}
