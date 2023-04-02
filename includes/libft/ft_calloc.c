/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:26:17 by abimkhio          #+#    #+#             */
/*   Updated: 2022/12/07 11:24:02 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t tnmemb, size_t size)
{
	void	*ptr;

	if (size > 0 && tnmemb * size / size != tnmemb)
		return (NULL);
	ptr = malloc(tnmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, tnmemb * size);
	return (ptr);
}
