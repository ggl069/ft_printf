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

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


void	print_str(int *count, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
		(*count)++;
	}
}

void	print_int(int *count, int num)
{
	char	*str_num;
	size_t	len;

	str_num = ft_itoa(num);
	if (!str_num)
		return ;
	len = ft_strlen(str_num);
	write(1, str_num, len);
	*count += len;
	free(str_num);
}

void	print_hex(int *count, int num, int is_upper)
{
	size_t	i;
	char	*hex_num;
	char	*base;

	i = 0;
	hex_num = malloc(sizeof(char) * 16);
	if (!hex_num)
		return ;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		free(hex_num);
		return ;
	}
	while (num != 0)
	{
		hex_num[i] = base[num % 16];
		num = num / 16;
		i++;
	}
	hex_num[i] = '\0';
	ft_strflip(hex_num);
	ft_putstr_fd(hex_num, 1);
	(*count)++;
	free(hex_num);
}

void	print_uns_int(int *count, unsigned int	num)
{
	char	*ns;
	size_t	i;

	i = 0;
	while (num[i])
	ft_putstr_fd(ns, 1);
}
int	print_right_type(char type, va_list *list, int *count)
{
	if (type == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
	else if (type == 'c')
	{
		ft_putchar_fd(va_arg(*list, int), 1);
		(*count)++;
	}
	else if (type == 's')
		print_str(count, va_arg(*list, char *));
	else if (type == 'd' || type == 'i')
		print_int(count, va_arg(*list, int));
	else if (type == 'x')
		print_hex(count, va_arg(*list, int), 0);
	else if (type == 'X')
		print_hex(count, va_arg(*list, int), 1);
	//else if (type == 'u')

	//else if (type == 'p')

	return (*count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		cnt;
	va_list	vrs;

	va_start(vrs, str);
	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_right_type(str[i + 1], &vrs, &cnt);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			cnt++;
		}
		i++;
	}

	va_end(vrs);

	return (0);
}

int	main(void)
{
	ft_printf("final print: %X \n", 648332432);
}


