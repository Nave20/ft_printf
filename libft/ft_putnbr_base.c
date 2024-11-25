/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:27:20 by vpirotti          #+#    #+#             */
/*   Updated: 2024/11/23 17:27:28 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_base(char *base)
{
	int	i;
	int	a;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		a = 0;
		while (a < i)
		{
			if (base[a] == base[i])
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

int	ft_printer(int i, char *a)
{
	int	count;

	count = 0;
	i--;
	while (i > -1)
	{
		count += (int) write(1, &a[i], 1);
		i--;
	}
	return (count);
}

int	ft_putnbr_base(long long int nbr, char *base)
{
	int		i;
	int		size;
	char	a[1000];

	if (check_base(base) == 0)
		return (-1);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	size = (int) ft_strlen(base);
	i = 0;
	while (nbr > 0)
	{
		a[i] = base[nbr % size];
		nbr = nbr / size;
		i++;
	}
	return (ft_printer(i, a));
}
