#include "shell.h"

/**
 *_strlen - returns length of a string.
 *@s: a pointer to an int.
 *
 *Return: length of string.
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcmp - compares two strings
 * @str1: First string.
 * @str2: Second string.
 *
 * Return: True if equal.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (0);
		}

		str1++;
		str2++
	}

	return (*str1 == *str2);
}

/**
 * _strcpy - copy a string from one pointer to another pointer
 *      including the terminating null byte (\0)
 *
 * @src: source of string parameter.
 * @dest: destination of string parametr.
 *
 * Return: pointer to dest input parameter
*/

char *_strcpy(char *dest, char *src)
{
	int i;
	int j = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[j] = src[i];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
