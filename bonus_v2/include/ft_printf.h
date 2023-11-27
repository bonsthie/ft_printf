/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:18:50 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/27 00:59:17 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "format_parser.h"

# define BASE_16_LOW "0123456789abcdef"
# define BASE_16_UP "0123456789ABCDEF"
# define BASE_10 "0123456789"

int ft_printf(const char *format, ...);


t_flag  *format_parsing(const char *format, int *status);
char	*ft_ultoa_base(unsigned long nb, char *base, int base_len);

#endif
