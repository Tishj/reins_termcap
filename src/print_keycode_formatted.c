/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_keycode_formatted.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:24:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/23 00:06:36 by tbruinem      ########   odam.nl         */
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
