/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alog2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:28:49 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/04 21:56:06 by rywisozk         ###   ########.fr       */
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
int	ft_check_three(t_stack *sa)
{
	while (sa->prev != NULL)
	{
		sa = sa->prev;
	}
	while (sa->next != NULL)
	{
		if (sa->value > sa->next->value)
		{
			return (0);
		}
		sa = sa->next;
	}
	return (1);
}
void	alg(t_stack *a)
{
	int j;
	t_stack *tmp;
	int min;
	int	max;
	j = 0;

	while(a->prev != NULL){
		a = a->prev;
	}
	tmp = a;
	while (a->next)
	{
		j++;
		a = a->next;
	}
	// printf("%d", j);
	if (j == 2)
	{
		if ((tmp->value > a->value  && tmp->value > tmp->next->value ) && tmp->next->value > a->value)
		{
			write(1, "sa\n", 4);
			write(1, "rra\n", 4);
			ft_sa(a);
			ft_rra(a);
		}
		else if (tmp->value < a->value &&  tmp->value > tmp->next->value)
		{
			ft_sa(a);
			write(1, "sa\n", 4);
		}
		else
		{
			while (ft_check_three(a) == 0)
			{
				write(1, "rra\n", 4);
				ft_rra(a);
				if (tmp->value > tmp->next->value)
				{
					ft_sa(a);
					write(1, "sa\n", 4);
				}
			}
		}
		// ft_check(a);
		exit (0);
	}
	while(a->prev != NULL){
		a = a->prev;
	}
	if (j == 4)
	{
		while (ft_check_three(a) == 0)
		{
			tmp = a;
			while (tmp->next != NULL)
				tmp = tmp->next;
			if (tmp->value > tmp->next->value)
			{
				ft_sa(a);
				write(1, "sa\n", 4);
			}
			else if (tmp->value < tmp->next->value)
			{
				write(1, "rra\n", 4);
				ft_rra(a);
			}
			else
			{
				write(1, "ra\n", 4);
				ft_turn_ra(a);
			}


		}
	}

}
