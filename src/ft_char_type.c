/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:56:19 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/29 22:56:38 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_type(unsigned char c, t_flags *flags)
{
	int		counter;
	char	*spaces;

	counter = 1;
	spaces = NULL;
	if (flags->width > 1)
	{
		counter = flags->width;
		spaces = ft_get_spaces_str(flags->width - 1);
	}
	if (flags->minus)
	{
		write(1, &c, 1);
		if (spaces)
			ft_putstr_free(spaces);
	}
	else
	{
		if (spaces)
			ft_putstr_free(spaces);
		write(1, &c, 1);
	}
	return (counter);
}
