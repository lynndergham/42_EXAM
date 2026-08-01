/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:34:44 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/12 19:48:28 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        int j;
        char c;

        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                if ((av[i][j] >= 'A' && av[i][j] <= 'Z')
                    && (av[i][j + 1] == ' ' || av[i][j + 1] == '\0'))
                    c = av[i][j];
                else if ((av[i][j] >= 'a' && av[i][j] <= 'z')
                    && (av[i][j + 1] == ' ' || av[i][j + 1] == '\0'))
                    c = av[i][j] - 32;
                else if ((av[i][j] >= 'A' && av[i][j] <= 'Z')
                    && (av[i][j + 1] != ' ' || av[i][j + 1] != '\0'))
                    c = av[i][j] + 32;
                else
                    c = av[i][j];
                write(1, &c, 1);
                j++;
            }
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}