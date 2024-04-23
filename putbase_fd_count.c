/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase_fd_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:41:51 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 12:59:13 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putbase_fd_count(int nbr, int fd, char *base_to, int count)
{
	char	*s;

	s = convert_base(nbr, base_to);
	count = putstrrev_fd_count(s, fd, count);
	free(s);
	return (count);
}
