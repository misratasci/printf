/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohexstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:16:48 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/28 16:03:08 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //kaldır

static size_t	char_count(unsigned int a)
{
	size_t	len;

	len = 1;
	while (a > 15)
	{
		len++;
		a /= 16;
	}
	return (len);
}

char	*itohexstr(unsigned int a, int capital)
{
	char	*s;
	size_t	len;
	size_t	org_len;

	len = char_count(a);
	org_len = len;
	s = (char *)malloc((len + 1) * sizeof(char));
	if (a == 0)
		s[0] = '0';
	while (a > 0)
	{
		if (a % 16 < 10)
			s[len-- - 1] = a % 16 + '0';
		else if (a % 16 >= 10 && capital)
			s[len-- - 1] = a % 16 - 10 + 'A';
		else if (a % 16 >= 10 && !capital)
			s[len-- - 1] = a % 16 - 10 + 'a';
		a /= 16;
	}
	s[org_len] = 0;
	return (s);
}

static size_t	char_count_l(unsigned long long int a)
{
	size_t	len;

	len = 1;
	while (a > 15)
	{
		len++;
		a /= 16;
	}
	return (len);
}

char	*itohexstr_l(unsigned long long int a, int capital)
{
	char	*s;
	size_t	len;
	size_t	org_len;

	len = char_count_l(a);
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
		a /= 16;
	}
	s[org_len] = 0;
	return (s);
}
