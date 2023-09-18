/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:38:14 by ihama             #+#    #+#             */
/*   Updated: 2023/09/18 18:41:27 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// rl_on_new_line  : tells that we moved to a nl
// rl_replace_line : replace the content of the rl buffer 
// rl_redisplay    : change what is on the screen with
//  the actual content of the buffer

void	display_prompt(int sig)
{
	struct termios	t;

	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		if (rl_on_new_line() == -1)
			exit(0);
		rl_redisplay();

	}
}

void	signal_handler(void)
{
	struct sigaction	sa_control_c;
	struct sigaction	sa_quit;

	sa_control_c.sa_handler = &display_prompt;
	sa_quit.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa_control_c, NULL);
	sigaction(SIGQUIT, &sa_quit, NULL);
}
