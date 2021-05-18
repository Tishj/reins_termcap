/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_input_empty.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 15:17:28 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/18 15:18:03 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>

bool	reins_input_empty(t_input *input)
{
	return (!input->line.size);
}
