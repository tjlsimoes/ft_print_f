/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:43 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/19 13:07:34 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
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

int	percent_spe_q(char *format, int i)
{
	int	j;
	
	j = 0;
	while(format[i] == '%')
	{
		j++;
		i++;
	}
	if (j % 2 == 0)
		return (1);
	else if (j % 2 != 0 && j != 1)
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

char	get_specifier(char *format, int i)
{
	while(format[i] == '%')
		i++;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
		i++;
	while (ft_isdigit(format[i]))
		i++;
	if (is_specifier(format[i]))
		return(format[i]);
	return ('\0');
}

int		get_length_ofspe(char *format)
{
	int	i;

	i = 0;
	while(format[i] == '%')
		i++;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
		i++;
	while (ft_isdigit(format[i]))
		i++;
	if (is_specifier(format[i]))
		return(i + 1);
	return ('\0');
}

int ft_printf(const char *format, ...)
{
	va_list args;
	char	*str;
	char	*debug;
	int		nbr_specifiers;
	int		j;

	nbr_specifiers = get_nbr_specifiers((char *)format);
	str = (char *)format;
	printf("%d\n", nbr_specifiers);
	j = 0;
	if (nbr_specifiers)
	{
		va_start(args, format);
		while (nbr_specifiers--)
		{
			while(!(str[j] == '%' && percent_spe_q(str, j)))
			{
				j++;
				continue;
			}
			if (get_specifier(str, j) == 'c')
				va_arg(args, int); ///
			else if (get_specifier(str, j) == 's')
			{
				debug = va_arg(args, char *);
				j--;
				while (j-- >= 0)
				{
					write(1, str, 1);
					str++;
				}
				while (*debug)
				{
					write(1, debug, 1);
					debug++;
				}
				str = str + get_length_ofspe(str);
				while (*str)
				{
					write(1, str, 1);
					str++;
				}
			}
			// else if (get_specifier(str, j) == 'd')
			// 	va_arg(args, double);
			// else if (get_specifier(str, j) == 'i')
			// 	va_arg(args, int);
			// else if (get_specifier(str, j) == 'u')
			// 	va_arg(args, float); ///
			// else if (get_specifier(str, j) == 'x')
			// 	va_arg(args, int);
			// else if (get_specifier(str, j) == 'X')
			// 	va_arg(args, int);
			// else if (get_specifier(str, j) == '%')
			// 	va_arg(args, char *);
		}
		va_end(args);
	}
	return (0);
}

int main(void)
{
	// ft_printf("Hello World!");
	// ft_printf("Hello %!");
	// ft_printf("Hello %%!");
	// ft_printf("Hello %%%!");
	// ft_printf("%%%%");
	// ft_printf("%%%%%%");
	// ft_printf("%%%%%%%");
	// ft_printf("%%%%%%%%");
	// ft_printf("%%%%%%%%%");
	// ft_printf("%%%%%%%%%%");
	// ft_printf("%%%%%%%%%%c");
	// ft_printf("%%%%%%%%%%d");
	// ft_printf("%%%%%%%%%%%");

	ft_printf("Hello %s!\n", "42");

	return (0);
}
