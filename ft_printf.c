/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:43 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/18 16:25:41 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
// #include "libft/libft.h"

// int percent_spe_q(char *format, int i)
// {
// 	if (format[i] == '%' && format[i - 1] != '%' &&
// 		format[i + 1] != '%')
// 		return (1);
// 	return (0);
// }

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x'
		|| c == '%')
		return (1);
	return (0);
}

int percent_spe_q(char *format, int i)
{
	int	j;
	
	j = 0;
	while(format[i++] == '%')
		j++;
	if (j % 2 == 0)
		return (1);
	else
		return (0);
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
		i++;
	while (ft_isdigit(format[i]))
		i++;
	if (is_specifier(format[i]))
		return(1);
	return (0);
}

int get_nbr_specifiers(char *format)
{
	int i;
	int count;
	
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && percent_spe_q(format, i))
			count++;
		i++;
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int		nbr_specifiers;
	int		i;

	nbr_specifiers = get_nbr_specifiers((char *)format);
	printf("%d\n", nbr_specifiers);
	i = 0;
	if (nbr_specifiers)
	{
		va_start(args, format);
		// while (i < nbr_specifiers)
			// va_arg(args, type);

		va_end(args);
	}
	return (0);
}

int main(void)
{
	ft_printf("Hello World!");
	ft_printf("Hello %!");
	ft_printf("Hello %%!");
	ft_printf("Hello %%%!");
	ft_printf("%%%%");
	ft_printf("%%%%%%");
	ft_printf("%%%%%%%");
	ft_printf("%%%%%%%%");
	ft_printf("%%%%%%%%%");
	ft_printf("%%%%%%%%%%");
	ft_printf("%%%%%%%%%%c");
	ft_printf("%%%%%%%%%%d");
	ft_printf("%%%%%%%%%%%");

	return (0);
}
