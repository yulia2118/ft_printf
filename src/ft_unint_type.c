/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unint_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 23:03:40 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/29 23:04:05 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_u_spaces(char *nbr, int len_spaces)
{
	ft_putstr_free(nbr);
	ft_putstr_free(ft_get_spaces_str(len_spaces));
}

static void	print_zeros_u(char *nbr, int len_zeros)
{
	ft_putstr_free(ft_get_zeros_str(len_zeros));
	ft_putstr_free(nbr);
}

static void	print_spaces_u(char *nbr, int len_spaces)
{
	ft_putstr_free(ft_get_spaces_str(len_spaces));
	ft_putstr_free(nbr);
}

int			ft_unint_type(char *nbr, t_flags *flags)
{
	int		len;

	len = ft_strlen(nbr);
	if (flags->dot && flags->precision == 0 && !ft_strncmp(nbr, "0", len))
		nbr = ft_empty_str(nbr, &len);
	if (len < flags->precision)
		nbr = ft_add_zeros(nbr, flags->precision, &len);
	if (len >= flags->width)
	{
		ft_putstr_free(nbr);
		return (len);
	}
	if (flags->minus)
	{
		print_u_spaces(nbr, flags->width - len);
		return (flags->width);
	}
	if (flags->zero && !flags->dot)
	{
		print_zeros_u(nbr, flags->width - len);
		return (flags->width);
	}
	print_spaces_u(nbr, flags->width - len);
	return (flags->width);
}
