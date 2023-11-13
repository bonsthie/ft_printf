/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:35 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/12 00:04:41 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *format, ...);

void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_base(unsigned long n, char *base, unsigned long base_size,
                    int *count);
void ft_putnbr_count(int n, int *count);
size_t ft_strlen(const char *str);
int manage_char(va_list var, const char type);
int print_pointer(unsigned long pointer);


#endif
