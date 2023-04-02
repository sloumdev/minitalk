/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:58:46 by abimkhio          #+#    #+#             */
/*   Updated: 2022/11/28 09:54:13 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*desti;
	unsigned char	*sourc;

	desti = (unsigned char *)dest;
	sourc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		desti[i] = sourc[i];
		i ++;
	}
	return (dest);
}
