/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:48:17 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/21 16:30:15 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	ft_sa(t_stack	*a)
{
    int i;

    i = a->value;
    a->value = a->next->value;
    a->next->value = i;
}

void	ft_sb(t_stack	*sb)
{
    int i;

    i = sb->value;
    sb->value = sb->next->value;
    sb->next->value = i;
}

void	ft_ss(t_stack	*sa, t_stack	*sb)
{
    ft_sa(sa);
    ft_sb(sb);

}

void	ft_pa(t_stack *a, t_stack **b)
{
    t_stack *pn;

    a = ft_listadd_start(a);
    a->value = (*b)->value;
    //  pn = (*b);
    // (*b) = del((*b)->value, (*b));
    //  if (pn->next == NULL)
    //  {
    //     // printf("PAPAPAP:%d\n",(*b)->value);
    //     // free((*b));
    //     // (*b) = pn->next;
    //     // (*b)->prev = NULL;

    //  }
    //  else
    //  {
    //     (*b) = pn->next;
    //     (*b)->prev = NULL;
    //     free(pn);
    //  }


    // pn = b->next;

}

void	ft_pb(t_stack	*sa, t_stack	*sb)
{

    sa->value = sb->value;
}

void    ft_turn_ra(t_stack	*sa)
{
    int i;

	i = sa->value;
    while (sa->next != NULL)
    {
    	sa->value = sa->next->value;
        sa->next->value = i;
        sa = sa->next;
	}
}

void    ft_turn_rb(t_stack	*sb)
{
	int	j;

	j = sb->value;
    while (sb->next != NULL)
    {
        sb->value = sb->next->value;
        sb->next->value = j;
    	sb = sb->next;
    }
}

void    ft_rr(t_stack *sb, t_stack *sa)
{
    ft_turn_rb(sb);
    ft_turn_ra(sa);
}

void    ft_rra(t_stack	*sa)
{
	int	j;

	while (sa->next != NULL)
	{
        sa = sa->next;
	}
	j = sa->value;
	while (sa->prev != NULL)
    {
        sa->value =  sa->prev->value;
        sa->prev->value = j;
    	sa = sa->prev;
    }
}

void    ft_rrb(t_stack	*sb)
{
	int i;

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

void    ft_rrr(t_stack	*sb, t_stack   *sa)
{
    ft_rrb(sb);
    ft_rra(sa);
}
