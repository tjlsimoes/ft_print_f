/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:43 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/05/21 16:02:44 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		j;

	if (!format)
		return (-1);
	va_start(args, format);
	j = format_traversal((char *)format, args);
	va_end(args);
	return (j);
}

// #include "ft_printf.h"
// #include <stdio.h>

// int main(void)
// {
// 	ft_printf("Hello World!");
// 	ft_printf("Hello %%!");
// 	ft_printf("%%%%");
// 	ft_printf("%%%%%%");
// 	ft_printf("%%%%%%%%");
// 	ft_printf("%%%%%%%%%%");
// 	ft_printf("%%%%%%%%%%c");
// 	ft_printf("%%%%%%%%%%d");

// 	ft_printf("Hello %s!\n", "42");
// 	ft_printf("Hello %s! %s\n", "42", "Bye!");
// 	ft_printf("Hello %s! This is char %c!\n", "42", 'c');
// 	ft_printf("Hello %s! %c! %d!\n", "42", 'c', 42);
// 	ft_printf("Hello %s!  %c! %d!\n", "42", 'c', -42);
// 	ft_printf("Int: %d!\n", INT_MIN);
// 	ft_printf("Hello %s! Int: %d! Percent sign: %%\n", "42", -42);
// 	ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 42);
// 	ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 32); // 20
// 	ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 0); // 2a
// 	ft_printf("Hello %s! Hex uppercase: %X!\n", "42", 42);
// 	ft_printf("%s! %d! Unsigned int: %u\n", "42", -42, -42); // 4294967254
// 	int i = 4;
// 	printf("%p %p %p %p\n", "hello", &i, NULL, (void *)0);
// 	ft_printf("%p %p %p %p\n", "hello", &i, NULL, (void *)0);

// 	printf("%d\n", ft_printf("Hello %s! Hex uppercase: %X!\n", "42", 42));
// 	printf("%d\n", printf("Hello %s! Hex uppercase: %X!\n", "42", 42));

// 	printf("%d\n", ft_printf("Hello World!\n"));
// 	printf("%d\n", printf("Hello World!\n"));

// 	printf("%d\n", ft_printf("%%%%%%\n"));
// 	printf("%d\n", ft_printf("%%%%%%\n"));

// 	printf("%d\n", ft_printf("Hello %s! %s\n", "42", "Bye!"));
// 	printf("%d\n", printf("Hello %s! %s\n", "42", "Bye!"));

// 	printf("%d\n", ft_printf("Hello %s! Hex lowercase: %x!\n", "42", 32));
// 	printf("%d\n", printf("Hello %s! Hex lowercase: %x!\n", "42", 32));

// 	printf("%d\n", ft_printf("Hello %s! %c! %d!\n", "42", 'c', -42));
// 	printf("%d\n", printf("Hello %s! %c! %d!\n", "42", 'c', -42));

// 	printf("%d\n", ft_printf("Hello %s! %d! %u\n", "42", -42, -42));
// 	printf("%d\n", printf("Hello %s! Int: %d! %u\n", "42", -42, -42));

// 	printf("%d\n", ft_printf("%p %p %p %p\n", NULL, NULL, NULL, NULL));
// 	printf("%d\n", printf("%p %p %p %p\n", NULL, NULL, NULL, NULL));

// 	long long j;
// 	// j = 0;
// 	// j = 1;
// 	// j = LONG_MIN;
// 	// j = LONG_MAX;
// 	// j = ULONG_MAX;
// 	// j = -ULONG_MAX;
// 	// j = -1;
// 	// j = ULLONG_MAX;
// 	// j = -ULLONG_MAX;
// 	j = LLONG_MIN;

// 	printf("%p\n", &j);
// 	ft_printf("%p\n", &j);

// 	printf("%p\n", (void *)j);
// 	ft_printf("%p\n", (void *)j);

// 	ft_printf("Hello!\n");

// 	ft_printf("%c small string", 'a');
// 	return (0);
// }
