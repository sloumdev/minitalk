/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:22:41 by abimkhio          #+#    #+#             */
/*   Updated: 2023/01/12 16:48:43 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	ptr = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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
