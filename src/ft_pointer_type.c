/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:59:43 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/29 23:48:53 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_spaces_hex(char *hex, int len)
{
	ft_putstr_free(ft_get_spaces_str(len));
	ft_putstr_fd("0x", 1);
	ft_putstr_free(hex);
}

static void	print_zeros_hex(char *hex, int len)
{
	ft_putstr_fd("0x", 1);
	ft_putstr_free(ft_get_zeros_str(len));
	ft_putstr_free(hex);
}

static void	print_hex_spaces(char *hex, int len)
{
	ft_putstr_fd("0x", 1);
	ft_putstr_free(hex);
	ft_putstr_free(ft_get_spaces_str(len));
}

int			print_pointer(char *hex, t_flags *flags)
{
	int		len;

	len = ft_strlen(hex);
	if (flags->dot && flags->precision == 0 && !ft_strncmp(hex, "0", len))
		hex = ft_empty_str(hex, &len);
	if (len < flags->precision)
		hex = ft_add_zeros(hex, flags->precision, &len);
	if (len + 2 >= flags->width)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_free(hex);
		return (len + 2);
	}
	if (flags->minus)
	{
		print_hex_spaces(hex, flags->width - len - 2);
		return (flags->width);
	}
	if (flags->zero && !flags->dot)
	{
		print_zeros_hex(hex, flags->width - len - 2);
		return (flags->width);
	}
	print_spaces_hex(hex, flags->width - len - 2);
	return (flags->width);
}

int			ft_pointer_type(va_list arg, t_flags *flags)
{
	unsigned long	ptr;
	int				counter;

	if (!(ptr = va_arg(arg, unsigned long)))
		counter = print_pointer(ft_strdup("0"), flags);
	else
		counter = print_pointer(ft_tohex(ptr, 'x'), flags);
	return (counter);
}
