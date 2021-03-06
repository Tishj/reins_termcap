/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 13:00:43 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 19:18:13 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REIGNS_H
# define REIGNS_H

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
	t_navigation	nav;
	t_input			input;

	//termcap/termios related variables
	char			table[2048];
	struct termios	termios;
}					t_reigns;

typedef int	(*t_actionf)(t_reigns* reigns, t_vec *input, char *buf);

//-----------------------PROTOTYPES-------------------------------

t_reigns	*reigns_init();
int			reigns_get_input(t_reigns* reigns, char **line);
void		reigns_destroy(t_reigns* reigns);
//reigns_enable //<- raw
//reigns_disable //<- standard

//-----------------------GET_INPUT-------------------------------

int	perform_action(t_reigns* reigns, t_vec* input, char *buf);

int	key_eof(t_reigns* reigns, t_vec* input, char *buf);
int	key_newline(t_reigns* reigns, t_vec* input, char *buf);
int	key_regular(t_reigns* reigns, t_vec* input, char *buf);
int	key_up(t_reigns* reigns, t_vec* input, char *buf);
int	key_down(t_reigns* reigns, t_vec* input, char *buf);
int	key_right(t_reigns* reigns, t_vec* input, char *buf);
int	key_left(t_reigns* reigns, t_vec* input, char *buf);
int	key_del(t_reigns* reigns, t_vec* input, char *buf);

//-----------------------UTIL-------------------------------

void		termcmd(char *command, int p1, int p2, int lines_affected);
void		update_cursor(t_reigns* reigns, int col_adjust, int row_adjust);
void		refresh_cursor(t_navigation* nav);

int			util_atoi(const char *str);
size_t		util_strlen(char *str);
void		util_bzero(void *dest, size_t n);
void		util_memcpy(void *dest, void *src, size_t n);
char		*util_strdup(char *str);

#endif
