/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:41:47 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/02 14:57:56 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	min_max(t_buf *buf, t_stack *a)
{
	while (a != NULL)
	{
		if (a->value < buf->minb)
            buf->minb = a->value;
        else if (a->value > buf->maxb)
            buf->maxb = a->value;
		a = a->next;
	}
}

void	srot(t_stack *a)
{
	t_stack		*b;
	t_stack		*head;
	int			i;
	t_buf		*buf;

	i = 0;
	buf = (t_buf *)malloc(sizeof(t_buf));
	b = NULL;
	head = a;
	buf->mina = a->value;
	buf->maxa = a->value;
	while (a != NULL)
	{
		if (a->value < buf->mina)
            buf->mina = a->value;
        else if (a->value > buf->maxa)
            buf->maxa = a->value;
		i++;
		a = a->next;
	}
	while (i > 0)
	{
		if (head->value != buf->mina && head->value != buf->maxa)
		{
			ft_pb(&head, &b);
			write(1, "pb\n", 3);
			head = del(head->value, &head);
		}
		else
		{
			write(1, "ra\n", 3);
			ft_turn_ra(head);
		}
		i--;
	}
	a = head;
	sort_a(a, b, buf);
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
	while(new->prev != NULL){
		new = new->prev;
	}

	return (new);
}
// void	find_good_rra(t_stack *a, t_stack *b)
// {
// 	int		i;
// 	t_stack *head;
// 	t_stack	*last;
// 	t_stack	*bi;
// 	int		j;
// 	int		*fir;
// 	int		c;

// 	j = 0;
// 	i = 0;
// 	c = 0;

// 	fir = (int*)malloc(sizeof(int) * 100);
// 	bi = b;
// 	while (b != NULL)
// 	{
// 		printf("|B:%d|",b->value);
// 		head = cpy_list(a);
// 		j = 0;
// 		while (head)
// 		{
// 			last = head;
// 			while (last->next != NULL)
// 				last = last->next;
// 			printf("last %d\n", last->value);
// 			if (b->value < head->value && b->value > last->value)
// 				break ;
// 			else
// 			{
// 				j++;
// 			}
// 			printf("\na: %d b: %d j: %d\n", head->value, b->value, j);
// 			ft_turn_ra(head);
// 		}
// 		list_del(&head);
// 		printf("|J:%d|\n",j);
// 		fir[i] = j;
// 		i++;
// 		b = b->next;
// 	}

// 	i = 0;
// 	printf("|FIRST|");
// 	while (fir[i])
// 	{
// 		printf("|A:%d|",fir[i]);
// 		printf("|B:%d|",i);
// 		i++;
// 	}
// 	printf("\n");
// 	i = 0;
// 	j = 0;
// 	c = fir[0];
// 	while (fir[i])
// 	{
// 		if (fir[i] + i < c)
// 		{
// 			c = fir[i]; // наименьшее прокрутка А
// 			j = i;		// наименьшее прокрутка В
// 		}
// 		i++;
// 	}

// 	printf("|C:%d|", c);
// 	printf("|J:%d|\n", j);
// 	// while (b->prev != NULL)
//     //     b = b->prev;
// 	while (j > 0)
// 	{
// 		printf("rb\n");
// 		ft_turn_rb(bi);
// 		j--;
// 	}
// 	// head = a;
// 	// if (c != 0)
// 	// {
// 	while (c > 0)
// 	{
// 		printf("FT_RA\n");
// 		ft_turn_ra(a);
// 		c--;
// 	}
// 	// // }
// // if (b->value < a->value && b->value > last->value)
// //         {
// // 			printf("FT_PA\n");
// // 			ft_pa(&a, &b);
// // 			b = del(b->value, &b);
// //         }
// }
void	find_good_rra(t_stack *a, t_stack *b, t_buf *buf)
{
	int		i;
	t_stack *head;
	t_stack	*last;
	int		j;
	int		*fir;
	int		k;
	t_stack	*bi;

	i = 0;
	k = 0;
	bi = b;
	while(bi != NULL){
		bi = bi->next;
		k++;
	}
	fir = (int*)malloc(sizeof(int) * k);
	while (b != NULL)
	{
		head = cpy_list(a);
		j = 0;
		while (head)
		{
			last = head;
			while (last->next != NULL)
				last = last->next;
			if (b->value < head->value && b->value > last->value)
				break ;
			else
				j++;
			ft_rra(head);
		}
		list_del(&head);
		fir[i] = j;
		i++;
		b = b->next;
	}

	i = 0;
	buf->sra = fir[0];
	while (i < k)
	{
		if (fir[i] + i < buf->fra)
		{
			buf->sra = fir[i]; // наименьшее прокрутка А
			buf->srb = i;		// наименьшее прокрутка В
		}
		i++;
	}
	free(fir);
}

