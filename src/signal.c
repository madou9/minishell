/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:22:38 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/20 02:24:23 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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
		rl_on_new_line();
		rl_redisplay();
		g_error_code = 1;
	}
}

void	child_signal_process(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	g_error_code = 130;
}

void	quit_child_signal(int sig)
{
	(void)sig;
	printf("\nQuit: 3\n");
	g_error_code = 131;
}

void	signal_handler(int main)
{
	struct sigaction	sa_control_c;
	struct sigaction	sa_quit;

	if (main == 1)
	{
		sa_control_c.sa_handler = &display_prompt;
		sigaction(SIGINT, &sa_control_c, NULL);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		sa_quit.sa_handler = child_signal_process;
		sigaction(SIGINT, &sa_quit, NULL);
		signal(SIGQUIT, &quit_child_signal);
	}
}
