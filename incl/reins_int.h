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
# include <bstree.h>
# include <stdbool.h>
# include <reins.h>

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

# define MOD_CTRL			(1 << 0)
# define MOD_SHIFT			(1 << 1)
# define MOD_ALT			(1 << 2)
# define MOD_META			(1 << 3)

/*
**	---------------------STRUCTS----------------------
*/

typedef struct s_trie t_trie;

# define TRIE_CHILDREN_AMOUNT 128

struct s_trie
{
	t_trie	*children[TRIE_CHILDREN_AMOUNT];
	bool	end;
	void	*val;
};

typedef struct s_vec2ll
{
	long long	col;
	long long	row;	
}				t_vec2ll;

//input object
typedef struct s_input
{
	t_vec2ll		term_cursor;
	size_t			max_col;
	size_t			max_row;

	size_t			prompt_size;
	size_t			prompt_row;

	t_vec2ll		shell_cursor;
	size_t			input_rows;

	t_vec			line;
}				t_input;

typedef struct s_reins
{
	char			table[2048];
	struct termios	termios;
	struct termios	standard;
	bool			enabled;

	t_trie			*keys;
}					t_reins;


/*
**	--------------------PREFIX TREE---------------------
*/

t_trie	*trie_new(void);
void	*trie_insert(t_trie **root, char *key, void *val);
void	*trie_find(t_trie *root, char *c, int *ret);
void	*trie_find_str(t_trie *root, char *keycode);
void	trie_destroy(t_trie *trie);

/*
**	--------------------GET_INPUT---------------------
*/


typedef struct s_hook
{
	t_hookf		function;
	void		*param;
}				t_hook;

/*
**	--------------KEY_FUNCTION_PROTOTYPE--------------
*/

typedef struct s_key
{
	char	*keycode;
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
int			perform_action(t_reins *reins, t_input *input);

t_key		*new_key(char *keycode, t_keyf f);
ssize_t		find_key(t_reins *reins, char *keycode, size_t size);
t_key		*get_key(t_reins *reins, char *keycode, size_t size);

/*
**	--------------DEFAULT_KEY_BEHAVIOUR---------------
*/
int			key_eof(t_input *input, char *buf, t_hook *hook);
int			key_newline(t_input *input, char *buf, t_hook *hook);
int			key_regular(t_input *input, char *buf, t_hook *hook);
int			key_up(t_input *input, char *buf, t_hook *hook);
int			key_down(t_input *input, char *buf, t_hook *hook);
int			key_right(t_input *input, char *buf, t_hook *hook);
int			key_left(t_input *input, char *buf, t_hook *hook);
int			key_del(t_input *input, char *buf, t_hook *hook);
int			key_home(t_input *input, char *buf, t_hook *hook);
int			key_end(t_input *input, char *buf, t_hook *hook);

/*
**	------------TERMINAL_RELATED_FUNCTIONS------------
*/

void		termcmd(char *command, int p1, int p2, int lines_affected);
void		update_cursor(t_input *reins, int col_adjust, int row_adjust);
void		refresh_cursor(t_input *input);
void		visual_add(t_input *input, char *buffer, size_t size);
void		visual_del(t_input *input, size_t size);

/*
**	-----------------------UTIL-----------------------
*/

int			error(char *msg, int error_value);

int			init_keys(t_reins *reins);
int			init_cursor(t_input *input);
void		print_keycode_formatted(char *keycode, size_t n);

int			util_atoi(char *str);
size_t		util_strlen(char *str);
void		util_bzero(void *dest, size_t n);
void		util_memcpy(void *dest, void *src, size_t n);
void		util_memset(void *dest, unsigned char value, size_t n);
int			util_memcmp(void *dest, void *src, size_t n);
int			util_strncmp(char *str1, char *str2, size_t n);
char		*util_strdup(char *str);
size_t		util_strnlen(char *str, size_t n);
void		util_strncpy(char *dest, char *src, size_t n);

#endif
