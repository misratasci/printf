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

int	ft_printf(const char *s, ...)
{
	va_list args;
	va_start(args, s);
	printf("%s\n", va_arg(args, int));
	va_end(args);
}