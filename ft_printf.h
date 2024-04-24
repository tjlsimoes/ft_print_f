/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:53:53 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/24 15:31:18 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

size_t		ft_strlen(const char *str);
int			ft_isdigit(int c);
int			get_nbr_digits(int n);
int			power(int n, int power);
int			putnbr_fd_count(int n, int fd, int count);
int			putpointer_fd_count(unsigned long nbr, int fd, int count);
int			get_unint_digits(unsigned long n);
int			putunint_fd_count(unsigned int n, int fd, int count);
int			putchar_fd_count(char c, int fd, int count);
int			putstr_fd_count(char *s, int fd, int count);
int			putstrrev_fd_count(char *s, int fd, int count);
int			is_specifier(char c);
int			percent_spe_q(char *format, int i);
char		get_specifier(char *format, int i);
int			get_length_ofspe(char *format);
int			out_length(int nbr, int base);
char		*convert_base(unsigned long nbr, char *base_to);
int			putbase_fd_count(unsigned long nbr, int fd, char *base_to, int count);
int			specifier_switch(char c, va_list args, int count);
int			format_traversal(char *str, va_list args);
int			ft_printf(const char *format, ...);
#endif