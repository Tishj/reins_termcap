/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_memcmp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:01:50 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 15:29:55 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	util_memcmp(void *dst, void *src, size_t n)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (i < n && ((unsigned char *)dst)[i] == ((unsigned char *)src)[i])
		i++;
	if (i == n)
		return (0);
	return (((unsigned char*)dst)[i] - ((unsigned char*)src)[i]);
}
