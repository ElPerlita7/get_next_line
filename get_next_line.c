/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:05:24 by abferrer          #+#    #+#             */
/*   Updated: 2025/03/25 15:49:52 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	advance_to_nl_or_end(t_buf *buf)
{
	// Avanzamos la posicion hasta el final del buffer o '\n'.
	while (buf->position < (size_t)buf->bytes_read
		&& buf->buf[buf->position] != '\n')
		++(buf->position);
	// Si la posicion no es bytes_read, significa que si encontramos '\n'.
	if (buf->position < (size_t)buf->bytes_read)
	{
		// Avanzamos la posicion 1 para que incluya el caracter '\n'.
		++buf->position;
		buf->nl_found = true; // Encontrado.
	}
}

int	buf_fill(int fd, t_buf *buf)
{
	if (buf->position >= (size_t)buf->bytes_read)
	{
		buf->position = 0;
		buf->bytes_read = read(fd, buf->buf, BUFFER_SIZE);
		if (buf->bytes_read < 0)
			return (-1);
		if (buf->bytes_read == 0)
			return (0);
		return (1);
	}
	return (1);
}

/**

	*  Copia la linea que hemos encontrado en el buffer que empieza en el indice begin
 *  y termina en el indice end.
 */
char	*copy_from_buf_to_line(t_buf *buf, char *old_line, size_t begin,
		size_t end)
{
	size_t	len;
	char	*new_line;
	char	*joined_line;

	len = end - begin;
	new_line = ft_substr(buf->buf, begin, len);
	// Cuando es NULL la linea? No hay linea anterior porque esta es la primera.
	if (old_line == NULL)
		return (new_line);
	else // Ya habia cosas en la linea.
	{
		joined_line = ft_strjoin(old_line, new_line);
		free(new_line);
		free(old_line);
		return (joined_line);
	}
}

void	buf_init(t_buf *buf)
{
	// Solo se inicializa si no se ha inicializado antes.
	// o si ya esta inicializado, no lo toca.
	if (buf->buf == NULL)
	{
		buf->nl_found = false;
		buf->bytes_read = 0;
		buf->position = 0;
		buf->buf = malloc(BUFFER_SIZE);
	}
}

/**
 * 1. Llenamos el buffer (solo si hiciera falta).
 * 2. Guardamos la posicion donde comienza la linea.

	* 3. Avanzamos el indice del buffer hasta donde termina la linea o el final del buffer.
 * 4. Copiamos la linea desde el buffer a la variable line que vamos a devolver.

	* 5. Se repite todo hasta que se encuentra la nueva linea o se acabe lo que hay en el FD.
 * 6. Devolvemos la linea al usuario.
 */
char	*get_next_line(int fd)
{
	static t_buf	buf;
	char			*line;
	size_t			begin;
	ssize_t			bytes_read;

	// Chequear precondiciones.
	// Los fd no pueden ser negativos. No existen.
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf_init(&buf);
	if (buf.buf == NULL)
		return (NULL);
	// Inicializar las variables porque pueden tener cualquier valor antes de ser definidas.
	line = NULL;         
		// Si no haces line = NULL; line tiene cualquier valor.
	buf.nl_found = false; // Lo mismo pasa aquí
	// Cuando va a parar el loop? Cuando encontremos una '\n' dentro del buffer.
	while (!buf.nl_found)
	{
		bytes_read = buf_fill(fd, &buf); // Llenamos el buffer.
		if (bytes_read == -1)            // read error
			return (free(line), free(buf.buf), buf.buf = NULL, NULL);
		if (bytes_read == 0) // read done
			return (free(buf.buf), buf.buf = NULL, line);
		begin = buf.position;                                         
			// Guardamos donde empieza la linea
		advance_to_nl_or_end(&buf);                                   
			// Avanzamos la posición de buf hasta el caracter destras del próximo '\n' or el final.
		line = copy_from_buf_to_line(&buf, line, begin, buf.position);
			// Copiamos la linea en el buffer a la variable line;
		if (line == NULL)                                             
			// Error copiando la linea.
			return (free(buf.buf), buf.buf = NULL, NULL);
	}
	return (line);
}

#include <stdio.h>

int main(void)
{
    int 	fd = open("prueba.txt", O_RDONLY);
    char	*line = NULL;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
