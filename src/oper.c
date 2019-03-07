/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:48:17 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/07 15:05:00 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	ft_sa(t_stacka	*sa)
{
    int i;

    i = sa->a;
    sa->a = sa->next->a;
    sa->a = i;
}

void	ft_sb(t_stackb	*sb)
{
    int i;

    i = sb->b;
    sb->b = sb->next->b;
    sb->b = i;
}

void	ft_ss(t_stacka	*sa, t_stackb	*sb)
{
    ft_sa(sa);
    ft_sb(sb);

}

void	ft_pa(t_stacka	*sa, t_stackb	*sb)
{
    sa->a = sb->b;
}

void	ft_pb(t_stacka	*sa, t_stackb	*sb)
{
    sa->a = sb->b;
}

void    ft_turn_ra(t_stacka	*sa)
{
    int i;

	i = sa->a;
    while (sa->next != NULL)
    {
    	sa->a =  sa->next->a;
        sa->next->a = i;
        sa = sa->next;
	}
}

void    ft_turn_rb(t_stackb	*sb)
{
	int	j;

	j = sb->b;
    while (sb->next != NULL)
    {
        sb->b =  sb->next->b;
        sb->next->b = j;
    	sb = sb->next;
    }
}

void    ft_rr(t_stackb *sb, t_stacka *sa)
{
    ft_turn_rb(sb);
    ft_turn_ra(sa);
}

void    ft_rra(t_stacka	*sa)
{
	int	j;

	while (sa != NULL)
	{
        sa = sa->next;
	}
	j = sa->a;
	while (sa->prev != NULL)
    {
        sa->a =  sa->prev->a;
        sa->prev->a = j;
    	sa = sa->prev;
    }
}

void    ft_rrb(t_stackb	*sb)
{
	int i;

	while (sb != NULL)
    {
        sb = sb->next;
    }
	i = sb->b;
	while (sb->prev != NULL)
    {
        sb->b = sb->prev->b;
        sb->prev->b = i;
    	sb = sb->prev;
    }
}

void    ft_rrr(t_stackb	*sb, t_stacka   *sa)
{
    ft_rrb(sb);
    ft_rra(sa);
}
