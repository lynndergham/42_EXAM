/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:21:55 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/07 19:30:48 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    
    while (str[i])
    {
        i++;
    }
    return (i);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int i = 0;
        int j = 0;
        int len = 0;


        while(av[2][j])
        {
            if (av[1][i] == av[2][j])
            {
                len++;
                i++;
            }
            j++;
        }
        if (ft_strlen(av[1]) == len)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    
    write(1, "\n", 1);
}
