/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:17:07 by oyozcan           #+#    #+#             */
/*   Updated: 2023/12/02 12:17:10 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(char **str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (ft_isdigit(str[i][j]))
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
			error_message();
		flag = 0;
	}
}

void	check_arguments(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((!ft_isdigit(av[i][j]) && av[i][j] != '-'
					&& av[i][j] != '+' && av[i][j] != ' ')
				|| (av[i][j] == '-' && av[i][j + 1] == '\0')
				|| (av[i][j] == '+' && av[i][j + 1] == '\0')
				|| (av[i][j] == '-' && av[i][j + 1] == ' ')
				|| (av[i][j] == '+' && av[i][j + 1] == ' '))
			{
				error_message();
			}
			j++;
		}
	}
}

void	check_duplicate(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (i < list->size_a - 1)
	{
		j = i + 1;
		while (j < list->size_a)
		{
			if (list->stack_a[i] == list->stack_a[j])
			{
				stack_free(list);
				error_message();
			}
			j++;
		}
		i++;
	}
}

int	check_sorted(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->size_a - 1)
	{
		if (list->stack_a[i] > list->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
