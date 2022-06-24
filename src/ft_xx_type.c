/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 23:04:32 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/29 23:04:54 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_x_spaces(char *hex, int len_spaces)
{
	ft_putstr_free(hex);
	ft_putstr_free(ft_get_spaces_str(len_spaces));
}

static void	print_zeros_x(char *hex, int len_zeros)
{
	ft_putstr_free(ft_get_zeros_str(len_zeros));
	ft_putstr_free(hex);
}

static void	print_spaces_x(char *hex, int len_spaces)
{
	ft_putstr_free(ft_get_spaces_str(len_spaces));
	ft_putstr_free(hex);
}

int			ft_xx_type(char *hex, t_flags *flags)
{
	int		len;

	len = ft_strlen(hex);
	if (flags->dot && flags->precision == 0 && !ft_strncmp(hex, "0", len))
		hex = ft_empty_str(hex, &len);
	if (len < flags->precision)
		hex = ft_add_zeros(hex, flags->precision, &len);
	if (len >= flags->width)
	{
		ft_putstr_free(hex);
		return (len);
	}
	if (flags->minus)
	{
		print_x_spaces(hex, flags->width - len);
		return (flags->width);
	}
	if (flags->zero && !flags->dot)
	{
		print_zeros_x(hex, flags->width - len);
		return (flags->width);
	}
	print_spaces_x(hex, flags->width - len);
	return (flags->width);
}
