/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:09:19 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/26 14:09:19 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTFT_H
# define LIBFTPRINTFT_H

# include <stdarg.h>
# include <unistd.h>
//# include "libft.h"

int		ft_printf(const char *, ...);
char	*ft_uitoa(unsigned int n);
char	*ptrtohexstr(int a, int capital);
char	*itohexstr(int a, int capital);

#endif