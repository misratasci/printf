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
#include <stdint.h>
#include <string.h> //strlen'i ft ile değişince kaldır, libft ekle

void	print_conv(char conv, void *arg)
{
	uintptr_t ptr;
	
	if (conv == 'c')
		write(1, &arg, 1);
	else if (conv == 's')
		write(1, arg, strlen(arg)); //ft ile değiş
	else if (conv == 'p')
	{
		ptr = (uintptr_t)arg;
		write(1, &ptr, 1);
	}
		
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
			print_conv(s[i + 1], va_arg(args, void *));
			i++;
		}
		i++;
	}
	va_end(args);
	return (0);
}
int main()
{
	void	*ptr;
	ptr = malloc(1);
	ft_printf("123 %p-", ptr);
}