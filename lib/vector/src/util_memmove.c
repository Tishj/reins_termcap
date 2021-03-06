/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_memmove.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 19:40:38 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 19:41:37 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	util_memmove(void *dst, void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	char			rev;
	size_t			i;

	if (!dst || !src || !n)
		return ;
	rev = (dst > src && src + n > dst);
	i = 0;
	dest = dst;
	source = src;
	while (i < n)
	{
		if (rev)
			dest[(n - 1) - i] = source[(n - 1) - i];
		else
			dest[i] = source[i];
		i++;
	}
}
