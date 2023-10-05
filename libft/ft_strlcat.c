/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:51:57 by abimkhio          #+#    #+#             */
/*   Updated: 2023/10/05 15:52:01 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	j = len_dest;
	i = 0;
	if (size == 0)
		return (len_src);
	if (size < len_dest)
		return (len_src + size);
	while (src[i] != '\0' && j < (size - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len_dest + len_src);
}
/*
int main(void)
{
	char src[] = "plays";
	char dest[16] = "juninho ";

	printf("%ld\n", ft_strlcat(dest, src, 16));
	printf("%s\n", dest);
}*/