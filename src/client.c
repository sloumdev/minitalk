/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:57:06 by abimkhio          #+#    #+#             */
/*   Updated: 2023/10/05 15:57:10 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//ordem dos argumentos:
//./minitalk <PID> <mensagem>
void	args_check(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 3)
	{
		ft_printf("Invalid number of params");
		exit(EXIT_FAILURE);
	}
	while (argv[1][++i])
	{	//pid nao pode possuir caracteres que nao sao numeros
		if (!ft_strchr("0123456789", argv[1][i]))
		{
			ft_printf("Incorrect PID!");
			exit(EXIT_FAILURE);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("Empty message");
		exit(EXIT_FAILURE);
	}
}

//envio a mensagem bit a bit 
void	send_msg(int sv_pid, char *msg)
{
	unsigned char	c;
	int				nbr_bits;

	while (*msg)
	{
		c = *msg;
		nbr_bits = 8; //cada byte tem 8 bits
		while (nbr_bits--)
		{
			if (c & 0b10000000) //compara o bit atual a 1
				kill(sv_pid, SIGUSR1); //envio 1
			else
				kill(sv_pid, SIGUSR2); //envio 0
			usleep(50); //suspende a execucao por 50 microsegundos para que o o server possa receber e tratar a mensagen
			c <<= 1; //anda um bit pra esquerda 
		}
		msg++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Signal coming out!\n");
}

//crio um novo sinal, indico a flag e a funcao handler e configuro os sinais SIGUSR1 e SIGUSR2
void	config_signals(void)
{
	struct sigaction	new_sig;

	new_sig.sa_handler = &sig_handler;
	new_sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &new_sig, NULL) == -1)
		ft_printf("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &new_sig, NULL) == -1)
		ft_printf("Failed to change SIGUSR2's behavior");
}

int	main(int argc, char **argv)
{
	ft_printf("CLIENT PID = %d\n\n", getpid());
	args_check(argc, argv); //funcao que checka se os argumentos foram passados na forma correta
	config_signals(); //settar os sinais
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
