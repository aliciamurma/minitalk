/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:12:38 by amurcia-          #+#    #+#             */
/*   Updated: 2022/07/01 16:12:46 by amurcia-         ###   ########.fr       */
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
		exit (0);
	}
	str_pid = ft_itoa(number_pid);
	ft_putstr(str_pid);
	return (0);
}

static void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = '\0';

	usleep(100);
	(void) context;
	c = c << 1;
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
	{
		c = c | 1;
		kill(info->si_pid, SIGUSR1);
	}
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			usleep(400);
			kill(info->si_pid, SIGUSR2);
		}
		write (1, &c, 1);
		bit = 0;
		c = '\0';
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	msj1;
	struct sigaction	msj2;

	argv = NULL;
	if (argc != 1)
	{
		ft_putstr("Error\nNum. de parametros incorrecto\n");
		return (0);
	}
	ft_print_pid ();
	msj1.sa_flags = SA_SIGINFO;
	msj1.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &msj1, NULL);
	msj2.sa_flags = SA_SIGINFO;
	msj2.sa_sigaction = ft_handler;
	sigaction(SIGUSR2, &msj2, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
