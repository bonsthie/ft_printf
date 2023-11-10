/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:24:18 by marde-vr          #+#    #+#             */
/*   Updated: 2023/11/09 16:54:46 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main (void)
{

	int	n;
	n = ft_printf("%|abc%");
	printf("\nret : %d\n",n);
	fflush(stdout);
	n = printf("%|abc%");
	printf("\nret : %d\n",n);
	
	n = ft_printf("abc%");
	printf("\nret : %d\n",n);
	fflush(stdout);

	n = printf("abc%");
	printf("\nret : %d\n",n);

	/*
	n = ft_printf("    %");
	printf("\nret : %d\n",n);
	fflush(stdout);

	n = printf("    %");
	printf("\nret : %d\n",n);
	*/
}
