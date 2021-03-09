/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_strncpy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:08:35 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 14:10:59 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	util_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
}
