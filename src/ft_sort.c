/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:41:47 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/22 19:46:58 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

t_stack	 *del(int i, t_stack **head)
{
    t_stack *pn;
	t_stack *tail;
	t_stack *temp;
    // while (head->prev != NULL)
    // {
    //     head = head->prev;
    // }
    pn = *head;
    while (pn != NULL)
    {
        if (pn->prev == NULL && pn->next== NULL) // если запись единственная
        {
            (*head) = NULL;
            free(pn);
            break ;
        }
        if (pn->value == i) // если найдена заданная страна
        {
            if (pn == *head) // если найденная запись - первая
            {
                (*head) = pn->next;
                (*head)->prev = NULL;
				free(pn);
				pn = (*head)->next;
            }
       		else if (pn->next == NULL) // если найденная запись - последняя
                {
                    tail = pn->prev;
                    tail->next = NULL;
                    free(pn);
                    pn = tail;
                }
            else  // удаление из средины списка
            {
                    pn->next->prev = pn->prev;
                    pn->prev->next = pn->next;
                    temp = pn;
                    pn=pn->next;
                    free(temp);
                }
        }
        else // если заданная страна не найдена – продвигаемся по списку
		    pn=pn->next;
	}
    // if (head == NULL)
    //     return (NULL);
	return (*head);
}


void  srot(t_stack *as)
{
    t_stack		*b;
	t_stack		*a;
	t_stack		*temp;
    int			i;
    int			j;

    i = as->value;
    j = as->value;
    b = ft_listnew();

    while (a != NULL)
    {
        if (a->value < i)
            i = a->value;
        else if (a->value > j)
            j = a->value;
        a = a->next;
    }
	a = as;
    while (a != NULL)
    {
        if (a->value != i && a->value != j)
    	{
            if (b->value != 0)
			{
                b = ft_listadd(b);
			}
            b->value = a->value;
        }
        a = a->next;
    }
	a = as;
	while (a != NULL)
	{
		if (a->value != i && a->value != j)
			as = del(a->value, &as);
		a = a->next;
	}
	sort_a(as, b, i, j);

}

void	sort_a(t_stack *a, t_stack *b, int min, int max)
{
	t_stack *last;
    t_stack *start;
    int i = 0;
    int flag;

flag = 0;
	while (b->prev != NULL)
    {
        b = b->prev;
    }
    while (a->prev != NULL)
    {
        a = a->prev;
    }
    start = a;
    last = a;
    while (last->next != NULL)
    {
        last = last->next;
    }

    while (b)
    {
    	if (b->value < a->value && b->value > last->value)
        {
			printf("FT_PA\n");
			ft_pa(&a, &b);
            i++;
			b = del(b->value, &b);
			// a = a->prev;
        }
        else if (b->value < a->value && b->value < last->value)
        {
            i++;
			printf("FT_rrr\n");
            ft_rrr(b, a);
        }
        else
        {
            i++;
			printf("FT_RA\n");
			ft_turn_ra(a);
        }
        if (b == NULL)
            break ;
    }
    while (a->prev != NULL)
    {
        a = a->prev;
    }

if (b)
{
    while (b->prev != NULL)
    {
        b = b->prev;
    }
}
    start = a;
    while(start->value != min)
    {
        i++;
		printf("FT_rra\n");
        ft_rra(a);
    }

	while (a != NULL)
	{
		printf("A:%d", a->value);
		printf("\n");
		a = a->next;
	}
printf("I:%d\n",i);
	while (b != NULL)
	{
		printf("B:%d", b->value);
		printf("\n");
		b = b->next;
	}
}