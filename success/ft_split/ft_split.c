/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:39:56 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/07/31 19:09:56 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int word_len(char *str)
{
	int i = 0;

	while (str[i] && str[i] != ' ')
	{
		i++;
	}
	return (i);
}

int	count_words(char *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i + 1] == ' ')
			count++;
		if (str[i] != ' ' && str[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

char *get_word(char *str, int len)
{
	char *res;
	int i = 0;

	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char    **ft_split(char *str)
{
	char **res;
	int i = 0;
	int j = 0;
	int len = 0;

	res = (char **)malloc((count_words(str) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		len = word_len(str + i);
		if (len)
		{
			res[j] = get_word(str + i, len);
			j++;
		}
		i += len;
	}
	return (res);
}

// int main(void)
// {
// 	char **test;
// 	int i = 0;

// 	test = ft_split("Hello my name is ali");
// 	while (test[i])
// 	{
// 		printf("S%sS\n", test[i]);
// 		i++;
// 	}
// }
