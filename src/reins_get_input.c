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

int		reins_get_input(t_reins* reins, char **line)
{
	t_vec				input;
	char				buf[6];
	int					state;

	if (!init_cursor(reins))
		return (-1);
	vec_new(&input, sizeof(char));
	while (1)
	{
		util_bzero(buf, 6);
		read(STDIN_FILENO, buf, 6);
//		printf("BUF[%d][%d][%d][%d][%d][%d]\n", (int)buf[0], (int)buf[1], (int)buf[2], (int)buf[3], (int)buf[4], (int)buf[5]);
		state = perform_action(reins, &input, buf);
		if (state != RD_IDLE)
			break ;
		refresh_cursor(reins);
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
