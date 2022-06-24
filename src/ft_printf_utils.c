/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:53:12 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/30 22:46:48 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_free(char *s)
{
	int	length;

	length = write(1, s, ft_strlen(s));
	free(s);
	return (length);
}

char	*ft_empty_str(char *str, int *len)
{
	*len = 0;
	free(str);
	return (ft_strdup(""));
}

char	*ft_get_spaces_str(int size)
{
	char	*spaces;

	spaces = (char *)malloc(sizeof(char) * (size + 1));
	if (!spaces)
		return (0);
	spaces[size--] = '\0';
	while (size >= 0)
		spaces[size--] = 32;
	return (spaces);
}

char	*ft_get_zeros_str(int len)
{
	char	*zeros;

	zeros = (char *)malloc(sizeof(char) * (len + 1));
	if (!zeros)
		return (0);
	zeros[len--] = '\0';
	while (len >= 0)
		zeros[len--] = '0';
	return (zeros);
}

char	*ft_add_zeros(char *str, int total_len, int *nbr_len)
{
	char	*res;
	int		i;
	int		zeros_len;

	i = 0;
	if (*str == '-')
	{
		total_len += 1;
		i = 1;
		str++;
	}
	res = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	res[total_len] = '\0';
	if (i)
		res[0] = '-';
	zeros_len = total_len - *nbr_len;
	while (zeros_len--)
		res[i++] = '0';
	while (*str)
		res[i++] = *str++;
	free(str - *nbr_len);
	*nbr_len = total_len;
	return (res);
}
