/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_strncmp.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 22:43:20 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 15:29:28 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	util_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (i == n || str1[i] == str2[i])
		return (0);
	return (str1[i] - str2[i]);
}
