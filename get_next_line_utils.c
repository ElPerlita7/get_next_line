/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:05:20 by abferrer          #+#    #+#             */
/*   Updated: 2025/03/13 22:16:43 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Calcula y devuelve la longitud de una cadena de caracteres (string)

int ft_strlen(char *s)
{
    int count;

     count = 0;
     while (s[count] != '\0')
    {
        count++;
    }
    return (count);
}
// Busca la primera aparición de un carácter en una cadena y devuelve un puntero a esa posición.

char    *ft_strchr(char *s, int c)
{
    int count;

    count = 0;
    while (s[count] != '\0')
    {
        if (s[count] == c)
            return ((char *)s + count);
        count++;
    }
    return (NULL);
}
// Extrae de un string que le pasa la parte que le indicas y copia esa parte del string substraida en otro nuevo bloque de memoria.

char	*ft_substr(char *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t  i;
    size_t  s_len;

    i = 0;
    s_len = ft_strlen(s);
    if (!s)
        return (NULL);
    if (len + start > s_len)
        len = s_len - start;
    substr = (char *)malloc(len +1);
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}
// Concatena dos cadenas y devuelve una nueva cadena resultante de la unión de ambas.

char	*ft_strjoin(char *s1, char *s2)
{
    char    *new_str;
    unsigned int    i;
    unsigned int    j;
    
    j = 0;
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
    while (s2[j] != '\0')
    {
        new_str[i] = s2[j];
        i++;
        j++;
    }
    new_str[i] = '\0';
    return (new_str);
}
// int main()
// {
//     char *s1 = "KELOKEKEDICEKELOKE";
//     // char *s2 = " KEPASA";
//     char *new_str = ft_substr(s1, 7, 12);
//     printf("%s\n", new_str);
    
//     return 0;
// }
