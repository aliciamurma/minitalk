/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:09:16 by amurcia-          #+#    #+#             */
/*   Updated: 2022/07/01 16:09:35 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int		ft_is_numeric(char *argv);
char	*ft_itoa(int n);
void	ft_putchar(char c);
int		ft_atoi(char *str);
void	ft_putstr(char *s);

//CONVERTIMOS EL CHAR EN BINARIO, DE UNO EN UNO,
//POR ESO C <<= 1, PARA DESPLAZAR LOS BITS
static void	ft_ascii_to_bin(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << (7 - bit))) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr("Error\n");
				exit (0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr("Error\n");
				exit (0);
			}
		}
		bit++;
		usleep(400);
	}
}

static void	ft_send_signal(int pid, char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
	{
		ft_ascii_to_bin(str[cont], pid);
		cont++;
	}
}

//EN EL CONTROL DE ERRORES MIRAMOS QUE HAYA 3 PARAMETROS
//Y QUE LO SEGUNDO QUE LE DAMOS SEA EL PID, QUE SON NUMEROS
int	main(int argc, char **argv)
{
	int	pid;

	pid = 1;
	if (argc != 3)
	{
		ft_putstr("Error\nNum. de parametros incorrecto\n");
		return (0);
	}
	if (ft_is_numeric(argv[1]) == -1)
	{
		ft_putstr("Error\nDame un PID correct\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_putstr("Error\nError en el PID\n");
		return (0);
	}
	ft_send_signal(pid, argv[2]);
	return (0);
}
