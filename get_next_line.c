/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:05:24 by abferrer          #+#    #+#             */
/*   Updated: 2025/03/14 17:05:08 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// funcion que lea el .txt y que lo añada con strjoin a tu buffer estatico.
// funcion para escribir tu linea con substr.
// funcion para limpiar el buffer estatico con substr despues de escribir una linea.
// hacer la funcion principal de get_next_line.

// Este get_next_line se compone de cuatro funciones:

// in_buffer(fd, buffer): Lee del archivo y guarda en buffer.
// procc_line(buffer): Extrae una línea completa de buffer.
// sep_line(buffer): Elimina la línea ya procesada y guarda lo restante.
// get_next_line(fd): Llama a las otras funciones y maneja la memoria.

static char *read_buffer(int fd, char *buffer)
{
    char    *buff;
    int     bytes_read;

    bytes_read = 1;
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    bytes_read = read(fd, buff, BUFFER_SIZE);
    if (bytes_read == -1)
         return (NULL);
    buffer = ft_strjoin(buffer, buff);
    return (buffer);
}
static char *write_line(char *buffer)
{
    int i;
    char *line;

    i = 0;
    while (buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    line = ft_substr(buffer, 0, i);
    if (buffer[i] == '\n')
    {
        line[i] = buffer[i];
    }
    return (line);
}
static char *clean_line(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
    return(buffer);
}
char *get_next_line(int fd)
{
    static char *static_buffer;
    char *line;
    
    if (!static_buffer)
    {
        static_buffer = malloc(sizeof(BUFFER_SIZE));
    }
    if (!static_buffer)
        return (NULL);
    static_buffer = read_buffer(fd, static_buffer);
    if (!static_buffer)
        return (NULL);
    line = write_line(static_buffer);
    if (!line)
        return (NULL);
    static_buffer = clean_line(static_buffer);
    return(line);
}
int main(void) 
{
    int fd = open("prueba.txt", O_RDONLY);
    char    *str2 = NULL;
    while ((str2 = get_next_line(fd)) != NULL)
    {
        printf("%s\n", str2);
        free(str2);
    }
    close(fd);
    return 0;
}