/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohexstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:16:48 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/27 16:16:48 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //kaldır

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
	s = (char *)malloc((len + 1) * sizeof(char));
	while (a > 0)
	{
		if (a % 16 < 10)
			s[len-- - 1] = a % 16 + '0';
		else if (a % 16 >= 10 && capital)
			s[len-- - 1] = a % 16 - 10 + 'A';
		else if (a % 16 >= 10 && !capital)
			s[len-- - 1] = a % 16 - 10 + 'a';
		printf("%c - %d\n", s[len], a);
		a /= 16;
	}
	s[org_len] = 0;
	return (s);
}