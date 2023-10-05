/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:49:15 by abimkhio          #+#    #+#             */
/*   Updated: 2023/10/05 15:49:18 by abimkhio         ###   ########.fr       */
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
/*
int		main()
{
	char a[] = "Esta frase não tem nada cá dentro.";
	char b[] = "Esta frase não tem nada cá dentro.";
	char c = 's';

	printf("\n%s \n", a);
	memset(a + 5, c, 2);
	printf("%s\n", a);

	printf("\n%s \n", b);
	ft_memset(b + 5, c, 2);
	printf("%s\n", b);
}*/