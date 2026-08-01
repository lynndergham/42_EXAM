/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:51:56 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/07/31 16:38:42 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	if (str_base < 2 || str_base > 16)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
        int value;

        if (str[i] >= '0' && str[i] <= '9')
            value = str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            value = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            value = str[i] - 'A' + 10;
        else
            break;
        if (value >= str_base)
            break;
        res = res * str_base + value;
		i++;
	}
	return (res * sign);
}

// int main(void)
// {
// 	printf("%d\n", ft_atoi_base("12fdb3", 16)); // Should print 1251763
//     printf("%d\n", ft_atoi_base("-12FDB3", 16)); // Should print -1251763
//     printf("%d\n", ft_atoi_base("101", 2)); // Should print 5
//     printf("%d\n", ft_atoi_base("-7a", 16)); // Should print -122
//     printf("%d\n", ft_atoi_base("123", 8)); // Should print 83
// }