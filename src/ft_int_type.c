/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:57:04 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/31 16:47:23 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_zeros_di(char *nbr, int len_zeros)
{
	int minus;

	minus = 0;
	if (*nbr == '-')
	{
		write(1, "-", 1);
		minus = 1;
	}
	ft_putstr_free(ft_get_zeros_str(len_zeros));
	ft_putstr_fd(nbr + minus, 1);
	free(nbr);
}

static void	print_di_spaces(char *nbr, int len_spaces)
{
	ft_putstr_free(nbr);
	ft_putstr_free(ft_get_spaces_str(len_spaces));
}

static void	print_spaces_di(char *nbr, int len_spaces)
{
	ft_putstr_free(ft_get_spaces_str(len_spaces));
	ft_putstr_free(nbr);
}

int			ft_int_type(char *nbr, t_flags *flags)
{
	int	len;

	len = ft_strlen(nbr);
	if (flags->dot && flags->precision == 0 && !ft_strncmp(nbr, "0", len))
		nbr = ft_empty_str(nbr, &len);
	if (len <= flags->precision)
		nbr = ft_add_zeros(nbr, flags->precision, &len);
	if (len >= flags->width)
	{
		ft_putstr_free(nbr);
		return (len);
	}
	if (flags->minus)
	{
		print_di_spaces(nbr, flags->width - len);
		return (flags->width);
	}
	if (flags->zero && !flags->dot)
	{
		print_zeros_di(nbr, flags->width - len);
		return (flags->width);
	}
	print_spaces_di(nbr, flags->width - len);
	return (flags->width);
}
