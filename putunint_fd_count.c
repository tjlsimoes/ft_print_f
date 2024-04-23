/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunint_fd_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:54 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 12:36:11 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putunint_fd_count(unsigned int n, int fd, int count)
{
	char		c;
	int			nbr_digits;
	long		n_ll;

	n_ll = (unsigned long)n;
	nbr_digits = get_unint_digits(n_ll);
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
