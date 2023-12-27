/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohexstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:08:44 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/27 16:08:44 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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