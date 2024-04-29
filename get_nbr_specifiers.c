/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:10:50 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/29 10:10:54 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
