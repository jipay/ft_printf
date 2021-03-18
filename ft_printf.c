/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:02:56 by jdidier           #+#    #+#             */
/*   Updated: 2020/10/18 00:42:58 by jdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fmt	*ft_getfmt(char **format, va_list ad)
{
	t_fmt	*fmt;

	fmt = ft_init_fmt();
	(*format)++;
	while (ft_isflag(**format, fmt))
		(*format)++;
	ft_checkminw(format, fmt, ad);
	if (**format == '.')
	{
		fmt->point = 1;
		(*format)++;
	}
	ft_checkprcsn(format, fmt, ad);
	fmt->conv = ft_isconv(**format);
	return (fmt);
}

char	*ft_init_arg_u(t_fmt *fmt, unsigned int arg_u)
{
	char	*arg;

	if (arg_u == 0 && fmt->point)
		arg = ft_strdup("");
	else
	{
		if (fmt->conv == 'u')
			arg = ft_itoa_base(arg_u, "0123456789");
		if (fmt->conv == 'x')
			arg = ft_itoa_base(arg_u, "0123456789abcdef");
		if (fmt->conv == 'X')
			arg = ft_itoa_base(arg_u, "0123456789ABCDEF");
	}
	return (arg);
}

int		ft_parse_arg(t_fmt *fmt, va_list ad)
{
	if (fmt->conv == 'c')
		return (ft_parse_c(fmt, va_arg(ad, int)));
	else if (fmt->conv == '%')
		return (ft_parse_c(fmt, '%'));
	else if (fmt->conv == 's')
		return (ft_parse_s(fmt, ad));
	else if (fmt->conv == 'd' || fmt->conv == 'i')
		return (ft_parse_d(fmt, va_arg(ad, int)));
	else if (fmt->conv == 'u' || fmt->conv == 'x' || fmt->conv == 'X')
		return (ft_parse_u(fmt, va_arg(ad, unsigned int)));
	else if (fmt->conv == 'p')
		return (ft_parse_p(fmt, va_arg(ad, unsigned long int)));
	return (0);
}

int		ft_reader(char *format, t_fmt *fmt, va_list ad)
{
	int ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!(fmt = ft_getfmt(&format, ad)))
				return (-1);
			while (*format != fmt->conv)
				format++;
			format++;
			if (!(ft_parse_arg(fmt, ad)))
				return (-1);
			ret += fmt->ret;
			free(fmt);
			fmt = 0;
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			ret++;
		}
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	ad;
	char	*str;
	int		ret;
	t_fmt	*fmt;

	fmt = NULL;
	if (!format)
		return (-1);
	ret = 0;
	str = (char *)format;
	va_start(ad, format);
	ret = ft_reader(str, fmt, ad);
	va_end(ad);
	return (ret);
}
