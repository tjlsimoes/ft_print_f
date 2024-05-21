/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_traversal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:42:37 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/05/21 15:54:43 by tjorge-l         ###   ########.fr       */
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
		if (str[j] == '%' && is_specifier(str[j + 1]))
		{
			count = specifier_switch(str[j + 1], args, count);
			j += 2;
			continue ;
		}
		else
			count = putchar_fd_count(str[j], 1, count);
		j++;
	}
	return (count);
}
