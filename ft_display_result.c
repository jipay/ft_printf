/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:34:28 by jdidier           #+#    #+#             */
/*   Updated: 2020/10/17 20:50:51 by jdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_result(char *result, char *arg, t_fmt *fmt)
{
	if (arg)
	{
		free(arg);
		arg = 0;
	}
	ft_putstr_fd(result, 1);
	fmt->ret = ft_strlen(result);
	free(result);
	result = 0;
}
