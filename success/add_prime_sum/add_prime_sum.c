/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:32:41 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/15 17:24:28 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *src)
{
    int i = 0;
    int n = 0;

    while (src[i] == ' ')
        i++;
    if (src[i] == '+')
        i++;
    while (src[i] >= '0' && src[i] <= '9')
    {
        n = (n * 10) + (src[i] - '0');
        i++;
    }
    return (n);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nbr)
{
    if (nbr >= 10)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    else
        ft_putchar(nbr + '0');
}

int is_prime(int nbr)
{
    // first prime number is 3, if nbr smaller than that we
    // can return 0 to say it's not prime
    if (nbr < 2)
        return (0);
    // checking all factors up until half nbr
    // going over nbr/2 is useless, let's take an example
    // nbr = 10; nbr/2 = 5; If we check for 3, checking for 6
    // will give the same result
    int i = 2;
    while (i <= nbr / 2)
    {
        if (nbr % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac == 2 && ft_atoi(av[1]))
    {
        int i = 1;
        int n = ft_atoi(av[1]);
        int sum = 0;

        while (n > 1)
        {
            if (is_prime(n))
                sum += n;
            n--;
        }
        ft_putnbr(sum);
        ft_putchar('\n');
    }
    else
        write(1, "0\n", 2);
}