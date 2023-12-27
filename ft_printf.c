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

static va_list	print_conv(char conv, va_list args)
{
	if (conv == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	else if (conv == 's')
		ft_putstr_fd(va_arg(args, char*), 1);
	else if (conv == 'p')
		ft_putstr_fd(ptrtohexstr(va_arg(args, int), 1), 1);
	else if (conv == 'd' || conv == 'i')
		ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
	else if (conv == 'u')
		ft_putstr_fd(ft_uitoa(va_arg(args, unsigned int)), 1);
	else if (conv == 'x')
		ft_putstr_fd(itohexstr(va_arg(args, int), 1), 0);
	else if (conv == 'X')
		ft_putstr_fd(itohexstr(va_arg(args, int), 1), 1);
	else if (conv == '%')
		ft_putchar_fd('%', 1);
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
			args = print_conv(s[i++ + 1], args);
		i++;
	}
	va_end(args);
	return (0);
}
int main()
{
	void *p = malloc(1);
	ft_printf("-%c-%s-%p-%x\n", '9', "abcd", p, 33);
	printf("-%c-%s-%p-%x\n", '9', "abcd", p, 33);
}