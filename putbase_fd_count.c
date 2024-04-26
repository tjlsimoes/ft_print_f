/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase_fd_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:41:51 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/26 10:38:44 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putbase_fd_count(unsigned long nbr, int fd, char *base, int count)
{

	if (nbr >= 16)
	{
		count = putbase_fd_count((nbr / 16), 1, base, count);
		count = putbase_fd_count((nbr % 16), 1, base, count);
	}
	else
	{
		write(fd, &base[nbr], 1);
		count++;
	}
	return (count);
}

// char	*convert_base(unsigned long nbr, char *base_to)
// {
// 	int		base;
// 	char	*output;
// 	int		i;

// 	base = ft_strlen(base_to);
// 	i = 0;
// 	output = (char *)malloc(out_length(nbr, base) + 1);
// 	if (!output)
// 		return (NULL);
// 	if (nbr == 0)
// 	{
// 		output[0] = base_to[0];
// 		i++;
// 	}
// 	while (nbr)
// 	{
// 		output[i] = base_to[nbr % base];
// 		nbr = nbr / base;
// 		i++;
// 	}
// 	output[i] = '\0';
// 	return (output);
// }

// int	putstrrev_fd_count(char *s, int fd, int count)
// {
// 	int	i;

// 	i = ft_strlen(s) - 1;
// 	while (i >= 0)
// 	{
// 		count = putchar_fd_count(s[i], fd, count);
// 		i--;
// 	}
// 	return (count);
// }

// int	putbase_fd_count(unsigned long nbr, int fd, char *base_to, int count)
// {
// 	char	*s;

// 	s = convert_base(nbr, base_to);
// 	count = putstrrev_fd_count(s, fd, count);
// 	free(s);
// 	return (count);
// }