/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:48:34 by abimkhio          #+#    #+#             */
/*   Updated: 2023/10/05 15:48:36 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*conv_str;

	i = 0;
	conv_str = (unsigned char *)str;
	while (conv_str[i] != '\0' && i < n)
	{
		if (conv_str[i] == (unsigned char)c)
			return (conv_str + i);
		i++;
	}
	return (NULL);
}
/*
int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '/';
   char *ret;

   ret = ft_memchr(str, ch, 6);

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}*/