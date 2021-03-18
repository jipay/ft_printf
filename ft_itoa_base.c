/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:46:44 by jdidier           #+#    #+#             */
/*   Updated: 2020/06/19 10:59:36 by jdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(unsigned long long n, char *result, char *base, int *i)
{
	int		baselen;

	baselen = ft_strlen(base);
	if (n >= (unsigned long long)baselen)
		ft_recursive(n / baselen, result, base, i);
	result[*i] = base[n % baselen];
	*i += 1;
}

char		*ft_itoa_base(unsigned long long n, char *base)
{
	int					counter;
	unsigned long long	nb;
	char				*result;
	int					baselen;

	nb = n;
	baselen = ft_strlen(base);
	counter = 1;
	while ((nb = nb / baselen) >= 1)
		counter++;
	if (!(result = malloc(sizeof(*result) * (counter + 1))))
		return (NULL);
	counter = 0;
	ft_recursive(n, result, base, &counter);
	result[counter] = '\0';
	return (result);
}
