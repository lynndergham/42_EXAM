/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:11:28 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/07 16:12:08 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac > 1)
    {
        char *first;
        int i = 0;
        int j = 0;
        int len = 0;
        int x = 0;

        while (av[1][i] == ' ')
            i++;
        while (av[1][i] && av[1][i] != ' ')
        {
            // printf("S%cS\n", av[1][i]);
            len++;
            i++;
        }
        first = (char *)malloc(len + 1 * sizeof(char));
        i = 0;
        while (av[1][i] == ' ')
            i++;
        while (av[1][i] && av[1][i] != ' ')
        {
            first[j] = av[1][i];
            j++;
            i++;
        }
        first[j] = '\0';
        while (av[1][i])
        {
            while (av[1][i] == ' ')
                i++;
            while (av[1][i] && av[1][i] != ' ')
            {
                write(1, &av[1][i], 1);
                x = 1;
                i++;
            }
            while (av[1][i] == ' ')
                i++;
            if (x)
                write(1, " ", 1);
        }
        i = 0;
        while (first[i])
        {
            write(1, &first[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}