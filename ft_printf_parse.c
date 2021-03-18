/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:04:36 by jdidier           #+#    #+#             */
/*   Updated: 2020/10/17 20:50:12 by jdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_parse_c(t_fmt *fmt, int c)
{
	char	*result;

	if (fmt->min_w > 1)
	{
		if (!(result = ft_init_result_c(fmt)))
			return (0);
		if (fmt->minus)
		{
			ft_putchar_fd(c, 1);
			ft_putstr_fd(result, 1);
		}
		else
		{
			ft_putstr_fd(result, 1);
			ft_putchar_fd(c, 1);
		}
		fmt->ret = ft_strlen(result) + 1;
		free(result);
	}
	else
	{
		fmt->ret = 1;
		ft_putchar_fd(c, 1);
	}
	return (1);
}

int		ft_parse_s(t_fmt *fmt, va_list ad)
{
	char	*result;
	char	*arg;
	int		len;
	int		width;
	int		i;

	arg = va_arg(ad, char*);
	arg = (arg) ? ft_strdup(arg) : ft_strdup("(null)");
	len = ft_strlen(arg);
	len = (((fmt->point) && (fmt->prcsn < len) && fmt->prcsn >= 0) ? fmt->prcsn
	: len);
	width = ((fmt->min_w) > len) ? fmt->min_w : len;
	if (!(result = ft_init_result_s(width)))
		return (0);
	i = 0;
	while (i < len)
	{
		if (fmt->minus)
			result[i] = arg[i];
		else
			result[width - (len - i)] = arg[i];
		i++;
	}
	ft_display_result(result, arg, fmt);
	return (1);
}

int		ft_parse_d(t_fmt *fmt, int arg_d)
{
	char	*result;
	char	*arg;
	int		width;
	int		len;
	int		i;

	arg = (fmt->point && arg_d == 0) ? ft_strdup("") : ft_itoa(arg_d);
	i = (arg[0] == '-') ? 1 : 0;
	len = (arg[0] == '-') ? (ft_strlen(arg) - 1) : ft_strlen(arg);
	fmt->prcsn = ((fmt->point) && ((fmt->prcsn) > len)) ? fmt->prcsn : len;
	width = ((fmt->min_w) > (fmt->prcsn + i)) ? fmt->min_w : ((fmt->prcsn) + i);
	if (!(result = ft_init_result_d(fmt, width, i)))
		return (0);
	len += i;
	fmt->prcsn += i;
	while (i < len)
	{
		if (fmt->minus)
			result[i + ((fmt->prcsn) - len)] = arg[i];
		else
			result[width - (len - i)] = arg[i];
		i++;
	}
	ft_display_result(result, arg, fmt);
	return (1);
}

int		ft_parse_u(t_fmt *fmt, unsigned int arg_u)
{
	char	*result;
	char	*arg;
	int		width;
	int		len;
	int		i;

	arg = ft_init_arg_u(fmt, arg_u);
	len = (ft_strlen(arg));
	fmt->prcsn = ((fmt->point) && ((fmt->prcsn) > len)) ? fmt->prcsn : len;
	width = ((fmt->min_w) > (fmt->prcsn)) ? fmt->min_w : fmt->prcsn;
	if (!(result = ft_init_result_u(fmt, width)))
		return (0);
	i = 0;
	while (i < len)
	{
		if (fmt->minus)
			result[i + ((fmt->prcsn) - len)] = arg[i];
		else
			result[width - (len - i)] = arg[i];
		i++;
	}
	ft_display_result(result, arg, fmt);
	return (1);
}

int		ft_parse_p(t_fmt *fmt, unsigned long int arg_p)
{
	char	*result;
	char	*arg;
	int		width;
	int		len;
	int		i;

	arg = (arg_p == 0 && fmt->point) ? ft_strdup("")
	: ft_itoa_base(arg_p, "0123456789abcdef");
	len = (ft_strlen(arg));
	fmt->prcsn = ((fmt->point) && ((fmt->prcsn) > len)) ? fmt->prcsn : len;
	width = ((fmt->min_w) > (fmt->prcsn + 2)) ? fmt->min_w : fmt->prcsn + 2;
	if (!(result = ft_init_result_p(fmt, width)))
		return (0);
	i = 0;
	while (i < len)
	{
		if (fmt->minus)
			result[i + ((fmt->prcsn + 2) - len)] = arg[i];
		else
			result[width - (len - i)] = arg[i];
		i++;
	}
	ft_display_result(result, arg, fmt);
	return (1);
}
