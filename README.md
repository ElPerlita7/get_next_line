# get_next_line

Implementar una función en C que lea una línea de un archivo cada vez que se llama, manteniendo su estado entre llamadas. El reto principal es gestionar correctamente la memoria, el buffer y múltiples descriptores de archivo (file descriptors).

🧠 ¿Qué se espera?
Debes escribir una función con el siguiente prototipo:
char *get_next_line(int fd);
Parámetro: fd es un file descriptor válido.

Devuelve:
La próxima línea leída (incluyendo el salto de línea \n si lo hay).

NULL si no hay más líneas o si ocurre un error.

⚙️ Funcionalidades clave:
Lectura por trozos (BUFFER_SIZE):
Usar read() para leer bloques del archivo con un tamaño de buffer definido (por macro o compilación).

Memoria dinámica:
Concatenar los bloques hasta construir una línea completa, cuidando las fugas de memoria.

Soporte para múltiples fd:
Debes manejar varios archivos abiertos simultáneamente sin que interfieran entre sí.

Manejo de saltos de línea y EOF:
Devolver cada línea completa una por una, incluyendo el último fragmento aunque no termine en \n.

🔧 Reglas del proyecto:
Solo puedes usar funciones estándar limitadas: read, malloc, free, y ninguna función de la libft como strchr, strcpy, etc. (a menos que las implementes tú).

El código debe estar norminette compliant (la guía de estilo del proyecto 42).
