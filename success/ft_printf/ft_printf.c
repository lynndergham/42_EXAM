/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:24:36 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/22 13:30:59 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


void	put_string(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		*len += write(1, str++, 1);
	}
}

void	put_nbr(long long int nbr,int base, int *len)
{
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		put_nbr((nbr / base), base, len);
	*len += write(1, &("0123456789abcdef"[nbr % base]), 1);
}

int ft_printf(const char *format, ... )
{
	int len = 0;
	va_list ptr;

	va_start(ptr, format);
	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_nbr((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_nbr((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ptr);
	return (len);
}

// int main(void)
// {
// 	printf("D%dD\n", ft_printf("D%dD\n", -2147483648));
// }