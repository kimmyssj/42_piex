/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:32:36 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/03 18:45:21 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipe_fork(t_pipex *p)
{
	if (pipe(p->fd) == -1)
		error_message(pipe_failed);
	p->pid = fork();
	if (p->pid == -1)
		error_message(fork_failed);
}

void	write_error(char *argv)
{
	write(2, "Command not found: ", 19);
	write(2, argv, ft_strlen(argv));
	write(2, "\n", 1);
}

int	inside_pipex(t_c c, char **env, int idx, int infilefd)
{
	t_pipex	p;

	pipe_fork(&p);
	if (p.pid == 0)
	{
		close(p.fd[0]);
		if (idx != 3)
			if (dup2(p.fd[1], STDOUT_FILENO) == -1)
				error_message1(dup_failed);
		close(p.fd[1]);
		if (infilefd == -1)
			exit(0);
		execve(c.com_path[idx - 2], ft_split(c.argv[idx], ' '), env);
		write_error(c.argv[idx]);
		exit(0);
	}
	else
	{
		close(p.fd[1]);
		if (dup2(p.fd[0], STDIN_FILENO) == -1)
			error_message1(dup_failed);
		close(p.fd[0]);
	}
	return (0);
}

void	pipex(t_c c, char **env)
{
	dup2(c.infilefd, STDIN_FILENO);
	inside_pipex(c, env, 2, c.infilefd);
	dup2(c.outfilefd, STDOUT_FILENO);
	write(1, "1", 1);
	inside_pipex(c, env, 3, 0);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}
