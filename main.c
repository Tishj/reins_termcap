/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 21:13:58 by tishj         #+#    #+#                 */
/*   Updated: 2021/04/06 19:29:52 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reins.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROMPT "\e[1;31mreins \e[0m\e[1;33m❯\e[0m "

void	print_up(void *yeet)
{
	(void)yeet;
	printf("UP\n");
}

void	print_a(void *yeet)
{
	(void)yeet;
	printf("\nAAAAAHHH\n");
}

int	up_function(t_input *line, char *buf, t_hook *hook)
{
	(void)line;
	(void)buf;
	(void)hook;
	reins_hook_run(hook);
	printf("\nOVERWRITTEN UP FUNCTION!\n");
	return (RD_IDLE);
}

int	insert_numbers(t_input *line, char *buf, t_hook *hook)
{
	(void)buf;
	(void)hook;
	reins_input_add(line, "123456789", 9);
	return (RD_IDLE);
}

int	insert_X(t_input *line, char *buf, t_hook *hook)
{
	(void)buf;
	(void)hook;
	reins_input_add(line, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 188);
	return (RD_IDLE);
}

int	insert_a_truckload(t_input *input, char *buf, t_hook *hook)
{
	(void)buf;
	(void)hook;
	reins_input_add(input, "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", 188);
	return (RD_IDLE);
}

int	delete_characters(t_input *input, char *buf, t_hook *hook)
{
	(void)buf;
	(void)hook;

	return (reins_input_del(input, 30));
}

int	delete_row(t_input *input, char *buf, t_hook *hook)
{
	(void)buf;
	(void)hook;

//	columns = input->max_col - (!input->shell_cursor.row * input->prompt_size);

	return (reins_input_del(input, 5));
}

int	clear_input(t_input *input, char *buf, t_hook *hook)
{
	(void)buf;
	(void)hook;
	return (reins_input_clear(input));
}

int	reins_start(t_reins **reins)
{
	*reins = reins_init();
	if (!*reins)
		return (!!printf("Failed to init reins!\n"));
	if (!reins_key(*reins, KEY_ESC "[" KEY_UP, up_function))
		return (!!printf("Failed to overwrite/add key!\n"));
	if (!reins_hook(*reins, KEY_ESC "[" KEY_UP, &print_up, NULL))
		return (!!printf("Failed to hook!\n"));
	if (!reins_key(*reins, "A", insert_a_truckload))
		return (1);
	if (!reins_key(*reins, "x", insert_X))
		return (1);
	if (!reins_key(*reins, KEY_ESC "[3~", delete_characters))
		return (1);
	if (!reins_key(*reins, KEY_CNTRL_U, clear_input))
		return (1);
	return (0);
}

int	main(void)
{
	t_reins	*reins;
	char	*line;
	int		ret;

	line = NULL;
	ret = 1;
	if (reins_start(&reins))
		return (-1);
	while (ret)
	{
		write(1, PROMPT, sizeof(PROMPT));
		ret = reins_get_input(reins, &line);
//		ret = reins_print_keycodes(reins);
		reins_disable(reins);
		printf("\nLINE: |%s|\n", line);
		free(line);
		if (ret != 1)
			break ;
	}
	reins_destroy(reins);
	if (!ret)
		return (!printf("\nexit\n"));
	else if (ret == -1)
		return (!!printf("reins_get_input failed!\n"));
	return (0);
}
