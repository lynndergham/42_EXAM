/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:22:35 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/13 09:30:40 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
    {
        i++;
    }
    return i;
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        int i = 0;

        if (ft_strlen(av[2]) > 1 || ft_strlen(av[3]) > 1)
        {
            write(1, "\n", 1);
            return (0);
        }

        while (av[1][i])
        {
            if (av[1][i] == av[2][0])
                write(1, &av[3][0], 1);
            else
                write(1, &av[1][i], 1);
            i++;
        }
        
    }
    write(1, "\n", 1);
}