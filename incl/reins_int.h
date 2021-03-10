/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_int.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:44:08 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 11:47:50 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REINS_INT_H
# define REINS_INT_H

# include <termios.h>
# include <stddef.h>
# include <vector.h>
# include <stdbool.h>

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

/*
**	----------------TERMINAL_COMMANDS-----------------
*/

# define INSERT_START		"im"
# define INSERT_END			"ei"
# define MOVE_HORIZONTAL	"ch"
# define MOVE_COLROW		"cm"
# define DELETE_START		"dm"
# define DELETE_END			"ed"
# define SCROLL_REV			"rs"
# define CLEAR_SCREEN		"cl"
# define CARRIAGE_RETURN	"cr"
# define DELETE_LINE		"dl"
# define DELETE_LINES		"DL"
# define MOVE_ROWUP			"up"
# define DELETE_CHAR		"dc"
# define DELETE_CHARS		"DC"
# define SCROLL_LINE		"sf"
# define SCROLL_LINES		"SF"
# define SCROLL_UP			"sr"

/*
**	----------------SPECIAL_CHARACTERS----------------
*/

# define KEY_CNTRL_D "\x4"
# define KEY_NEWLINE "\xA"
# define KEY_CNTRL_L "\xC"
# define KEY_ESC "\x1B"
# define KEY_CNTRL_U "\x15"
# define KEY_UP "\x41"
# define KEY_DOWN "\x42"
# define KEY_RIGHT "\x43"
# define KEY_LEFT "\x44"
# define KEY_END "\x46"
# define KEY_HOME "\x48"
# define KEY_DEL "\x7F"

/*
**	---------------------STRUCTS----------------------
*/

typedef struct s_vec2ll
{
	long long	col;
	long long	row;	
}				t_vec2ll;

typedef struct s_reins
{
	t_vec2ll		term_cursor;
	size_t			max_col;
	size_t			max_row;

	size_t			prompt_size;
	size_t			prompt_row;

	t_vec2ll		shell_cursor;
	size_t			input_rows;

	char			table[2048];
	struct termios	termios;
	bool			enabled;

	t_vec			keys;
}					t_reins;

/*
**	--------------------GET_INPUT---------------------
*/

typedef struct s_hook
{
	void	(*function)(void *tmp);
	void	*param;
}				t_hook;

/*
**	--------------KEY_FUNCTION_PROTOTYPE--------------
*/

typedef int	(*t_keyf)(t_reins *reins, t_vec *input, char *buf, t_hook *hook);

typedef struct s_key
{
	char	buf[6];
	size_t	size;
	t_keyf	function;
	t_hook	hook;
}				t_key;

/*
**	--------------LIBreins_FUNCTIONS------------------
*/

int			reins_key(t_reins *reins, char *raw_key, t_keyf func);

/*
**	----------------------HOOKS-----------------------
*/
int			perform_action(t_reins *reins, t_vec *input, char *buf);

t_key		*new_key(char keycode[6], t_keyf f);
ssize_t		find_key(t_reins *reins, char *keycode, size_t size);
t_key		*get_key(t_reins *reins, char *keycode, size_t size);

/*
**	--------------DEFAULT_KEY_BEHAVIOUR---------------
*/
int			key_eof(t_reins *reins, t_vec *input, char *buf, t_hook *hook);
int			key_newline(t_reins *reins, t_vec *input, char *buf, t_hook *hook);
int			key_regular(t_reins *reins, t_vec *input, char *buf, t_hook *hook);
int			key_up(t_reins *reins, t_vec *input, char *buf, t_hook *hook);
int			key_down(t_reins *reins, t_vec *input, char *buf, t_hook *hook);
int			key_right(t_reins *reins, t_vec *input, char *buf, t_hook *hook);
int			key_left(t_reins *reins, t_vec *input, char *buf, t_hook *hook);
int			key_del(t_reins *reins, t_vec *input, char *buf, t_hook *hook);

/*
**	------------TERMINAL_RELATED_FUNCTIONS------------
*/

void		termcmd(char *command, int p1, int p2, int lines_affected);
void		update_cursor(t_reins *reins, int col_adjust, int row_adjust);
void		refresh_cursor(t_reins *nav);

/*
**	-----------------------UTIL-----------------------
*/
int			create_keycode(char *raw, char keycode[6]);
int			init_keys(t_reins *reins);
int			init_cursor(t_reins *reins);
void		print_keycode_formatted(char *keycode, size_t n);

int			util_atoi(char *str);
size_t		util_strlen(char *str);
void		util_bzero(void *dest, size_t n);
void		util_memcpy(void *dest, void *src, size_t n);
int			util_memcmp(void *dest, void *src, size_t n);
int			util_strncmp(char *str1, char *str2, size_t n);
char		*util_strdup(char *str);
size_t		util_strnlen(char *str, size_t n);
void		util_strncpy(char *dest, char *src, size_t n);

#endif
