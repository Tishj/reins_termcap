/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_keycode_formatted.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:24:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 20:52:55 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_keycode_formatted(char *keycode, size_t n)
{
	size_t	i;

	i = 0;
	printf("KEYCODE");
	while (i < n)
	{
		printf("[%d]", (int)keycode[i]);
		i++;
	}
	printf("\n");
}
