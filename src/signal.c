/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:38:14 by ihama             #+#    #+#             */
/*   Updated: 2023/09/18 14:36:37 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// rl_on_new_line  : tells that we moved to a nl
// rl_replace_line : replace the content of the rl buffer 
// rl_redisplay    : change what is on the screen with
//  the actual content of the buffer

void	display_prompt(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 1);
		ft_putendl_fd("", STDOUT_FILENO);
		if (rl_on_new_line() == -1)
			exit(0);
		rl_redisplay();

	}
}

void	signal_handler(void)
{
	struct sigaction	sa_control_c;

	sa_control_c.sa_handler = &display_prompt;
	sigaction(SIGINT, &sa_control_c, NULL);
}
