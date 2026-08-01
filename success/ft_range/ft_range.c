/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:47:20 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/15 13:24:58 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int len;
    int *arr;
    int i = 0;

    if (start >= end)
        len = start - end;
    else
        len = end - start;
    arr = (int *)malloc(len * sizeof(int));
    if (start <= end)
    {
        while (start <= end)
        {
            arr[i] = start;
            // printf("D%dD\n", arr[i]);
            start++;
            i++;
        }
    }
    else
    {
        while (end <= start)
        {
            arr[i] = start;
            // printf("D%dD\n", arr[i]);
            start--;
            i++;
        }
    }
    return(arr);
}

// int main(void)
// {
//     ft_range(0, -3);
// }