/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:43 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 10:28:31 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

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

int	putnbr_fd_count(int n, int fd, int count)
{
	char		c;
	int			nbr_digits;
	long		n_ll;

	n_ll = (long)n;
	if (n_ll < 0)
	{
		n_ll *= -1;
		count++;
		write(fd, "-", 1);
	}
	nbr_digits = get_nbr_digits(n_ll);
	while (nbr_digits > 0)
	{
		c = (n_ll / power(10, nbr_digits - 1)) + 48;
		write(fd, &c, 1);
		count++;
		n_ll = n_ll % power(10, nbr_digits - 1);
		nbr_digits--;
	}
	return (count);
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

int	putchar_fd_count(char c, int fd, int count)
{
	write(fd, &c, 1);
	count++;
	return (count);
}

int	putstr_fd_count(char *s, int fd, int count)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		count = putchar_fd_count(s[i], fd, count);
		i++;
	}
	return (count);
}

int	putstrrev_fd_count(char *s, int fd, int count)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		count = putchar_fd_count(s[i], fd, count);
		i--;
	}
	return (count);
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

int	putbase_fd_count(int nbr, int fd, char *base_to, int count)
{
	char	*s;
	
	s = convert_base(nbr, base_to);
	count = putstrrev_fd_count(s, fd, count);
	free(s);
	return (count);
}

int	specifier_switch(char c, va_list args, int count)
{
	if (c == 'c')
		count = putchar_fd_count(va_arg(args, int), 1, count);
	else if (c == 's')
		count = putstr_fd_count(va_arg(args, char *), 1, count);
	else if (c == 'd' || c == 'i')
		count = putnbr_fd_count(va_arg(args, int), 1, count);
	else if (c == 'u')
		count = putnbr_fd_count(va_arg(args, unsigned int), 1, count);
	else if (c == '%')
		count = putstr_fd_count("%", 1, count);
	else if (c == 'x')
		count = putbase_fd_count(va_arg(args, int), 1, "0123456789abcdef", count);
	else if (c == 'X')
		count = putbase_fd_count(va_arg(args, int), 1, "0123456789ABCDEF", count);
	return (count);
}

int format_traversal(char *str, va_list args)
{
	int		j;
	int		count;
	char	c;

	j = 0;
	count = 0;
	while (str[j])
	{
		if (!(str[j] == '%' && percent_spe_q(str, j)))
		{
			count++;
			write(1, &str[j], 1);
		}
		else
		{
			c = get_specifier(str, j);
			count = specifier_switch(c, args, count);
			j += get_length_ofspe(&str[j]);
			continue;
		}
		j++;
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int		j;

	va_start(args, format);
	j = format_traversal((char *)format, args);
	va_end(args);
	// if (nbr_specifiers)
	// {
	// 	va_start(args, format);
	// 	va_end(args);
	// }
	return (j);
}

#include <stdio.h>
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
	// 	ft_printf("Hello %s! Hex uppercase: %X!\n", "42", 42);

	
	// printf("%d\n", ft_printf("Hello %s! Hex uppercase: %X!\n", "42", 42));
	// printf("%d\n", printf("Hello %s! Hex uppercase: %X!\n", "42", 42));

	// printf("%d\n", ft_printf("Hello World!\n"));
	// printf("%d\n", printf("Hello World!\n"));

	// printf("%d\n", ft_printf("%%%%%%\n"));
	// printf("%d\n", ft_printf("%%%%%%\n"));

	// printf("%d\n", ft_printf("Hello %s! %s\n", "42", "Bye!"));
	// printf("%d\n", printf("Hello %s! %s\n", "42", "Bye!"));
	
	// printf("%d\n", ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 32));
	// printf("%d\n", printf("Hello %s! Hex lowercase: %x!\n", "42", 32));

	// printf("%d\n", ft_printf("Hello %s! %c! %d!\n", "42", 'c', -42));
	// printf("%d\n", printf("Hello %s! %c! %d!\n", "42", 'c', -42));

	// Not working as it should!
	// ft_printf("Hello %s! Int: %d! Unsigned int: %u\n", "42", -42, -42);
	return (0);
}
