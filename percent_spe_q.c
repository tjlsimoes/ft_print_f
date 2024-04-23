/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_spe_q.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:39:05 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 13:00:12 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percent_spe_q(char *format, int i)
{
	int	j;

	j = 0;
	while (format[i] == '%')
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
		return (1);
	return (0);
}
