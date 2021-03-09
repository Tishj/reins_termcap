/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_keycode_formatted.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:24:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 14:43:47 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_keycode_formatted(char keycode[6])
{
	printf("KEYCODE[%d][%d][%d][%d][%d][%d]\n", (int)keycode[0], (int)keycode[1], (int)keycode[2], (int)keycode[3], (int)keycode[4], (int)keycode[5]);
}
