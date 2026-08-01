/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:29:16 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/19 15:45:22 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 4)
    {
        int n1, n2;

        n1 = atoi(av[1]);
        n2 = atoi(av[3]);

        if (av[2][0] == '+')
            printf("%d", n1 + n2);
        else if (av[2][0] == '-')
            printf("%d", n1 - n2);
        else if (av[2][0] == '*')
            printf("%d", n1 * n2);
        else if (av[2][0] == '/')
            printf("%d", n1 / n2);
        else if (av[2][0] == '%')
            printf("%d", n1 % n2);
    }
    printf("\n");
}