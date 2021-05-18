/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_key.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:39:28 by tishj         #+#    #+#                 */
/*   Updated: 2021/05/18 18:40:01 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdlib.h>

t_key	*new_key(char *keycode, t_keyf f)
{
	t_key	*this;

	this = malloc(sizeof(t_key));
	if (!this)
		return (NULL);
	this->keycode = keycode;
	this->function = f;
	this->hook.function = NULL;
	this->hook.param = NULL;
	return (this);
}
