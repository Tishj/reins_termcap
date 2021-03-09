/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_memcpy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:15:01 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 15:29:46 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	util_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
}
