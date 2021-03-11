/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_signal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 23:27:52 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/11 00:47:03 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <signal.h>

// sighandler_t	reins_signal(t_reins *reins, int signum, sighandler_t handler)
// {
// 	sighandler_t	ret;
// 	t_signal		sighandler;

// 	ret = signal(signum, handler);
// 	if (ret == SIG_ERR)
// 		return (ret);
// 	sighandler.signum = signum;
// 	sighandler.handler = handler;
// 	if (!vec_add(&reins->sighandlers, &sighandler))
// 		return (SIG_ERR);
// 	return (ret);
// }
