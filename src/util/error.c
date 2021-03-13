/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 15:12:41 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/13 20:38:54 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdio.h>

int	error(char *msg, int error_value)
{
	printf("%s\n", msg);
	return (error_value);
}
