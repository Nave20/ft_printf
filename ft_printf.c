/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:16:07 by vpirotti          #+#    #+#             */
/*   Updated: 2024/11/23 10:16:07 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft/libft.h"


int	ft_excheck(char const c, size_t i, va_list arg)
{
	int	count;

	count = 0;
	if (c == 37)
		count += ft_putchar_fd('%', 1);// --> %%
	else if (c == 99)
		count += ft_putchar_fd(va_arg(arg, int), 1);// --> %c
	else if (c == 115)
		count += ft_putstr_fd(va_arg(arg, char *), 1);// --> %s
	else if (c == 105)
		count += ft_putnbr_fd(va_arg(arg, int), 1);// --> %i
	return (count);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	int count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] != 37)
		{
			count += ft_putchar_fd(s[i], 1);
			i++;
		}
		else
		{
			count += ft_excheck(s[i + 1], i, arg);
			i += 2;
		}
	}
	return (count);
}
#include <stdio.h>
int main(void)
{
	printf("%d", ft_printf("test %i\n", -103));
	return 0;
}