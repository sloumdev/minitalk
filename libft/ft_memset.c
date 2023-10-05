/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:49:15 by abimkhio          #+#    #+#             */
/*   Updated: 2023/10/05 16:10:39 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t			i;
	unsigned char	*conv_ptr;

	i = 0;
	conv_ptr = (unsigned char *)ptr;
	while (i < n)
	{
		conv_ptr[i] = c;
		i++;
	}
	return (ptr);
}
