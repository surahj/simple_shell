#include "shell.h"

/**
 * _memcpy - copies memory area,
 * @dest: destination memory area.
 * @src: source memory area.
 * @n: bytes filled.
 * Return: the pointer to dest.
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *dest_ptr = (char *) dest;
	char *src_ptr = (char *) src;
	unsigned int i;

	for (i = 0; i < n; i++)
		dest_ptr[i] = src_ptr[i];

	return (dest_ptr);
}

/**
 * _strdup - duplicates a string
 *
 * @s: the given string
 * Return: pointer to the duplicate
 */
char *_strdup(const char *s)
{
	size_t len;
	char *dup;

	len = _strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	_memcpy(dup, s, len + 1);
	return (dup);
}

/**
 *_atoi - converts a string to an integer.
 *@s: pointer to string.
 *
 *Return: integer gotten.
 */
int _atoi(const char *s)
{
	int index, ind2;
	unsigned int res;
	int sign = 1;
	char now;

	index = 0;
	res = 0;
	while (*(s + index) != '\0')
	{
		now = *(s + index);
		if (now == '-')
		{
			sign *= -1;
		}
		if (now >= '0' && now <= '9')
		{
			ind2 = index;
			while (*(s + ind2) > 47 && *(s + ind2) < 58)
			{
				res = (res * 10) + *(s + ind2) - '0';
				ind2++;
			}
			break;
		}
		index++;
	}
	if (sign < 0)
		res *= sign;
	return (res);
}
