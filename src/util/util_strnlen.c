/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_strnlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 23:29:18 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/08 23:30:04 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	util_strnlen(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
		i++;
	return (i);
}
