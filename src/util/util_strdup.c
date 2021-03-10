/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_strdup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:13:25 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/07 22:18:43 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <reins_int.h>

char	*util_strdup(char *str)
{
	size_t	len;
	char	*dup;

	len = util_strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	util_memcpy(dup, str, len + 1);
	return (dup);
}
