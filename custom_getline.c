#include "monty.h"

/**
 * _getline - Reads an entire line from a file, dynamically allocating buffer
 * @lineptr: Address of pointer to allocated buffer
 * @n: Pointer to size of allocated buffer
 * @stream: File stream to read from
 *
 * Description: Reads stream line-by-line, dynamically reallocating buffer 
 * as needed until newline or EOF is reached. Null terminates line.
 * Handles realloc failure and errors.
 *
 * Return: Number of bytes read, or -1 on failure
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
    char *bufptr = NULL;
    char *newbuf;
    size_t size;
    size_t len;

    if (lineptr == NULL || stream == NULL || n == NULL) {
        errno = EINVAL;
        return -1;
    }

    if (*lineptr == NULL) {
        size = 128;
        bufptr = malloc(size);
        if (bufptr == NULL) {
            return -1;
        }
        *lineptr = bufptr;
        *n = size;
    } else {
        bufptr = *lineptr;
        size = *n;
    }

    len = 0;
    while (1) {
        if (fgets(bufptr + len, size - len, stream) == NULL) {
            if (ferror(stream)) {
                free(bufptr);
                *lineptr = NULL;
                return -1;
            }
            break;
        }
        len = strlen(bufptr);
        if (bufptr[len - 1] == '\n') {
            bufptr[len - 1] = '\0';
            break;
        }

        newbuf = realloc(bufptr, size * 2);
        if (newbuf == NULL) {
            free(bufptr);
            *lineptr = NULL;
            return -1;
        }
        bufptr = newbuf;
        *lineptr = bufptr;
        size *= 2;
    }

    *n = size;
    return len;
}
