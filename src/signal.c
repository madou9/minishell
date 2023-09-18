/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:38:14 by ihama             #+#    #+#             */
/*   Updated: 2023/09/18 18:30:28 by ihama            ###   ########.fr       */
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
		rl_replace_line("", 1);
		printf("\n");
		if (rl_on_new_line() == -1)
			exit(0);
		rl_redisplay();

	}
}

void exit_handler(int sig) {
    // Handle Ctrl+D (EOF) here.
    // For example, you can gracefully exit the program.
    // Clean up resources if needed.
    printf("Received Ctrl+D %d(EOF). Exiting...\n", sig);
    exit(0); // Exit the program gracefully.
}

void	signal_handler(void)
{
	struct sigaction	sa_control_c;
	struct sigaction	sa_quit;
	struct sigaction	sa_exit;

	sa_control_c.sa_handler = &display_prompt;
	sa_quit.sa_handler = SIG_IGN; // Ignore Ctrl+\ (SIGQUIT) for now.
	sa_exit.sa_handler = &exit_handler; // Handle Ctrl+D (EOF).
	sigaction(SIGINT, &sa_control_c, NULL);
	sigaction(SIGQUIT, &sa_quit, NULL);
	sigaction(SIGQUIT, &sa_exit, NULL);
}
