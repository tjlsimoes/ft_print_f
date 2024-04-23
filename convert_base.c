/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:41:27 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 13:02:20 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_base(unsigned long long nbr, char *base_to)
{
	int		base;
	char	*output;
	int		i;

	base = ft_strlen(base_to);
	i = 0;
	output = (char *)malloc(out_length(nbr, base) + 1);
	if (!output)
		return (NULL);
	if (nbr == 0)
	{
		output[0] = base_to[0];
		i++;
	}
	while (nbr)
	{
		output[i] = base_to[nbr % base];
		nbr = nbr / base;
		i++;
	}
	output[i] = '\0';
	return (output);
}
