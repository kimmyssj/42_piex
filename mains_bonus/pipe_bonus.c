/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:32:36 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/29 15:49:29 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	closing_duping(int zero, int one, t_pipex *p)
{
	close(p->fd[zero]);
	if (zero == 0)
		if (dup2(p->fd[one], STDOUT_FILENO) == -1)
			error_message1(dup_failed);
	if (zero == 1)
		if (dup2(p->fd[one], STDIN_FILENO) == -1)
			error_message1(dup_failed);
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

void	pipex_inside(t_c c, char **env, char **argv, int idx)
{
	t_pipex	p;

	if (pipe(p.fd) == -1)
		error_message(pipe_failed);
	p.pid = fork();
	if (p.pid == -1)
		error_message(fork_failed);
	else if (p.pid == 0)
	{
		if (idx == 0 && c.infilefd == -1)
			exit(0);
		closing_duping(0, 1, &p);
		if (c.com_path[idx + 1] == NULL)
			if (dup2(c.outfilefd, STDOUT_FILENO) == -1)
				error_message1(dup_failed);
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
			execve(c.com_path[idx], ft_split(argv[idx + 3], ' '), env);
		execve(c.com_path[idx], ft_split(argv[idx + 2], ' '), env);
	}
	else
	{
		closing_duping(1, 0, &p);
		if (c.com_path[idx + 1] == NULL)
			multi_waitpid(idx);
	}
}

void	pipex(t_c c, char **env, char **argv)
{
	int	idx;

	idx = 0;
	dup2(c.infilefd, STDIN_FILENO);
	while (c.com_path[idx] != NULL)
	{
		pipex_inside(c, env, argv, idx);
		idx ++;
	}
	if (unlink(c.buff) == -1)
		error_message1(unlink_failed);
}
