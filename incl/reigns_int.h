/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_int.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:44:08 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 12:01:46 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REIGNS_INT_H
# define REINGS_INT_H

# include <termios.h>
# include <stddef.h>
# include <vector.h>

//---------------------READ_STATE-----------------------------

enum	e_readstate
{
	RD_ERROR,
	RD_EOF,
	RD_SEND,
	RD_IDLE
};

//---------------------TERMINAL_COMMANDS-----------------------------

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

//-----------------------SPECIAL_CHARACTERS-------------------------------

enum		e_special
{
	KEY_CTRL_D		= 4,
	KEY_NEWLINE		= 10,
	KEY_CTRL_L		= 12,
	KEY_CTRL_U		= 21,
	KEY_ESC			= 27,
	KEY_UP			= 65,
	KEY_DOWN		= 66,
	KEY_RIGHT		= 67,
	KEY_LEFT		= 68,
	KEY_END			= 70,
	KEY_HOME		= 72,
	KEY_DEL	 		= 127,
};

//---------------------STRUCTS------------------------------

typedef struct	s_vec2sz
{
	size_t	x;
	size_t	y;	
}				t_vec2sz;

typedef struct	s_navigation
{
	t_vec2sz	dimension;
	t_vec2sz	cursor;
}				t_navigation;

typedef struct	s_input
{
	t_vec2sz		start;
	t_navigation	nav;
	t_vec			line;
}					t_input;

typedef struct		s_reigns
{
	t_input			input;
	t_navigation	nav;

	//termcap/termios related variables
	char			table[2048];
	struct termios	termios;

	//keys
	t_vec			keys;
}					t_reigns;

//-----------------------GET_INPUT-------------------------------

typedef struct	s_hook
{
	void	(*function)();
	void	*param;
}				t_hook;

//----------------------KEY_FUNCTION_PROTOTYPE--------------------------------

typedef int	(*t_keyf)(t_reigns* reigns, t_vec *input, char *buf, t_hook* hook);

typedef struct	s_key
{
	char	buf[6];
	size_t	size;
	t_keyf	function;
	t_hook	hook;
}				t_key;

//----------------------LIBREIGNS FUNCTIONS---------------------------------

int			reigns_key(t_reigns* reigns, char keycode[6], t_keyf func);


//----------------------HOOKS-------------------------------

int	perform_action(t_reigns* reigns, t_vec* input, char *buf);

t_key		*new_key(char keycode[6], t_keyf f);
ssize_t		find_key(t_reigns* reigns, char *keycode, size_t size);
t_key		*get_key(t_reigns* reigns, char *keycode, size_t size);

//----------------------------DEFAULT KEY BEHAVIOR------------------------

int	key_eof(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook);
int	key_newline(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook);
int	key_regular(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook);
int	key_up(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook);
int	key_down(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook);
int	key_right(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook);
int	key_left(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook);
int	key_del(t_reigns* reigns, t_vec* input, char *buf, t_hook* hook);

//-----------------------TERMINAL RELATED FUNCTIONS-------------------------------

void		termcmd(char *command, int p1, int p2, int lines_affected);
void		update_cursor(t_reigns* reigns, int col_adjust, int row_adjust);
void		refresh_cursor(t_navigation* nav);

//-----------------------UTIL-------------------------------

int			init_keys(t_reigns* reigns);

int			util_atoi(const char *str);
size_t		util_strlen(char *str);
void		util_bzero(void *dest, size_t n);
void		util_memcpy(void *dest, void *src, size_t n);
int			util_memcmp(void *dest, void *src, size_t n);
int			util_strncmp(char *str1, char *str2, size_t n);
char		*util_strdup(char *str);
size_t		util_strnlen(char *str, size_t n);

#endif
