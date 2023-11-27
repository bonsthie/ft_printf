/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flag.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:31:40 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/26 07:07:21 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_FLAG_H
#define CREATE_FLAG_H

#include "format_parser.h"

t_flag *create_flag_char(const char *start, const char *end);

int complete_struct(t_flag *flag, const char *precision, const char *length_flag);
int is_valid_flag(const char *start, const char *end);

t_flag *create_flag(const char *start, const char *end, char precision, char *prefer_length);


#endif
