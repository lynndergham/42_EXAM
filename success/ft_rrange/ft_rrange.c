/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:07:21 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/08/12 15:51:46 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
    int len;
    int *arr;
    int i = 0;

    len = (end - start) > 0 ? end - start : start - end;
    arr = (int *)malloc(len * sizeof(int));
    if (!arr)
        return (NULL);
    if (end >= start)
    {
        while (end >= start)
        {
            arr[i] = end;
            // printf("%d -> ", arr[i]);
            i++;
            end--;
        }
    }
    else
    {
        while (start >= end)
        {
            arr[i] = end;
            // printf("%d -> ", arr[i]);
            i++;
            end++;
        }
    }
    return (arr);
}

// int main(void)
// {
//     int *arr = ft_rrange(0, -3);
//     int i = 2;
//     // while (i >= 0)
//     // {
//     //     printf("%d -> ", arr[i]);
//     //     i--;
//     // }
    
// }