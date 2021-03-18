/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 10:30:20 by jdidier           #+#    #+#             */
/*   Updated: 2020/10/18 00:30:44 by jdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fmt	*ft_init_fmt(void)
{
	t_fmt	*fmt;

	if (!(fmt = malloc(sizeof(*fmt))))
		return (NULL);
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->min_w = 0;
	fmt->point = 0;
	fmt->prcsn = 0;
	fmt->ret = 0;
	return (fmt);
}

int		ft_isflag(int c, t_fmt *fmt)
{
	if (c == '-')
	{
		fmt->minus = 1;
		return (1);
	}
	else if (c == '0')
	{
		fmt->zero = 1;
		return (1);
	}
	else
		return (0);
}

int		ft_isconv(int c)
{
	if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i') ||
	(c == 'u') || (c == 'x') || (c == 'X') || (c = '%'))
		return (c);
	else
		return (0);
}

void	ft_checkminw(char **format, t_fmt *fmt, va_list ad)
{
	while (ft_isdigit(**format))
	{
		fmt->min_w *= 10;
		fmt->min_w += ((**format) - 48);
		(*format)++;
	}
	if (**format == '*')
	{
		fmt->min_w = va_arg(ad, int);
		if (fmt->min_w < 0)
		{
			fmt->minus = 1;
			fmt->min_w *= -1;
		}
		(*format)++;
	}
}

void	ft_checkprcsn(char **format, t_fmt *fmt, va_list ad)
{
	while (ft_isdigit(**format))
	{
		fmt->prcsn *= 10;
		fmt->prcsn += ((**format) - 48);
		(*format)++;
	}
	if (**format == '*')
	{
		fmt->prcsn = va_arg(ad, int);
		if (fmt->prcsn < 0)
			fmt->point = 0;
		(*format)++;
	}
}
