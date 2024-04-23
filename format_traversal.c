/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_traversal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:42:37 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 16:41:02 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_traversal(char *str, va_list args)
{
	int		j;
	int		count;
	char	c;

	j = 0;
	count = 0;
	if (!str || !args)
		return (0);
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
			continue ;
		}
		j++;
	}
	return (count);
}
