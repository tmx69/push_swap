/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:40:24 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/18 13:56:49 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void		del2(t_stack **head, t_stack **pn)
{
    t_stack *tail;
	t_stack *temp;
  if (*pn == *head) // если найденная запись - первая
            {
                (*head) = (*pn)->next;
                (*head)->prev = NULL;
				free((*pn));
				(*pn) = (*head)->next;
            }
       		else if ((*pn)->next == NULL) // если найденная запись - последняя
                {
                    tail = (*pn)->prev;
                    tail->next = NULL;
                    free((*pn));
                    (*pn) = tail;
                }
            else  // удаление из средины списка
            {
                    (*pn)->next->prev = (*pn)->prev;
                    (*pn)->prev->next = (*pn)->next;
                    temp = (*pn);
                    (*pn) = (*pn)->next;
                    free(temp);
                }
}

t_stack	 *del(int i, t_stack **head)
{
    t_stack *pn;

    pn = *head;
    while (pn != NULL)
    {
        if (pn->prev == NULL && pn->next == NULL)
        {
            (*head) = NULL;
            free(pn);
            break ;
        }
        if (pn->value == i)
        {
          del2(head, &pn);
        }
        else
		    pn=pn->next;
	}
	return (*head);
}

void	str_check(char *av)
{
	int j;

	j = 0;
	while (av[j])
	{
		if (ft_isdigit(av[j]) == 0 && av[j] != ' ')
		{
			if (!(av[j] == 45 && av[j + 1] > 47
				&& av[j + 1] < 58))
				ft_error();
		}
		j++;
	}
}

void	str_arg(t_stack *a, char *av)
{
	int j;
	int c;
	int	minus;
	int flagg;

	minus = 0;
	j = -1;
	c = 0;
	flagg = 0;
	while (av[++j])
	{
		if (ft_isdigit(av[j]) == 1)
		{
			c = c * 10 + (av[j] - '0');
			if ((av[j + 1] == ' ') || (av[j + 1] == '\0'))
			{
				flagg == 1 ? a = ft_listadd(a) : 0;
				minus == 1 ? (c = c * -1) && minus-- : 0;
				a->value = c;
				c = 0;
				flagg == 0 ? flagg++ : 0;
			}
		}
		av[j] == 45 ? minus = 1 : 0;
	}
}
// t_stack	 *del(int i, t_stack **head)
// {
//     t_stack *pn;
// 	t_stack *tail;
// 	t_stack *temp;
//     // while (head->prev != NULL)
//     // {
//     //     head = head->prev;
//     // }
//     pn = *head;
//     while (pn != NULL)
//     {
//         if (pn->prev == NULL && pn->next== NULL) // если запись единственная
//         {
//             (*head) = NULL;
//             free(pn);
//             break ;
//         }
//         if (pn->value == i) // если найдена заданная страна
//         {
//             if (pn == *head) // если найденная запись - первая
//             {
//                 (*head) = pn->next;
//                 (*head)->prev = NULL;
// 				free(pn);
// 				pn = (*head)->next;
//             }
//        		else if (pn->next == NULL) // если найденная запись - последняя
//                 {
//                     tail = pn->prev;
//                     tail->next = NULL;
//                     free(pn);
//                     pn = tail;
//                 }
//             else  // удаление из средины списка
//             {
//                     pn->next->prev = pn->prev;
//                     pn->prev->next = pn->next;
//                     temp = pn;
//                     pn=pn->next;
//                     free(temp);
//                 }
//         }
//         else // если заданная страна не найдена – продвигаемся по списку
// 		    pn=pn->next;
// 	}
//     // if (head == NULL)
//     //     return (NULL);
// 	return (*head);
// }