/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:05:17 by oyozcan           #+#    #+#             */
/*   Updated: 2023/11/30 15:05:18 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all(t_list *list, int len)
{
	if (len == 2)
		sort_two(list);
	else if (len == 3)
		sort_three(list);
	else if (len > 3 && len <= 5)
		sort_five(list);
	else if (len > 5)
		radix_sort(list);
}

void	sort_two(t_list *list)
{
	if (list->stack_a[0] > list->stack_a[1])
	{
		swap_a(list);
	}
}

void	sort_three(t_list *list)
{
	if (list->stack_a[0] > list->stack_a[1]
		&& list->stack_a[0] > list->stack_a[2])
	{
		if (list->stack_a[1] > list->stack_a[2])
		{
			swap_a(list);
			reverse_rotate_a(list);
		}
		else
			rotate_a(list);
	}
	else if ((list->stack_a[1] > list->stack_a[0]
			&& list->stack_a[1] > list->stack_a[2]))
	{
		if (list->stack_a[0] > list->stack_a[2])
			reverse_rotate_a(list);
		else
		{
			swap_a(list);
			rotate_a(list);
		}
	}
	else
		swap_a(list);
}

void	sort_five(t_list *list)
{
	while (list->size_b <= 1)
	{
		if (list->stack_a[0] == 0 || list->stack_a[0] == 1)
			push_b(list);
		else
			rotate_a(list);
	}
	if (list->stack_b[0] == 0)
		swap_b(list);
	if (list->size_a == 3 && check_sorted(list) == 0)
		sort_three(list);
	else
		sort_two(list);
	push_a(list);
	push_a(list);
}
