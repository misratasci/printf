/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:42:00 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/28 16:00:05 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	ft_puthex(unsigned int a, int capital)
{
	int		l;
	char	*s;

	l = 0;
	if (capital)
		s = itohexstr(a, 1);
	else
		s = itohexstr(a, 0);
	l += ft_putstr(s);
	free(s);
	return (l);
}
