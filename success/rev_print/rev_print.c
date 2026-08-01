/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:54:38 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/12 14:57:56 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return(i);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int len = ft_strlen(av[1]);
        int i = len - 1;

        while (i >= 0)
        {
            write(1, &av[1][i], 1);
            i--;
        }
        
    }
    write(1, "\n", 1);
}