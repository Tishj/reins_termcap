/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reigns_get_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:04:02 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 00:41:25 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <unistd.h>
#include <vector.h>
#include <stdio.h>

int		reigns_get_input(t_reigns* reigns, char **line)
{
	t_vec				input;
	char				buf[6];
	int	state;

	vec_new(&input, sizeof(char));
	while (1)
	{
		util_bzero(buf, 6);
		read(STDIN_FILENO, buf, 6);
		state = perform_action(reigns, &input, buf);
		if (state != RD_IDLE)
			break ;
	}
	if (state == RD_ERROR)
		return (-!!dprintf(2, "error state!\n"));
	buf[0] = '\0';
	if (!vec_add(&input, buf))
		return (-!!dprintf(2, "failed to null-terminate!\n"));
	*line = util_strdup(input.store);
	if (!*line)
		return (-!!dprintf(2, "strdup failed!\n"));
	return ((state == RD_EOF) ? 0 : 1);
}
