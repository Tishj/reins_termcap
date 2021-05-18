/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_memset.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:15:01 by tishj         #+#    #+#                 */
/*   Updated: 2021/05/18 17:21:39 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	util_memset(void *dest, unsigned char value, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = value;
		i++;
	}
}
