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
int			reins_print_keycodes(t_reins *reins);

int			reins_cursor_move(t_input *input, size_t x, size_t y, bool cap);
int			reins_input_add(t_input *input, char *str, size_t len);
int			reins_input_del(t_input *input, size_t len);
int			reins_input_clear(t_input *input);
bool		reins_input_empty(t_input *input);
size_t		reins_input_size(t_input *input);

#endif
