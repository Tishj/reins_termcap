/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_get_input.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:04:02 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/10 11:50:44 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <vector.h>
#include <stdio.h>
#include <termcap.h>
#include <reins_int.h>
#include <reins.h>

int	reins_get_input(t_reins *reins, char **line)
{
	t_input				input;
	char				buf[6];
	int					state;

	if (!reins_enable(reins) || !init_cursor(&input))
		return (-1);
	vec_new(&input.line, sizeof(char));
	while (1)
	{
		util_bzero(buf, 6);
		read(STDIN_FILENO, buf, 6);
		state = perform_action(reins, &input, buf);
		refresh_cursor(&input);
		if (state != RD_IDLE)
			break ;
	}
	if (state == RD_ERROR)
		return (- !!dprintf(2, "error state!\n"));
	if (!vec_add(&input.line, "", 1))
		return (- !!dprintf(2, "failed to null-terminate!\n"));
	*line = util_strdup(input.line.store);
	if (!*line)
		return (- !!dprintf(2, "strdup failed!\n"));
	vec_destroy(&input.line, NULL);
	return ((state != RD_EOF));
}
