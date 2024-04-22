/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:43 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/22 15:41:32 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

// #include "libft/libft.h"

// int percent_spe_q(char *format, int i)
// {
// 	if (format[i] == '%' && format[i - 1] != '%' &&
// 		format[i + 1] != '%')
// 		return (1);
// 	return (0);
// }

//////// Changed!

size_t	ft_strlen(const char *str)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\0')
	{
		count += 1;
		i += 1;
	}
	return (count);
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

static int	get_nbr_digits(int n)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	power(int n, int power)
{
	int		result;

	result = 1;
	if (power == 0)
		return (1);
	while (power)
	{
		result *= n;
		power--;
	}
	return (result);
}

//////////////////// Changed!!!

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	int			nbr_digits;
	long	n_ll;

	n_ll = (long)n;

	if (n_ll < 0)
	{
		n_ll *= -1;
		write(fd, "-", 1);
	}
	nbr_digits = get_nbr_digits(n_ll);
	while (nbr_digits > 0)
	{
		c = (n_ll / power(10, nbr_digits - 1)) + 48;
		write(fd, &c, 1);
		n_ll = n_ll % power(10, nbr_digits - 1);
		nbr_digits--;
	}
}

// void	ft_putunint_fd(unsigned int n, int fd)
// {
// 	char			c;
// 	int				nbr_digits;
// 	n = n + (LONG_MAX ) % LONG_MAX;
// 	nbr_digits = get_nbr_digits(n);
// 	while (nbr_digits > 0)
// 	{
// 		c = (n / power(10, nbr_digits - 1)) + 48;
// 		write(fd, &c, 1);
// 		n = n % power(10, nbr_digits - 1);
// 		nbr_digits--;
// 	}
// }
// https://www.oreilly.com/library/view/c-in-a/0596006977/ch04.html

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putstrrev_fd(char *s, int fd)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		ft_putchar_fd(s[i], fd);
		i--;
	}
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x'
		|| c == '%' || c == 'X')
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
int	out_length(int nbr, int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

char	*convert_base(int nbr, char *base_to)
{
	int		base;
	char	*output;
	int		i;

	base = ft_strlen(base_to);
	i = 0;
	output = (char *)malloc(out_length(nbr, base) + 1);
	if (!output)
		return (NULL);
	if (nbr == 0)
	{
		output[0] = base_to[0];
		i++; 
	}
	while (nbr)
	{
		output[i] = base_to[nbr % base];
		nbr = nbr / base;
		i++;
	}
	output[i] = '\0';
	return (output);
}

void	ft_putbase_fd(int nbr, int fd, char *base_to)
{
	char	*s;
	
	s = convert_base(nbr, base_to);
	ft_putstrrev_fd(s, fd);
	free(s);
}

void format_traversal(char *str, va_list args)
{
	int		j;
	char	c;

	j = 0;
	while (str[j])
	{
		if (!(str[j] == '%' && percent_spe_q(str, j)))
		 	write(1, &str[j], 1);
		else
		{
			c = get_specifier(str, j);
			if (c == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (c == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (c == 'd' || c == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (c == 'u')
				ft_putnbr_fd(va_arg(args, unsigned int), 1);
			else if (c == '%')
				ft_putstr_fd("%", 1);
			else if (c == 'x')
				ft_putbase_fd(va_arg(args, int), 1, "0123456789abcdef");
			else if (c == 'X')
				ft_putbase_fd(va_arg(args, int), 1, "0123456789ABCDEF");
			j += get_length_ofspe(&str[j]);
			continue;
		}
		j++;
	}
}

int ft_printf(const char *format, ...)
{
	va_list args;
	// char	*str;
	// char	*debug;
	int		nbr_specifiers;
	// int		j;

	nbr_specifiers = get_nbr_specifiers((char *)format);
	// str = (char *)format;
	printf("%d\n", nbr_specifiers);
	// j = 0;

	va_start(args, format);
	format_traversal((char *)format, args);
	va_end(args);
	// if (nbr_specifiers)
	// {
	// 	va_start(args, format);
	// 	while (nbr_specifiers--)
	// 	{
	// 		while(!(str[j] == '%' && percent_spe_q(str, j)))
	// 		{
	// 			j++;
	// 			continue;
	// 		}
	// 		if (get_specifier(str, j) == 'c')
	// 			va_arg(args, int); ///
	// 		else if (get_specifier(str, j) == 's')
	// 		{
	// 			debug = va_arg(args, char *);
	// 			j--;
	// 			while (j-- >= 0)
	// 			{
	// 				write(1, str, 1);
	// 				str++;
	// 			}
	// 			while (*debug)
	// 			{
	// 				write(1, debug, 1);
	// 				debug++;
	// 			}
	// 			str = str + get_length_ofspe(str);
	// 			while (*str)
	// 			{
	// 				write(1, str, 1);
	// 				str++;
	// 			}
	// 		}
	// 		// else if (get_specifier(str, j) == 'd')
	// 		// 	va_arg(args, double);
	// 		// else if (get_specifier(str, j) == 'i')
	// 		// 	va_arg(args, int);
	// 		// else if (get_specifier(str, j) == 'u')
	// 		// 	va_arg(args, float); ///
	// 		// else if (get_specifier(str, j) == 'x')
	// 		// 	va_arg(args, int);
	// 		// else if (get_specifier(str, j) == 'X')
	// 		// 	va_arg(args, int);
	// 		// else if (get_specifier(str, j) == '%')
	// 		// 	va_arg(args, char *);
	// 	}
	// 	va_end(args);
	// }
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

	// ft_printf("Hello %s!\n", "42");
	// ft_printf("Hello %s! %s\n", "42", "Bye!");
	// ft_printf("Hello %s! This is char %c!\n", "42", 'c');
	// ft_printf("Hello %s! This is char %c! And this is number %d!\n", "42", 'c', 42);
	// ft_printf("Hello %s! This is char %c! And this is number %d!\n", "42", 'c', -42);
	// ft_printf("Int: %d!\n", INT_MIN);
	// ft_printf("Hello %s! Int: %d! Percent sign: %%\n", "42", -42);
	//  ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 42);
	//  ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 32); // 20
	//  ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 0); // 2a
	// ft_printf("Hello %s! Hex uppercase: %X!\n", "42", 42); // 2A

	// Not working as it should!
	// ft_printf("Hello %s! Int: %d! Unsigned int: %u\n", "42", -42, -42);
	return (0);
}
