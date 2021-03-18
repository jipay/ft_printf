/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:20:39 by jdidier           #+#    #+#             */
/*   Updated: 2020/06/04 17:50:20 by jdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(int n, char *result, int *i)
{
	long int nbl;

	nbl = n;
	if (nbl < 0)
	{
		result[*i] = '-';
		nbl *= -1;
		*i += 1;
	}
	if (nbl >= 10)
	{
		ft_recursive(nbl / 10, result, i);
		ft_recursive(nbl % 10, result, i);
	}
	else
	{
		result[*i] = (nbl + '0');
		*i += 1;
	}
}

char		*ft_itoa(int n)
{
	int		counter;
	long	nb;
	char	*result;

	counter = 0;
	nb = n;
	if (nb < 0)
	{
		counter++;
		nb *= -1;
	}
	while (nb >= 1)
	{
		nb /= 10;
		counter++;
	}
	if (!(result = malloc(sizeof(*result) * (counter + 1))))
		return (NULL);
	counter = 0;
	ft_recursive(n, result, &counter);
	result[counter] = '\0';
	return (result);
}
