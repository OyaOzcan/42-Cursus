/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:07:46 by oyozcan           #+#    #+#             */
/*   Updated: 2023/11/30 18:25:50 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	stack_free(t_list *list)
{
	if (list != NULL)
	{
		if (list->stack_a != NULL)
			free(list->stack_a);
		if (list->stack_b != NULL)
			free(list->stack_b);
		if (list != NULL)
			free(list);
	}
}

int	count_element(char **av)
{
	char	**array;
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (av[i] != NULL)
	{
		array = ft_split(av[i], ' ');
		j = 0;
		while (array[j])
		{
			j++;
			count++;
		}
		i++;
		array_free(array);
	}
	return (count);
}

int	ft_atoin(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			error_message();
		if (str[0] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_message();
		res = (res * 10) + str[i++] - '0';
		if ((res < -2147483648) || (res > 2147483647))
			error_message();
	}
	res = res * sign;
	return (res);
}

int	count_words(char *str)
{
	int	count;
	int	new;

	count = 0;
	new = 1;
	while (*str)
	{
		if (*str != ' ' && new == 1)
		{
			count++;
			new = 0;
		}
		if (*str == ' ')
			new = 1;
		str++;
	}
	return (count);
}
