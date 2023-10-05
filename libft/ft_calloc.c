/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:45:52 by abimkhio          #+#    #+#             */
/*   Updated: 2023/10/05 15:54:46 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char			*a;
	unsigned int	tot;
	size_t			i;

	tot = size * nitems;
	a = malloc(size * nitems);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (tot > 0)
	{
		a[i] = 0;
		i++;
		tot--;
	}
	return ((void *)a);
}
