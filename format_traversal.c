/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_traversal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:42:37 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/26 12:51:41 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_traversal(char *str, va_list args)
{
	int		j;
	int		count;

	j = 0;
	count = 0;
	if (!str || !args)
		return (0);
	while (str[j])
	{
		if (percent_spe_q(str, j) == 5)
		{
			j++;
			continue;
		}
		if (!(str[j] == '%' && percent_spe_q(str, j)))
			count = putchar_fd_count(str[j], 1, count);
		else
		{
			count = specifier_switch(get_specifier(str, j), args, count);
			j += get_length_ofspe(&str[j]);
			continue ;
		}
		j++;
	}
	return (count);
}
