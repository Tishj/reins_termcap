/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 13:00:43 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 11:33:22 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REIGNS_H
# define REIGNS_H

# include <reigns_int.h>

//-----------------------PROTOTYPES-------------------------------

t_reigns	*reigns_init();
int			reigns_get_input(t_reigns* reigns, char **line);
void		reigns_destroy(t_reigns* reigns);
//reigns_enable //<- raw
//reigns_disable //<- standard

int			reigns_key(t_reigns* reigns, char keycode[6], t_keyf func);
int			reigns_hook(t_reigns* reigns, char keycode[6], void (*f)(), void *param);

#endif
