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

static int	ft_minimemory(const long long int ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (count += ft_putstr_fd("(nil)", 1));
	else
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_putnbr_base(ptr, "0123456789abcdef");
	}
	return (count);
}

static int	ft_excheck(char const c, va_list arg)
{
	int	count;

	count = 0;
	if (c == '%')
		count = ft_putchar_fd('%', 1);
	else if (c == 'c')
		count = ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 's')
		count = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'i' || c == 'd')
		count = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'x')
		count = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		count = ft_minimemory(va_arg(arg, long long int));
	else if (c == 'u')
		count = ft_putnbr_fd(va_arg(arg, unsigned int), 1);
	return (count);
}

int	ft_miniprintf(char const c, va_list arg)
{

}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	int		count;
	int		final;
	va_list	arg;

	i = 0;
	final = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] != 37)
		{
			count = ft_putchar_fd(s[i], 1);
			if (count == -1)
				return -1;
			final += count;
			i++;
		}
		else
		{
			count = ft_excheck(s[i + 1], arg);
			if (count == -1)
				return (-1);
			final += count;
			i += 2;
		}
	}
	return (final);
}
