/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:09:13 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/03 18:29:10 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define BUFFER_SIZE 500

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

enum e_error_message
{
	not_match_args,
	malloc_failed,
	not_a_valid_argument,
	pipe_failed,
	fork_failed,
	open_failed,
	open1_failed,
	dup_failed,
	execve_failed
};

enum e_fd
{
	infile,
	outfile
};

typedef struct s_pipex
{
	int		fd[2];
	int		*status;
	pid_t	pid;
}	t_pipex;

typedef struct s_c
{
	char	**com_path;
	char	**argv;
	char	**paths;
	int		infilefd;
	int		outfilefd;
	int		flag;
}	t_c;

size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*simmlilar_strdup(const char *s1, int ftschr);
char	**ft_split_slash(char *s, char c);
char	**ft_split(char *s, char c);
void	pipex(t_c c, char **env);
void	error_message(int flag);
void	error_message1(int flag);
void	free_all(t_c *c);
int		open_file(char **argv, int flag, int argc);
int		simillar_strchr(const char *s, char c);

#endif
