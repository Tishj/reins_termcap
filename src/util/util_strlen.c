/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_strlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:32:17 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 15:29:38 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	util_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
