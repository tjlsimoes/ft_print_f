/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:38:45 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 15:51:08 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x'
		|| c == '%' || c == 'X' || c == 'p')
		return (1);
	return (0);
}
