/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:07:28 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/18 16:57:30 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int first_word = 1;

		while (av[1][i])
		{
			// Skip spaces
			while (av[1][i] == ' ')
				i++;

			// Print a space before printing a new word, if it's not the first word
			if (av[1][i] && !first_word)
				write(1, " ", 1);

			// Print the word
			while (av[1][i] && av[1][i] != ' ')
			{
				write(1, &av[1][i], 1);
				i++;
			}

			// After printing the first word, we know the subsequent words will need a leading space
			first_word = 0;
		}
	}
	write(1, "\n", 1);
	return 0;
}
