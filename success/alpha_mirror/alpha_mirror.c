/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:25:32 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/12 19:33:33 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *rev = "zyxwvutsrqponmlkjihgfedcba";
		int i = 0;
		char c;
		
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				c = rev[av[1][i] - 97];
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				c = rev[av[1][i] - 65] - 32;
			else
				c = av[1][i];
			write(1, &c, 1);
			i++;
		}
		
	}
	write(1, "\n", 1);
}