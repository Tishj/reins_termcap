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

#include <stdbool.h>
#include <stddef.h>

# define KEY_CNTRL_U		"\x15"
# define KEY_CNTRL_D		"\x4"
# define KEY_NEWLINE		"\xA"
# define KEY_CNTRL_L		"\xC"
# define KEY_ESC			"\x1B"
# define KEY_CNTRL_U		"\x15"
# define KEY_UP				"\x41"
# define KEY_DOWN			"\x42"
# define KEY_RIGHT			"\x43"
# define KEY_LEFT			"\x44"
# define KEY_END			"\x46"
# define KEY_HOME			"\x48"
# define KEY_DEL			"\x7F"

/*
**	--------------------READ_STATE--------------------
*/

/*
**	returned by t_keyf functions to signal the state of the reader
*/
enum	e_readstate
{
	RD_ERROR,
	RD_EOF,
	RD_SEND,
	RD_IDLE
};

typedef struct s_hook t_hook;

typedef void	(*t_hookf)(void *tmp);

typedef struct s_reins t_reins;
typedef struct s_hook t_hook;
typedef struct s_input t_input;

typedef int	(*t_keyf)(t_input *input, char *buf, t_hook *hook);

//-----------------------PROTOTYPES-------------------------------

void		reins_hook_run(t_hook *hook);
t_reins		*reins_init(void);
int			reins_get_input(t_reins *reins, char **line);
void		reins_destroy(t_reins *reins);
int			reins_enable(t_reins *reins);
int			reins_disable(t_reins *reins);
int			reins_key(t_reins *reins, char *raw_key, t_keyf func);
int			reins_hook(t_reins *reins, char *raw_key, t_hookf func, void *param);
int			reins_print_keycodes(t_reins *reins);

int			reins_cursor_move(t_input *input, size_t x, size_t y, bool cap);
int			reins_input_add(t_input *input, char *str, size_t len);
int			reins_input_del(t_input *input, size_t len);
int			reins_input_clear(t_input *input);
bool		reins_input_empty(t_input *input);
size_t		reins_input_size(t_input *input);

#endif
