/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:05:20 by abferrer          #+#    #+#             */
/*   Updated: 2025/03/19 22:53:19 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int	i;
	
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t  i;

	if (!s)
		return (NULL);
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
    i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
    char    *new_str;
    unsigned int    i;
    unsigned int    j;
    
    i = 0;
    if (!s1 || !s2) 
        return (NULL);
    new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new_str)
        return (NULL);
    while (s1[i] != '\0')
    {
        new_str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        new_str[i] = s2[j];
        i++;
        j++;
    }
    new_str[i] = '\0';
    return (new_str);
}
