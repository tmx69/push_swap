/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:40:24 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/11 16:43:20 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

t_stacka *ft_listadd_a(t_stacka *trt)
{
	t_stacka *buf;
	t_stacka *new;

	new = ft_listnew();
	buf = trt;
	while (buf->prev != NULL)
		buf = buf->prev;
	buf->prev = new;
	new->next = buf;
	new->prev = NULL;
	return (new);
}