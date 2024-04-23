/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstrrev_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:37:37 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 12:38:26 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
