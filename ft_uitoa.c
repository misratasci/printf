/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:03:39 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/27 16:03:39 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static size_t	char_count(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	len;
	size_t	org_len;

	len = char_count(n);
	org_len = len;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len-- - 1] = n % 10 + '0';
		n /= 10;
	}
	str[org_len] = 0;
	return (str);
}
