/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_atoi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:00:50 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 13:57:06 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	util_atoi(char *str)
{
	int				i;
	int				result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}
