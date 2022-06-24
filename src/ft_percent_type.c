/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:58:02 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/31 00:04:51 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_type(t_flags *flags)
{
	if (flags->width < 2)
		return (write(1, "%", 1));
	if (flags->minus)
	{
		write(1, "%", 1);
		ft_putstr_free(ft_get_spaces_str(flags->width - 1));
		return (flags->width);
	}
	if (flags->zero)
	{
		ft_putstr_free(ft_get_zeros_str(flags->width - 1));
		write(1, "%", 1);
		return (flags->width);
	}
	ft_putstr_free(ft_get_spaces_str(flags->width - 1));
	write(1, "%", 1);
	return (flags->width);
}
