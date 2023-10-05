/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:53:22 by abimkhio          #+#    #+#             */
/*   Updated: 2023/10/05 15:53:26 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (ch);
}
/*
int main(void) 
{
	char c;

	c = 'm';
	printf("%c -> %c", c, ft_toupper(c));

	c = 'D';
	printf("\n%c -> %c", c, ft_toupper(c));

	c = '9';
	printf("\n%c -> %c", c, ft_toupper(c));
	return (0);
}*/