/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:21:13 by abimkhio          #+#    #+#             */
/*   Updated: 2022/12/05 12:53:17 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long n)
{
	size_t	num_size;

	num_size = 0;
	if (n < 0)
	{
		num_size++;
		n = -n;
	}
	while (n >= 1)
	{
		num_size++;
		n /= 10;
	}
	return (num_size);
}

static char	*ft_gen(char *result, long nbr, int len)
{
	int		neg_flag;

	if (nbr != 0)
		result = malloc(sizeof(char) * (len + 1));
	else
		return (result = ft_strdup("0"));
	if (!result)
		return (NULL);
	neg_flag = 0;
	if (nbr < 0)
	{
		neg_flag++;
		nbr = -nbr;
	}
	result[len] = '\0';
	while (--len)
	{
		result[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg_flag == 1)
		result[0] = '-';
	else
		result[0] = (nbr % 10) + '0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	nbr;

	nbr = n;
	len = ft_size(nbr);
	result = 0;
	result = ft_gen(result, nbr, len);
	if (!(result))
		return (0);
	return (result);
}
