/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:05:24 by oyozcan           #+#    #+#             */
/*   Updated: 2023/11/30 15:09:17 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list *list)
{
	int	i;

	i = 0;
	list->tmp = list->stack_a[0];
	while (i < list->size_a - 1)
	{
		list->stack_a[i] = list->stack_a[i + 1];
		i++;
	}
	list->stack_a[i] = list->tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list *list)
{
	int	i;

	i = 0;
	list->tmp = list->stack_b[0];
	while (i < list->size_b - 1)
	{
		list->stack_b[i] = list->stack_b[i + 1];
		i++;
	}
	list->stack_b[i] = list->tmp;
	write(1, "rb\n", 3);
}

void	rr(t_list *list)
{
	rotate_a(list);
	rotate_b(list);
	write(1, "rr\n", 3);
}
