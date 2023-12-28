/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:10:02 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/28 15:34:02 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h> //kaldır
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft/libft.h"

static int	print_conv(char conv, va_list args)
{
	int	l;

	l = 0;
	if (conv == 'c')
		l += ft_putchar((char)va_arg(args, int));
	else if (conv == 's')
		l += ft_putstr(va_arg(args, char *));
	else if (conv == 'p')
		l += ft_putptr(va_arg(args, void *));
	else if (conv == 'd' || conv == 'i')
		l += ft_putint(va_arg(args, int));
	else if (conv == 'u')
		l += ft_putuint(va_arg(args, unsigned int));
	else if (conv == 'x')
		l += ft_putstr(itohexstr(va_arg(args, int), 1));
	else if (conv == 'X')
		l += ft_putstr(itohexstr(va_arg(args, int), 1));
	else if (conv == '%')
		l += ft_putchar('%');
	return (l);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	int		l;

	i = 0;
	l = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			l += write(1, &s[i], 1);
		else
			l += print_conv(s[i++ + 1], args);
		i++;
	}
	va_end(args);
	return (l);
}
/*
int main()
{
	//void *p = malloc(1);
	
	printf("Returns: %i\n", ft_printf("%u\n", -050));
	printf("Returns: %i\n", printf("%u\n", -050));
}
*/