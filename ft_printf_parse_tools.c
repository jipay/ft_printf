/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:03:03 by jdidier           #+#    #+#             */
/*   Updated: 2020/10/17 19:08:23 by jdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_init_result_c(t_fmt *fmt)
{
	char *result;

	if (!(result = malloc(sizeof(*result) * ((fmt->min_w)))))
		return (NULL);
	result[fmt->min_w - 1] = '\0';
	if (fmt->zero && fmt->conv == '%' && !(fmt->minus))
		ft_memset(result, '0', (fmt->min_w - 1));
	else
		ft_memset(result, ' ', (fmt->min_w - 1));
	return (result);
}

char	*ft_init_result_s(int width)
{
	char	*result;

	if (!(result = malloc(sizeof(*result) * (width + 1))))
		return (NULL);
	result[width] = '\0';
	result = ft_memset(result, ' ', width);
	return (result);
}

char	*ft_init_result_d(t_fmt *fmt, int width, int i)
{
	char	*result;

	if (!(result = malloc(sizeof(*result) * (width + 1))))
		return (NULL);
	result[width] = '\0';
	ft_memset(result, ' ', width);
	if (fmt->zero && !(fmt->point) && !(fmt->minus))
	{
		ft_memset(result, '0', width);
		if (i)
			result[0] = '-';
	}
	else if (!(fmt->minus))
	{
		ft_memset((result + (width - (fmt->prcsn + i))), '0', fmt->prcsn + i);
		if (i)
			result[(width - (fmt->prcsn + i))] = '-';
	}
	else
	{
		ft_memset(result, '0', fmt->prcsn + i);
		if (i)
			result[0] = '-';
	}
	return (result);
}

char	*ft_init_result_u(t_fmt *fmt, int width)
{
	char	*result;

	if (!(result = malloc(sizeof(*result) * (width + 1))))
		return (NULL);
	result[width] = '\0';
	ft_memset(result, ' ', width);
	if (fmt->zero && !(fmt->point) && !(fmt->minus))
		ft_memset(result, '0', width);
	else if (!(fmt->minus))
		ft_memset((result + (width - (fmt->prcsn))), '0', fmt->prcsn);
	else
		ft_memset(result, '0', fmt->prcsn);
	return (result);
}

char	*ft_init_result_p(t_fmt *fmt, int width)
{
	char	*result;

	if (!(result = malloc(sizeof(*result) * (width + 1))))
		return (NULL);
	result[width] = '\0';
	ft_memset(result, ' ', width);
	if (fmt->zero && !(fmt->point) && !(fmt->minus))
	{
		ft_memset(result, '0', width);
		result[1] = 'x';
	}
	else if (!(fmt->minus))
	{
		ft_memset((result + (width - (fmt->prcsn + 2))), '0', fmt->prcsn + 2);
		result[(width - (fmt->prcsn + 1))] = 'x';
	}
	else
	{
		ft_memset(result, '0', fmt->prcsn + 2);
		result[1] = 'x';
	}
	return (result);
}
