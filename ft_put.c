/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:12:03 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/28 15:34:23 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putptr(void *p)
{
	int		l;
	char	*s;

	if (!p)
		return (write(1, "0x0", 3));
	l = 0;
	l += write(1, "0x", 2);
	s = itohexstr_l((uintptr_t)p, 0);
	l += ft_putstr(s);
	free(s);
	return (l);
}

int	ft_putint(int a)
{
	int		l;
	char	*s;

	l = 0;
	s = ft_itoa(a);
	l += ft_putstr(s);
	free(s);
	return (l);
}

int	ft_putuint(unsigned int a)
{
	int		l;
	char	*s;

	l = 0;
	s = ft_uitoa(a);
	l += ft_putstr(s);
	free(s);
	return (l);
}
