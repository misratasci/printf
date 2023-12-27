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
#include <string.h> //strlen'i ft ile değişince kaldır, libft ekle

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

void	print_conv(char conv, void *arg)
{

	if (conv == 'c')
		write(1, &arg, 1);
	else if (conv == 's')
		write(1, arg, strlen(arg)); //ft ile değiş
	else if (conv == 'p')
		write(1, itohexstr((int)arg, 1), strlen(itohexstr((int)arg, 1))); //bunu da
	else if (conv == 'd')	
		write(1, ft_itoa(arg), strlen(ft_itoa(arg))); //bu da
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