/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_key.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:39:28 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/14 16:21:26 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <stdlib.h>

t_key	*new_key(char keycode[MAX_KEY_SIZE], t_keyf f)
{
	t_key	*this;

	this = malloc(sizeof(t_key));
	if (!this)
		return (NULL);
	util_bzero(this->buf, MAX_KEY_SIZE);
	util_memcpy(this->buf, keycode, MAX_KEY_SIZE);
	this->size = util_strnlen(this->buf, MAX_KEY_SIZE);
	this->function = f;
	this->hook.function = NULL;
	this->hook.param = NULL;
	return (this);
}
