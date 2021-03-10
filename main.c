/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 21:13:58 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 15:03:13 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reins.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROMPT "yeet >$ "

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

int	up_function(t_reins *reins, t_vec *line, char *buf, t_hook *hook)
{
	(void)line;
	(void)reins;
	(void)buf;
	(void)hook;
	if (hook && hook->function)
		hook->function(hook->param);
	printf("\nOVERWRITTEN UP FUNCTION!\n");
	return (RD_IDLE);
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
	return (0);
}

int	main(void)
{
	t_reins	*reins;
	char	*line;
	int		ret;

	ret = 1;
	if (reins_start(&reins))
		return (-1);
	while (ret)
	{
		write(1, PROMPT, sizeof(PROMPT));
		ret = reins_get_input(reins, &line);
		if (ret != 1)
			break ;
		printf("\nLINE: |%s|\n", line);
		free(line);
	}
	reins_destroy(reins);
	if (!ret)
		return (!printf("\nexit\n"));
	else if (ret == -1)
		return (!!printf("reins_get_input failed!\n"));
	return (0);
}
