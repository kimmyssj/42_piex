/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:32:36 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/05 23:38:29 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	closing_duping(int zero, int one, t_pipex *p, int outfilefd)
{
	close(p->fd[zero]);
	if (zero == 0 && outfilefd == 0)
		if (dup2(p->fd[one], STDOUT_FILENO) == -1)
			error_message1(dup_failed, p->c.buff);
	if (zero == 1 && outfilefd == 0)
		if (dup2(p->fd[one], STDIN_FILENO) == -1)
			error_message1(dup_failed, p->c.buff);
	if (outfilefd != 0)
		if (dup2(outfilefd, STDOUT_FILENO) == -1)
			error_message1(dup_failed, p->c.buff);
	close(p->fd[one]);
}

void	multi_waitpid(int idx)
{
	int	idx1;

	idx1 = 0;
	while (idx1 <= idx)
	{
		waitpid(-1, 0, 0);
		idx1 ++;
	}
}

void	write_error(char *argv)
{
	write(2, "Command not found: ", 19);
	write(2, argv, ft_strlen(argv));
	write(2, "\n", 1);
	exit(0);
}

void	pipex_inside(t_c c, char **env, char **argv, int idx)
{
	t_pipex	p;

	p.c = c;
	if (pipe(p.fd) == -1)
		error_message(pipe_failed, c.buff);
	p.pid = fork();
	if (p.pid == -1)
		error_message(fork_failed, c.buff);
	else if (p.pid == 0)
	{
		if (c.infilefd == -1)
			exit(0);
		if (argv[idx + 2 + c.flag + 2] == NULL)
			closing_duping(0, 1, &p, c.outfilefd);
		else
			closing_duping(0, 1, &p, 0);
		if (c.com_path[idx + 1] == NULL)
			if (dup2(c.outfilefd, STDOUT_FILENO) == -1)
				error_message1(dup_failed, c.buff);
		execve(c.com_path[idx], ft_split(argv[idx + 2 + c.flag], ' '), env);
		write_error(argv[idx + 2 + c.flag]);
	}
	else
		closing_duping(1, 0, &p, 0);
}

void	pipex(t_c c, char **env, char **argv)
{
	int	idx;

	idx = 0;
	if (dup2(c.infilefd, STDIN_FILENO) == -1)
		error_message1(dup_failed, c.buff);
	while (c.com_path[idx + 1] != NULL)
	{
		pipex_inside(c, env, argv, idx);
		idx ++;
	}
	multi_waitpid(idx);
}
