/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:55:59 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/30 22:49:26 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct	s_flags
{
	int	minus;
	int zero;
	int	width;
	int	dot;
	int precision;
}				t_flags;

int				ft_printf(const char *format, ...);
t_flags			*ft_new_t_flags(void);
const char		*ft_parse_flag(const char *format, va_list arg, t_flags *flags);
void			ft_clean_flags(t_flags *flags);
char			*ft_get_spaces_str(int size);
char			*ft_add_zeros(char *str, int total_len, int *hex_len);
char			*ft_get_zeros_str(int len);
char			*ft_empty_str(char *str, int *len);
int				ft_putstr_free(char *s);
int				ft_percent_type(t_flags *flags);
int				ft_char_type(unsigned char c, t_flags *flags);
int				ft_string_type(va_list arg, t_flags *flags);
int				ft_pointer_type(va_list arg, t_flags *flags);
int				ft_int_type(char *nbr, t_flags *flags);
int				ft_unint_type(char *nbr, t_flags *flags);
int				ft_xx_type(char *hex, t_flags *flags);

#endif
