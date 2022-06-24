/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:52:06 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/29 23:53:55 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_type(const char *format, va_list arg, t_flags *flags)
{
	int				counter;

	counter = 0;
	if (*format == '%')
		counter += ft_percent_type(flags);
	else if (*format == 'c')
		counter += ft_char_type(va_arg(arg, int), flags);
	else if (*format == 's')
		counter += ft_string_type(arg, flags);
	else if (*format == 'p')
		counter += ft_pointer_type(arg, flags);
	else if (*format == 'd' || *format == 'i')
		counter += ft_int_type(ft_itoa(va_arg(arg, int)), flags);
	else if (*format == 'u')
		counter += ft_unint_type(ft_utoa(va_arg(arg, unsigned int)), flags);
	else if (*format == 'x')
		counter += ft_xx_type(ft_tohex(va_arg(arg, unsigned int), 'x'), flags);
	else if (*format == 'X')
		counter += ft_xx_type(ft_tohex(va_arg(arg, unsigned int), 'X'), flags);
	return (counter);
}

static int	process_format(const char *format, va_list arg)
{
	int		counter;
	t_flags	*flags;

	counter = 0;
	flags = ft_new_t_flags();
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
			{
				free(flags);
				flags = NULL;
				return (0);
			}
			format = ft_parse_flag(++format, arg, flags);
			counter += process_type(format++, arg, flags);
			ft_clean_flags(flags);
		}
		else
			counter += write(1, format++, 1);
	}
	free(flags);
	flags = NULL;
	return (counter);
}

int			ft_printf(const char *format, ...)
{
	int		length;
	va_list	arg;

	va_start(arg, format);
	length = process_format(format, arg);
	va_end(arg);
	return (length);
}
