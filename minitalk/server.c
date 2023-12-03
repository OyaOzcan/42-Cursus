/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:04:31 by oyozcan           #+#    #+#             */
/*   Updated: 2023/08/31 16:04:34 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

void	get_message(int sig)
{
	static char	str = 0;
	static int	bit_count = 0;

	if (sig == SIGUSR1)
		str = str | 1;
	if (++bit_count == 8)
	{
		bit_count = 0;
		write(1, &str, 1);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	int		id;
	char	*pid;

	id = getpid();
	pid = ft_itoa(id);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	signal(SIGUSR1, get_message);
	signal(SIGUSR2, get_message);
	while (1)
	{
		pause();
	}
	return (0);
}
