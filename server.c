/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:50:20 by amurcia-          #+#    #+#             */
/*   Updated: 2022/07/04 20:50:47 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_is_numeric(char *argv);
char	*ft_itoa(int n);
void	ft_putchar(char c);
int		ft_atoi(char *str);
void	ft_putstr(char *s);

static int	ft_print_pid(void)
{
	int		number_pid;
	char	*str_pid;

	number_pid = getpid();
	if (!number_pid)
	{
		ft_putstr("Error\nNo se puede proporcionar el PID");
		return (0);
	}
	str_pid = ft_itoa(number_pid);
	ft_putstr(str_pid);
	return (number_pid);
}

static void	ft_reception(int signal)
{
	static int				bit = 0;
	static unsigned char	c = '\0';

	c = c << 1;
	if (signal == SIGUSR1)
	{
	}
	else
		c = c | 1;
	bit++;
	if (bit == 8)
	{
		write (1, &c, 1);
		bit = 0;
		c = '\0';
	}
}

int	main(int argc, char **argv)
{
	int	pid_number;

	argv = NULL;
	if (argc != 1)
	{
		ft_putstr("Error\nNum. de parametros incorrecto\n");
		return (0);
	}
	pid_number = ft_print_pid ();
	signal(SIGUSR1, &ft_reception);
	signal(SIGUSR2, &ft_reception);
	while (1)
	{
		pause();
	}
	return (0);
}