void	find(t_stack *a, t_stack *b, t_buf *buf)
{
	int		i;
	t_stack *head;
	t_stack	*last;
	int		j;
	int		*fir;
	t_stack *bi;
	int		k;

	i = 0;
	bi = b;
	k = 0;
	while(b != NULL){
		b = b->next;
		k++;
	}
	fir = (int*)malloc(sizeof(int) * k);
	i = 0;
	while (bi != NULL)
	{
		head = cpy_list(a);
		j = 0;
		while (head)
		{
			last = head;
			while (last->next != NULL)
				last = last->next;
			if (bi->value < head->value && bi->value > last->value)
				break ;
			else
				j++;
			ft_turn_ra(head);
		}
		list_del(&head);
		fir[i] = j;
		i++;
		bi = bi->next;
	}
	i = 0;

	buf->fra = fir[i];
	buf->frb = 0;
	while (i < k)
	{
		if (fir[i] + i < buf->fra && fir[i] > -1)
		{
			buf->fra = fir[i]; // наименьшее прокрутка А
			buf->frb = i;		// наименьшее прокрутка В
		}
		i++;
	}
	free(fir);
}

void	sort_a(t_stack *a, t_stack *b, t_buf *buf)
{
	t_stack	*last;
	t_stack *head;
	last = a;

	head = a;
	last = a;
	while(last->next != NULL){
		last = last->next;
	}
	while(a->prev != NULL){
		a = a->prev;
	}
	head = a;

	while (b)
	{
		find(a,b, buf);
		find_good_rra(a,b, buf);
		if ((buf->fra + buf->frb) < (buf->sra + buf->srb))
		{

			while (buf->frb > 0)
			{
				printf("rb\n");
				ft_turn_rb(b);
				buf->frb--;
			}
			while (buf->fra > 0)
			{
				printf("FT_RA\n");
				ft_turn_ra(a);
				buf->fra--;
			}
		}
		else
		{
			while (buf->srb > 0)
			{
				printf("rb\n");
				ft_turn_rb(b);
				buf->srb--;
			}
			while (buf->sra > 0)
			{
				printf("FT_RRA\n");
				ft_rra(a);
				buf->sra--;
			}
		}
		ft_pa(&a,&b);
		printf("PA\n");
		b = del(b->value, &b);
	}
head = a;
    while(head->value != buf->mina)
    {
		printf("FT_rra\n");
        ft_rra(a);
    }
	// while (a->prev != NULL)
	// 					a = a->prev;
	// 					printf("STACK A:");
	// 				while(a != NULL)
	// 				{
	// 					printf("|%d|", a->value );
	// 					a = a->next;
	// 				}
	// 				printf("\n");
	// 				if (b)
	// 				{
	// 				printf("STACK B:");
	// 				while (b->prev != NULL)
	// 					b = b->prev;
	// 				while(b != NULL)
	// 				{
	// 					printf("|%d|", b->value );
	// 					b = b->next;
	// 				}
	// 				}
	// 				printf("\n");
	// head = a;
	ft_check(a);
}