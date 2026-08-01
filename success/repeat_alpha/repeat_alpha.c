/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:21:08 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/07/31 19:34:05 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int j = 0;
		int k = 0;

		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				j = av[1][i] - 96;
				while (k < j)
				{
					write(1, &av[1][i], 1);
					k++;
				}
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				j = av[1][i] - 64;
				while (k < j)
				{
					write(1, &av[1][i], 1);
					k++;
				}
			}
			else
				write(1, &av[1][i], 1);
			j = 0;
			k = 0;
			i++;
		}
	}
	write(1, "\n", 1);
}
