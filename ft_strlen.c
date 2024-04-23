/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:33:30 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 12:33:49 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\0')
	{
		count += 1;
		i += 1;
	}
	return (count);
}
