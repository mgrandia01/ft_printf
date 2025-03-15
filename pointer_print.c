/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:00:40 by mgrandia          #+#    #+#             */
/*   Updated: 2025/03/15 11:43:25 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(char *ptr)
{
	int	size;

	if (ptr == NULL)
	{
		ft_print_string("(nil)");
		return (5);
	}
	size = 0;
	size += ft_print_string("0x");
	size += ft_print_hex_ptr((unsigned long)ptr, 'x');
	return (size);
}

int	ft_print_hex_ptr(unsigned long value, char type)
{
	char				*str;
	int					i;
	unsigned int		r;

	str = malloc(2 * sizeof(unsigned long) + 1);
	i = 0;
	r = 0;
	if (!str)
		return (0);
	if (value == 0)
	{
		i = ft_print_char('0');
		free (str);
		return (1);
	}
	while (value > 0)
	{
		r = value % 16;
		if (r > 9)
		{
			r = ft_letter_hexa(r, type);
			str[i] = r;
		}
		else
			str[i] = r + '0';
		value = value / 16;
		i ++;
	}
	str[i] = '\0';
	i = ft_print_string(ft_flip_string(str));
	free (str);
	return (i);
}
