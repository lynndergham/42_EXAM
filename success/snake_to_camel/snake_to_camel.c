/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:09:43 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/07/30 16:27:25 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i;
        int j;
        char *str;

        i = 0;
        j = 0;
        while (av[1][i])
        {
            if (av[1][i] == '_')
                j++;
            i++;
        }
        str = (char *)malloc(i - j + 1);
        i = 0;
        j = 0;
        while (av[1][i])
        {
            if (av[1][i] == '_')
            {
                i++;
                if (av[1][i] >= 'a' && av[1][i] <= 'z')
                {
                    str[j] = av[1][i] - 32;
                    i++;
                    j++;
                }
            }
            else
            {
                str[j] = av[1][i];
                i++;
                j++;
            }
        }
        str[j] = '\0';
        i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}