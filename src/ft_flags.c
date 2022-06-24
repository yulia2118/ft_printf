/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:54:15 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/31 00:18:56 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*get_digits(const char *format, int *dest)
{
	*dest = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (--format);
}

const char	*get_precision(const char *format, va_list arg, t_flags *flags)
{
	if (*(++format) == '*')
	{
		if ((flags->precision = va_arg(arg, int)) >= 0)
			flags->dot = 1;
	}
	else
	{
		format = get_digits(format, &flags->precision);
		if (flags->precision >= 0)
			flags->dot = 1;
	}
	return (format);
}

const char	*ft_parse_flag(const char *format, va_list arg, t_flags *flags)
{
	while (!ft_strchr(TYPE, *format))
	{
		if (*format == '-')
			flags->minus = 1;
		else if (*format == '0')
			flags->zero = 1;
		else if (ft_isdigit(*format) || *format == '*')
		{
			if (*format == '*')
			{
				if ((flags->width = va_arg(arg, int)) < 0)
				{
					flags->width *= -1;
					flags->minus = 1;
				}
			}
			else
				format = get_digits(format, &flags->width);
		}
		else if (*format == '.')
			format = get_precision(format, arg, flags);
		format++;
	}
	return (format);
}

t_flags		*ft_new_t_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (flags)
	{
		flags->minus = 0;
		flags->zero = 0;
		flags->width = 0;
		flags->dot = 0;
		flags->precision = 0;
		return (flags);
	}
	else
		return (NULL);
}

void		ft_clean_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = 0;
}
