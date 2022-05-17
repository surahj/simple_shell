#include "shell.h"

/**
 * _strlen - Returns lenght of a string
 * @s: the string checked
 * Return: lenght of the string
 */

size_t _strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
* _strcat - concatenates two strings
* @dest: pointer parameter for string
* @src: pointer parameter for second string
*
* Return: concatenated string
*/

char *_strcat(char *dest, const char *src)
{
	int l, j;

	l = 0;

	while (dest[l] != '\0')
	{
		++l;
	}
	for (j = 0; src[j] != '\0'; j++, ++l)
	{
		dest[l] = src[j];
	}
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
			break;
		op = *(s1 + i) - *(s2 + i);
		i++;
	}

	return (op);
}

/**
 *_strcpy - copy string at the end of another string including \0.
 *@dest: pointer to destination string.
 *@src: pointer to source string.
 *
 *Return: The dest.
 */
char *_strcpy(char *dest, char *src)
{
	size_t j;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';

	return (dest);
}
