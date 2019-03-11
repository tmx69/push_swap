/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:41:47 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/11 16:46:26 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

t_stackb	 *del_b(int i, t_stackb *head)
{
    t_stackb *pn;
	t_stackb *tail;
	t_stackb *temp;
    pn = head;
    while (pn != NULL)
    {
        if (pn->b == i) // если найдена заданная страна
        {
            if (pn == head) // если найденная запись - первая
            {
                head = pn->next;
                head->prev = NULL;
				free(pn);
				pn = head->next;
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
                    pn->next->prev=pn->prev;
                    pn->prev->next=pn->next;
                    temp=pn;
                    pn=pn->next;
                    free(temp);
                }
    	}
    else // если заданная страна не найдена – продвигаемся по списку
		pn=pn->next;
	}
	return (head);
}

t_stacka	 *del(int i, t_stacka *head)
{
    t_stacka *pn;
	t_stacka *tail;
	t_stacka *temp;
    pn = head;
    while (pn != NULL)
    {
        if (pn->a == i) // если найдена заданная страна
        {
            if (pn == head) // если найденная запись - первая
            {
                head = pn->next;
                head->prev = NULL;
				free(pn);
				pn = head->next;
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
                    pn->next->prev=pn->prev;
                    pn->prev->next=pn->next;
                    temp=pn;
                    pn=pn->next;
                    free(temp);
                }
    	}
    else // если заданная страна не найдена – продвигаемся по списку
		pn=pn->next;
	}
	return (head);
}

void  srot(t_stacka *as)
{
    t_stackb	*sb;
	t_stacka	*sa;
	t_stacka	*temp;
    int			i;
    int			j;

    i = as->a;
    j = as->a;
    sb = ft_listnewb();
	sa = as;
    while (sa != NULL) //max and min
    {
        if (sa->a < i)
            i = sa->a;
        else if (sa->a > j)
            j = sa->a;
        sa = sa->next;
    }
	sa = as;
    while (sa != NULL)
    {
        if (sa->a != i && sa->a != j)
    	{
            sb->b =	sa->a;
            if (sa->next != NULL)
                sb = ft_listadd_b(sb);
        }
        sa = sa->next;
    }
	sa = as;
	while (sa != NULL)
	{
		if (sa->a != i && sa->a != j)
			as = del(sa->a, as);
		sa = sa->next;
	}
	sort_a(as, sb, i);
    // while (sb != NULL)
	// {
	// 	printf("B:%d", sb->b);
	// 	printf("\n");
	// 	sb = sb->prev;
	// }
	// sa = as;
	// while (sa != NULL)
	// {
	// 	printf("A:%d", sa->a);
	// 	printf("\n");
	// 	sa = sa->next;
	// }
	// while (as != NULL)
	// {
	// 	printf("As:%d", as->a);
	// 	printf("\n");
	// 	as = as->next;
	// }
}

void sort_a(t_stacka *sa, t_stackb *sb, int min)
{
	t_stackb *head;

	head = sb;
	while (sb != NULL)
	{

		if (sb->b < sa->a)
		{
			ft_pa(sa, sb);
		}
		else if ()
	}
}