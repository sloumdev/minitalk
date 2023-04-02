/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abimkhio <abimkhio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:43:21 by abimkhio          #+#    #+#             */
/*   Updated: 2023/01/12 16:13:08 by abimkhio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hexa(unsigned int num, const char format);
int		ft_printpercent(void);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);

#endif