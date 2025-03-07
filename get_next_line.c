/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:05:24 by abferrer          #+#    #+#             */
/*   Updated: 2025/03/03 20:34:04 by abferrer         ###   ########.fr       */
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

char *get_next_line(int fd)
{
    
}
