/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:09:17 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/16 19:12:29 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_putpid(int n)
{
	char	c;
	int		i;

	i = 0;
	if (n > 9)
	i += ft_putpid(n / 10);
	c = '0' + (n % 10);
	i += write(1, &c, 1);
	return (i);
}

void	make_word(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	output;

	(void) context;
	if (signal == SIGUSR1)
		output |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (output == 0)
			kill(info->si_pid, SIGUSR2);
		write(1, &output, 1);
		output = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	int					pid;

	(void) av;
	if (ac != 1)
		write(1, "errore numero di parametri", 26);
	pid = getpid();
	ft_putpid(pid);
	write(1, "\n", 1);
	act.sa_sigaction = make_word;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
