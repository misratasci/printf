/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:10:02 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/26 11:10:02 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft/libft.h"

char	*itohexstr(int a, int capital)
{
	char	*s;
	size_t	len;
	int		aa;
	size_t	org_len;

	aa = a;
	len = 1;
	while (aa > 15)
	{
		len++;
		aa /= 16;
	}
	org_len = len;
	s = (char *)malloc((len + 3) * sizeof(char));
	s[0] = '0';
	s[1] = '0';
	while (len > 0)
	{
		if (a % 16 < 10)
			s[len + 1] = a % 16 + '0';
		else if (a % 16 >= 10 && capital)
			s[len + 1] = a % 16 - 10 + 'A';
		else if (a % 16 >= 10 && !capital)
			s[len + 1] = a % 16 - 10 + 'a';
		a /= 16;
		len--;
	}
	s[org_len + 2] = 0;
	return (s);
}

va_list	print_conv(char conv, va_list args)
{
	if (conv == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	else if (conv == 's')
		ft_putstr_fd(va_arg(args, char*), 1);
	else if (conv == 'p')
		ft_putstr_fd(itohexstr(va_arg(args, int), 1), 1);
	else if (conv == 'd')
		ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
	return (args);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			write(1, &s[i], 1);
		else
		{

			args = print_conv(s[i++ + 1], args);
		}
		i++;
	}
	va_end(args);
	return (0);
}
int main()
{
	void *p = malloc(1);
	ft_printf("-%c-%s-%p-%d\n", '9', "abcd", p, -456);
	printf("-%c-%s-%p-%d\n", '9', "abcd", p, -456);
}