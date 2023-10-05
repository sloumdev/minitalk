/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:52:50 by abimkhio          #+#    #+#             */
/*   Updated: 2023/10/05 15:52:52 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (c == '\0')
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
/*
int		main()
{
	char a[] = "Olua, quem faula?";
	char b = 'u';

	char c[] = "Olua, quem faula?";
	char d = 'u';

	printf("%s\n", strrchr(a, b));

	printf("\n%s\n", ft_strrchr(c, d));

	return (0);
}*/