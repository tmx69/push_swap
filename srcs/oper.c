/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:48:17 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/27 16:33:59 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	ft_sa(t_stack	*a)
{
    int i;

    while (a->prev != NULL)
    {
        a = a->prev;
    }
    i = a->value;
    if (a->next != NULL)
    {
        a->value = a->next->value;
        a->next->value = i;
    }
}

void	ft_sb(t_stack	*sb)
{
    int i;
    if (sb)
    {
        i = sb->value;
        sb->value = sb->next->value;
        sb->next->value = i;
    }
}

void	ft_ss(t_stack	*sa, t_stack	*sb)
{
    ft_sa(sa);
    ft_sb(sb);

}

t_stack	*ft_add_start(t_stack *trt)
{
	t_stack *buf;
	t_stack *new;

	new = ft_listnew();
	buf = trt;
	while (buf->prev != NULL)
		buf = buf->prev;
	buf->prev = new;
	new->next = buf;
	new->prev = NULL;
	return (new);
}

void	ft_pa(t_stack **a, t_stack **b)
{
    if (b)
    {
        while ((*b)->prev != NULL)
        {
			(*b) = (*b)->prev;
		}
		(*a) = ft_listadd_start(*a);
		(*a)->value = (*b)->value;
	}
}

void	ft_pb(t_stack	**a, t_stack	**b)
{
    if (!(*b))
    {
        (*b) = ft_listnew();
    }
	else
	{
		(*b) = ft_listadd_start((*b));
	}
	if (a)
	{
		while ((*a)->prev != NULL)
        {
			(*a) = (*a)->prev;
		}
		(*b)->value = (*a)->value;
	}
}

// void    ft_turn_ra(t_stack	*sa)
// {
//     int i;

// 	i = sa->value;
//     while (sa->next != NULL)
//     {
//     	sa->value = sa->next->value;
//         sa->next->value = i;
//         sa = sa->next;
// 	}
// }
void    ft_turn_ra(t_stack	*sa)
{
    int i;


    while (sa->prev != NULL)
        sa = sa->prev;
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

    if (sb)
    {
	    j = sb->value;
        while (sb->next != NULL)
        {
            sb->value = sb->next->value;
            sb->next->value = j;
            sb = sb->next;
        }
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

void    ft_rrr(t_stack	*sb, t_stack   *sa)
{
    write(1, "rrr\n", 4);
    ft_rrb(sb);
    ft_rra(sa);
}
