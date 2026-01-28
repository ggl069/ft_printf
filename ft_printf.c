/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaetani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:10:49 by ggaetani          #+#    #+#             */
/*   Updated: 2026/01/27 17:10:52 by ggaetani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	vrs;
	size_t	i;

	va_start(vrs, str);

	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_putchar_fd(va_arg(vrs, int), 1);
		i++;
	}

	return 0;
}

int	main(void)
{
	ft_printf("ciao &", 5);
}


