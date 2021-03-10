/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 13:00:43 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 13:16:14 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REINS_H
# define REINS_H

# include <reins_int.h>

//-----------------------PROTOTYPES-------------------------------

t_reins		*reins_init(void);
int			reins_get_input(t_reins *reins, char **line);
void		reins_destroy(t_reins *reins);
int			reins_enable(t_reins *reins);
int			reins_disable(t_reins *reins);
int			reins_key(t_reins *reins, char *raw_key, t_keyf func);
int			reins_hook(t_reins *reins, char *raw_key, void (*f)(), void *param);

#endif
