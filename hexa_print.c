/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:00:40 by mgrandia          #+#    #+#             */
/*   Updated: 2025/03/15 11:16:40 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_letter_hexa(int value, char type)
{
	char	let;

	if (value == 10)
		let = 'A';
	else if (value == 11)
		let = 'B';
	else if (value == 12)
		let = 'C';
	else if (value == 13)
		let = 'D';
	else if (value == 14)
		let = 'E';
	else if (value == 15)
		let = 'F';
	if (type == 'x')
		return (ft_tolower(let));
	else if (type == 'X')
		return (let);
	else
		return (0);
}

int	ft_print_hexadecimal(unsigned int value, char type)
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
			str[i] = ft_letter_hexa(r, type);
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
