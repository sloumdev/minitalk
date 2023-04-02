/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:45:04 by abimkhio          #+#    #+#             */
/*   Updated: 2023/01/12 16:06:34 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenght_nb(unsigned long int nb)
{
	int		i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

void	ft_put_ptr(unsigned long int nb)
{
	if (nb >= 16)
	{
		ft_put_ptr(nb / 16);
		ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int		len_ptr;

	len_ptr = 0;
	if (ptr == 0)
		len_ptr += write(1, "(nil)", 5);
	else
	{
		len_ptr += write(1, "0x", 2);
		ft_put_ptr(ptr);
		len_ptr += lenght_nb(ptr);
	}
	return (len_ptr);
}
