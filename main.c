/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 21:13:58 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/09 14:20:29 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"

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

int	up_function(t_reigns* reigns, t_vec* line, char *buf, t_hook* hook)
{
	(void)line;
	(void)reigns;
	(void)buf;
	(void)hook;
	if (hook && hook->function)
		hook->function(hook->param);
	printf("\nOVERWRITTEN UP FUNCTION!\n");
	return (RD_IDLE);
}

int main(void)
{
	t_reigns	*reigns;
	char		*line;
	int			ret;

	ret = 1;
	reigns = reigns_init();
	if (!reigns)
		return (!!printf("Failed to init reigns!\n"));
	if (!reigns_key(reigns, KEY_ESC "[" KEY_UP, up_function))
		return (!!printf("Failed to overwrite/add key!\n"));
	if (!reigns_hook(reigns, KEY_ESC "[" KEY_UP, &print_up, NULL))
	 	return (!!printf("Failed to hook!\n"));
	if (!reigns_hook(reigns, "a", &print_a, NULL))
		return (!!printf("Failed to hook on \"a\"!\n"));
	while (ret)
	{
		write(1, PROMPT, sizeof(PROMPT));
		ret = reigns_get_input(reigns, &line);
		if (ret != 1)
			break ;
		printf("\nLINE: |%s|\n", line);
		free(line);
	}
	reigns_destroy(reigns);
	if (!ret)
		return (!printf("\nexit\n"));
	else if (ret == -1)
		return (!!printf("reigns_get_input failed!\n"));
	return (0);
}
