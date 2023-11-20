/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:17:21 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/20 21:58:28 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *format, ...);


int manage_flag(const char *flag, va_list args, int *count);
int is_chars(const char c, const char *str);
int putstr_len_fill_after(char *str, int len, char fill_char);
int putstr_len_fill_before(char *str, int len, char fill_char);


char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int nb);
char	*ft_uitoa_base(int nb, char *base, int base_len);
int	ft_putstr(char *str);
int	ft_isdigit(int num);
int ft_putchar(char c);


#endif
