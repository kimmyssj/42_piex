/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:09:13 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/06 00:28:28 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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
	too_few_args,
	buff_exist,
	dup_failed,
	unlink_failed,
	outfile
};

enum e_fd
{
	here_docs,
	none
};

typedef struct s_gnl
{
	char	*str;
	char	buff[BUFFER_SIZE + 1];
	int		endl;
	int		size;
	char	*ret;
}	t_gnl;

typedef struct s_hd
{
	char	*buff;
	char	*buff1;
	char	*name;
	int		idx;
}	t_hd;

typedef struct s_struct
{
	int		idx;
	int		idx1;
	int		idx2;
	char	**answer;
}	t_struct;

typedef struct s_c
{
	char	**com_path;
	char	**paths;
	char	*buff;
	int		infilefd;
	int		outfilefd;
	int		flag;
}	t_c;

typedef struct s_pipex
{
	int		fd[2];
	int		*status;
	pid_t	pid;
	t_c		c;
}	t_pipex;

int		ft_strncmp1(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *str);
int		indexof(char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		simillar_strchr(const char *s, char c);
char	*simmlilar_strdup(const char *s1, int ftschr);
char	**give_paths(char *env[], t_c c);
char	**make_comm(char **paths, char *argv[], int argc, t_c c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split_slash(char *s, char c);
char	**ft_split(char *s, char c);
void	pipex(t_c c, char **env, char **argv);
void	error_message(int flag, char *name);
void	error_message1(int flag, char *name);
void	free_all(t_c *c);

#endif
