/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_size.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 15:19:05 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/18 15:19:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

size_t	reins_input_size(t_input *input)
{
	return (input->line.size);
}
