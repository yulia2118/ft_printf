/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 23:02:36 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/30 22:43:52 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstrlen(char *str, size_t len)
{
	if (!str)
		return (0);
	return (write(1, str, len));
}

static void	print_spaces_s(char *str, int len, char *spaces)
{
	if (spaces)
		ft_putstr_free(spaces);
	ft_putstrlen(str, len);
}

static void	print_s_spaces(char *str, int len, char *spaces)
{
	ft_putstrlen(str, len);
	if (spaces)
		ft_putstr_free(spaces);
}

int			print_string(char *str, t_flags *flags)
{
	int		len;
	char	*spaces;
	int		counter;

	spaces = NULL;
	len = ft_strlen(str);
	if (flags->dot && flags->precision < len)
		len = flags->precision;
	counter = len;
	if (len < flags->width)
	{
		counter = flags->width;
		spaces = ft_get_spaces_str(flags->width - len);
	}
	if (flags->minus)
		print_s_spaces(str, len, spaces);
	else
		print_spaces_s(str, len, spaces);
	return (counter);
}

int			ft_string_type(va_list arg, t_flags *flags)
{
	char	*str;
	int		counter;

	if (!(str = va_arg(arg, char *)))
		str = "(null)";
	counter = print_string(str, flags);
	return (counter);
}
