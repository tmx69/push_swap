/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:41:47 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/08 10:27:34 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

// void	srot(t_stack *a)
// {
// 	t_stack		*b;
// 	// t_stack		*head;
// 	t_buf		*buf;

// 	buf = (t_buf *)malloc(sizeof(t_buf));
// 	b = NULL;
// 	buf->i = 0;
// 	// head = a;
// 	buf = min_max(buf, head);
// 	while (buf->i-- > 0)
// 	{
// 		if (head->value != buf->mina && head->value != buf->maxa)
// 		{
// 			ft_pb(&head, &b);
// 			write(1, "pb\n", 3);
// 			head = del(head->value, &head);
// 		}
// 		else
// 		{
// 			write(1, "ra\n", 3);
// 			ft_turn_ra(head);
// 		}
// 	}
// 	a = head;
// 	sort_a(a, b, buf);
// 	free(buf);
// }
void	srot(t_stack *a)
{
	t_stack		*b;
	// t_stack		*head;
	t_buf		*buf;

	buf = (t_buf *)malloc(sizeof(t_buf));
	b = NULL;
	buf->i = 0;
	// head = a;
	buf = min_max(buf, a);
	while (buf->i-- > 0)
	{
		if (a->value != buf->mina && a->value != buf->maxa)
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
	// a = head;
	sort_a(a, b, buf);
	free(buf);
}
t_stack	*cpy_list(t_stack *a)
{
	t_stack *new;

	new = ft_listnew();
	while (a != NULL)
	{
		new->value = a->value;
		if (a->next != NULL)
			new = ft_listadd(new);
		a = a->next;
	}
	while (new->prev != NULL)
	{
		new = new->prev;
	}
	free(a);
	a = NULL;
	return (new);
}

void	find_good_rra(t_stack *a, t_stack *b, t_buf *buf)
{
	t_stack *head;
	int		*fir;
	t_stack	*bi;

	buf->i = 0;
	buf->k = 0;
	bi = b;
	while (bi != NULL)
	{
		bi = bi->next;
		buf->k++;
	}
	fir = (int*)malloc(sizeof(int) * buf->k);
	while (b != NULL)
	{
		head = cpy_list(a);
		buf->j = 0;
		cpy_head_rra(head, buf, b->value);
		list_del(&head);
		fir[buf->i++] = buf->j;
		b = b->next;
	}
	min_second_rbra(buf, fir);
	free(fir);
	list_del(&head);
}

void	find(t_stack *a, t_stack *b, t_buf *buf)
{
	t_stack *head;
	int		*fir;
	t_stack *bi;

	bi = b;
	buf->k = 0;
	while (b != NULL)
	{
		b = b->next;
		buf->k++;
	}
	fir = (int*)malloc(sizeof(int) * buf->k);
	buf->i = 0;
	while (bi != NULL)
	{
		head = cpy_list(a);
		buf->j = 0;
		cpy_head(head, buf, bi->value);
		list_del(&head);
		fir[buf->i++] = buf->j;
		bi = bi->next;
	}
	min_first_rbra(buf, fir);
	free(fir);
}

void	sort_a(t_stack *a, t_stack *b, t_buf *buf)
{
	t_stack *head;

	head = a;
	while (b)
	{
		find(a, b, buf);
		find_good_rra(a, b, buf);
		if ((buf->fra + buf->frb) < (buf->sra + buf->srb))
			first_rbra(a, b, buf);
		else
			second_rbra(a, b, buf);
		a = ft_listadd_start(a);
		ft_pa(&a, &b);
		write(1, "pa\n", 3);
		b = del(b->value, &b);
	}
	while (a->value != buf->mina)
	{
		write(1, "rra\n", 4);
		ft_rra(a);
	}
}
