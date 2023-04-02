/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:29:49 by abimkhio          #+#    #+#             */
/*   Updated: 2023/01/13 10:36:33 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list ptr, const char format)
{
	int	lenght;

	lenght = 0;
	if (format == 'c')
		lenght += ft_printchar(va_arg(ptr, int));
	else if (format == 's')
		lenght += ft_printstr(va_arg(ptr, char *));
	else if (format == 'p')
		lenght += ft_print_ptr(va_arg(ptr, unsigned long long));
	else if (format == 'd' || format == 'i')
		lenght += ft_printnbr(va_arg(ptr, int));
	else if (format == 'u')
		lenght += ft_print_unsigned(va_arg(ptr, unsigned int));
	else if (format == 'x' || format == 'X')
		lenght += ft_print_hexa(va_arg(ptr, unsigned int), format);
	else if (format == '%')
		lenght += ft_printpercent();
	return (lenght);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		ptr;
	int			print_len;

	i = 0;
	print_len = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_format(ptr, str[i + 1]);
			i++;
		}
		else
			print_len += ft_printchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (print_len);
}

/* int main()
{
	ft_printf("this is an int %0d\n", 0); 
	printf("this is an int %0d", 0);


    return 0;
} */