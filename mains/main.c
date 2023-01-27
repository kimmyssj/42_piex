/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:07:44 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/27 14:42:58 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**give_paths(char *env[])
{
	char	**paths;
	int		idx;

	idx = 0;
	while (ft_strncmp("PATH=", env[idx], 5) != 0)
			idx ++;
	paths = ft_split_slash(env[idx] + 5, ':');
	if (paths == 0)
		error_message(malloc_failed);
	return (paths);
}

void	initialize(t_struct *i, int argc)
{
	i->answer = malloc(sizeof(char *) * (argc - 1));
	if (i->answer == 0)
		error_message(malloc_failed);
	i->answer[argc - 1] = NULL;
	i->idx = 1;
	i->idx2 = 0;
}

char	**make_comm(char **paths, char *argv[], int argc)
{
	t_struct	i;

	initialize(&i, argc);
	while (argv[++i.idx + 1] != NULL)
	{
		i.idx1 = -1;
		while (paths[++i.idx1 + 1] != NULL)
		{
			i.answer[i.idx2] = ft_strjoin(paths[i.idx1], argv[i.idx]);
			if (i.answer[i.idx2] == NULL)
				error_message(malloc_failed);
			if (access(i.answer[i.idx2], F_OK) == 0)
				break ;
			free(i.answer[i.idx2]);
			i.answer[i.idx2] = NULL;
		}
		if (paths[i.idx1] == NULL || i.answer[i.idx2] == NULL)
			error_message(not_a_valid_argument);
		i.idx2 ++;
	}
	return (i.answer);
}

int	open_file(char **argv, int flag, int argc)
{
	int	answer;

	if (flag == infile)
	{
		answer = open(argv[1], O_RDONLY);
		if (answer == -1)
		{
			error_message1(open1_failed);
			return (answer);
		}
	}
	else
	{
		answer = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (answer == -1)
			error_message1(open_failed);
	}
	return (answer);
}

int	main(int argc, char *argv[], char *env[])
{
	t_c		c;

	if (argc != 5)
		error_message(not_match_args);
	c.paths = give_paths(env);
	c.com_path = make_comm(c.paths, argv, argc);
	c.argv = argv;
	c.infilefd = open_file(argv, infile, argc);
	c.outfilefd = open_file(argv, outfile, argc);
	pipex(c, env);
	free_all(c);
	free(c.paths);
	free(c.com_path);
}
