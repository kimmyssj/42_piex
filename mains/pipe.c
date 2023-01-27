/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:32:36 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/27 14:34:10 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	inside_pipex(t_c c, char **env, int idx, int infilefd)
{
	t_pipex	p;

	if (pipe(p.fd) == -1)
		error_message(pipe_failed);
	p.pid = fork();
	if (p.pid == -1)
		error_message(fork_failed);
	else if (p.pid == 0)
	{
		close(p.fd[0]);
		if (idx != 3)
			dup2(p.fd[1], STDOUT_FILENO);
		close(p.fd[1]);
		if (infilefd == -1)
			exit(0);
		execve(c.com_path[idx - 2], ft_split(c.argv[idx], ' '), env);
	}
	else
	{
		close(p.fd[1]);
		dup2(p.fd[0], STDIN_FILENO);
		close(p.fd[0]);
	}
}

void	pipex(t_c c, char **env)
{
	dup2(c.infilefd, STDIN_FILENO);
	inside_pipex(c, env, 2, c.infilefd);
	dup2(c.outfilefd, STDOUT_FILENO);
	inside_pipex(c, env, 3, 0);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}
