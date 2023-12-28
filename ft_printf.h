/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:09:19 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/28 15:20:07 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
//# include "libft.h"

int		ft_printf(const char *s, ...);
char	*ft_uitoa(unsigned int n);
char	*ptrtohexstr(int a, int capital);
char	*itohexstr(int a, int capital);
char	*itohexstr_l(int a, int capital);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(void *p);

#endif