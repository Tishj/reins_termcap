/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 21:39:28 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/07 23:48:45 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reigns_int.h>
#include <stdlib.h>
#include <stdio.h>

t_hook	*new_hook(char keycode[6], void (*f)(), void *param)
{
	t_hook	*this;

	this = malloc(sizeof(t_hook));
	if (!this)
		return (NULL);
	util_memcpy(this->buf, keycode, 6);
	this->function = f;
	this->param = param;
	return (this);
}
