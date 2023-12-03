/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:55:48 by oyozcan           #+#    #+#             */
/*   Updated: 2023/11/12 11:55:50 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *list)
{
	int	tmp;
	int	*stack_a;

	stack_a = list->stack_a;
	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_list *list)
{
	int	tmp;
	int	*stack_b;

	stack_b = list->stack_b;
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list *list)
{
	swap_a(list);
	swap_b(list);
	write(1, "ss\n", 1);
}

void	push_a(t_list *list)
{
	int	i;
	int	j;

	i = list->size_a;
	list->size_a++;
	while (i > 0)
	{
		list->stack_a[i] = list->stack_a[i - 1];
		i--;
	}
	list->stack_a[0] = list->stack_b[0];
	j = 0;
	while (j < list->size_b - 1)
	{
		list->stack_b[j] = list->stack_b[j + 1];
		j++;
	}
	list->size_b--;
	write(1, "pa\n", 3);
}

void	push_b(t_list *list)
{
	int	i;
	int	j;

	i = list->size_b;
	list->size_b++;
	while (i > 0)
	{
		list->stack_b[i] = list->stack_b[i - 1];
		i--;
	}
	list->stack_b[0] = list->stack_a[0];
	j = 0;
	while (j < list->size_a - 1)
	{
		list->stack_a[j] = list->stack_a[j + 1];
		j++;
	}
	list->size_a--;
	write(1, "pb\n", 3);
}
