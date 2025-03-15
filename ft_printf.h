/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:29:17 by mgrandia          #+#    #+#             */
/*   Updated: 2025/03/15 10:12:29 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stddef.h> //per el size_t
# include <stdio.h>//FIXME
# include <unistd.h>

int				ft_select_format(va_list args, const char type);
int				ft_printf(char const *str, ...);
char			*ft_flip_string(char *str);
int				ft_intlen(int i);
int				ft_print_char(char c);
int				ft_print_string(char *s);
int				ft_print_int(int i);
unsigned int	ft_print_unsigned_int(unsigned int i);
int				ft_print_signed_int(int i);
char			ft_letter_hexa(int value, char type);
int				ft_print_hexadecimal(unsigned int value, char type);
int				ft_print_pointer(char *ptr);
int				ft_print_hex_ptr(unsigned long value, char type);
unsigned int	ft_lenuint(unsigned int n);
char			*ft_uitoa(unsigned int n);
#endif
