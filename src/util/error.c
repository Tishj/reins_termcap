/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 15:12:41 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/12 15:16:47 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdio.h>

enum e_readstate	error(char *msg, enum e_readstate error_value)
{
	printf("%s\n", msg);
	return (error_value);
}
