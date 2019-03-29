/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:41:47 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/29 20:26:42 by rywisozk         ###   ########.fr       */
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
		else
		{
			buf->rnd = a->value;
		}
		i++;
		a = a->next;
	}
	// printf("|MIN:%d|\n", buf->mina);
	// printf("|MAX:%d|\n",buf->maxa);
	// printf("|RND:%d|\n", buf->rnd);
	// printf("|I:%d|\n", i);
	while (i > 0)
	{
		if (head->value != buf->mina && head->value != buf->maxa && head->value != buf->rnd)
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

void	find(t_stack *a, t_stack *b)
{
	int		i;
	t_stack *head;
	t_stack	*last;
	int		j;
	int		*fir;
	int		*end;
	int		c;
	j = 0;
	i = 0;
	c = 0;

	fir = (int*)malloc(sizeof(int) * 100);
	end = (int*)malloc(sizeof(int) * 100);
	last = a;
	while  (b->prev != NULL)
		b= b->prev;
	while  (last->next != NULL)
		last = last->next;
	while (b != NULL)
	{
		head = a;
		j = 0;
		while (head != NULL){
			j++;
			if (b->value < head->value && b->value > last->value)
			{
				break;
			}
			head = head->next;
		}
		fir[i] = j;
		i++;
		b = b->next;
	}
	i = 0;
	while (fir[i])
	{
		printf("|A:%d|",fir[i]);
		printf("|B:%d|",i);
		i++;
	}
	i = 0;
	j = 0;
	c = fir[0];
	while (fir[i])
	{
		if (fir[i] + i < c)
		{
			c = fir[i]; // наименьшее прокрутка А
			j = i;		// наименьшее прокрутка В
		}
		i++;
	}
	// i = 0;
	// c = fir[0];
	// j = 0;
	// while (fir[i])
	// {
	// 	if (fir[i] + i < c)
	// 	{
	// 		fir[i] + i;
	// 		j = i;
	// 	}
	// 	i++;
	// }
	printf("|C:%d|", c);
	printf("|J:%d|\n", j);
		// while(b->prev != NULL){
		// b = b->prev;
		// }
	while (j > 1)
	{
		printf("rb");
		ft_turn_rb(b);
		j--;
	}
	head = a;
	// if (c != 0)
	// {
	while (c > 1)
	{
		printf("FT_RA\n");
		ft_turn_ra(a);
		c--;
	// }
	}
// if (b->value < a->value && b->value > last->value)
//         {
// 			printf("FT_PA\n");
// 			ft_pa(&a, &b);
// 			b = del(b->value, &b);
//         }
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
					// 	printf("STACK A:");
					// while (last != NULL)
					// {
					// 	printf("|%d|", last->value );
					// 	last = last->next;
					// }
					// printf("\n");
					// if (b)
					// {
					// printf("STACK B:");
					// while (b->prev != NULL)
					// 	b = b->prev;
					// while(b != NULL)
					// {
					// 	printf("|%d|", b->value );
					// 	b = b->next;
					// }
					// }
	// ft_pa(&a,&b);
	// b = del(b->value, &b);
    // while (b)
    // {
		find(a, b);
		ft_pa(&a,&b);
	b = del(b->value, &b);

	find(a, b);
	ft_pa(&a,&b);
	b = del(b->value, &b);
	find(a, b);
	// ft_pa(&a,&b);
	// b = del(b->value, &b);

	// 	if (b->value < a->value && b->value > last->value)
    //     {
	// 		printf("FT_PA\n");
	// 		ft_pa(&a, &b);
	// 		b = del(b->value, &b);
    //     }
    //     else if (b->value < a->value && b->value < last->value)
    //     {
	// 		printf("FT_rrr\n");
    //         ft_rrr(b, a);
    //     }
    //     else
    //     {
	// 		printf("FT_RA\n");
	// 		ft_turn_ra(a);
    //     }
    //     if (b == NULL)
    //         break ;
    // }
head = a;
    // while(head->value != buf->mina)
    // {
	// 	printf("FT_rra\n");
    //     ft_rra(a);
    // }
	while (a->prev != NULL)
						a = a->prev;
						printf("STACK A:");
					while(a != NULL)
					{
						printf("|%d|", a->value );
						a = a->next;
					}
					printf("\n");
					if (b)
					{
					printf("STACK B:");
					while (b->prev != NULL)
						b = b->prev;
					while(b != NULL)
					{
						printf("|%d|", b->value );
						b = b->next;
					}
					}
					printf("\n");
						printf("MIN:%d", buf->mina);
						printf("MAX:%d", buf->maxa);
	// ft_check(a);
}