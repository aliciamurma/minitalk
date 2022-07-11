/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:50:11 by amurcia-          #+#    #+#             */
/*   Updated: 2022/07/01 16:53:13 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_is_numeric(char *argv)
{
	int	cont;

	cont = 0;
	while (argv[cont])
	{
		if (argv[cont] < 48 || argv[cont] > 57)
			return (-1);
		cont++;
	}
	return (1);
}
