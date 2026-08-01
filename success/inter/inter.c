/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:47:43 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/18 14:54:53 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;
	unsigned char seen[256] = {0};

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					if (!seen[(unsigned char)av[1][i]])
					{
						write(1, &av[1][i], 1);
						seen[(unsigned char)av[1][i]] = 1;
					}
					// break ;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
