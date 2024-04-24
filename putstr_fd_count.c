/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:36:54 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/24 15:02:02 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_fd_count(char *s, int fd, int count)
{
	int	i;

	if (!s)
	{
		write(fd, "(null)", 6);
		count += 6;
		return (count);
	}
	i = 0;
	while (s[i] != '\0')
	{
		count = putchar_fd_count(s[i], fd, count);
		i++;
	}
	return (count);
}
