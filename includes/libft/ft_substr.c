/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:11:13 by abimkhio          #+#    #+#             */
/*   Updated: 2022/11/29 12:45:53 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	slen;

	slen = ft_strlen(s);
	i = 0;
	j = 0;
	if (start < slen)
		i = slen - start;
	if (i > len)
		i = len;
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (j < i)
	{
		ptr[j] = s[start + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
