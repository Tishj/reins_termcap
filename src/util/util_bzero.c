/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_bzero.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:09:40 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/05 18:11:00 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	util_bzero(void *buf, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)buf)[i] = '\0';
		i++;
	}
}
