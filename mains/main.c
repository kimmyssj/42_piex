/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:07:44 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/05 03:01:11 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**give_paths(char *env[])
{
	char	**paths;
	int		idx;

	idx = 0;
	while (ft_strncmp("PATH=", env[idx], 5) != 0)
	{
		idx ++;
		if (env[idx] == NULL)
			return (NULL);
	}
	paths = ft_split_slash(env[idx] + 5, ':');
	if (paths == 0)
		error_message(malloc_failed);
	return (paths);
}

char	*make_comm(char **paths, char *argv)
{
	int		idx;
	char	*answer;

	idx = -1;
	while (paths != NULL && paths[++idx] != NULL)
	{
		answer = ft_strjoin(paths[idx], argv);
		if (answer == NULL)
			error_message(malloc_failed);
		if (access(answer, X_OK) == 0)
			return (answer);
		free(answer);
	}
	answer = ft_strdup(argv);
	if (answer == NULL)
		error_message(malloc_failed);
	return (answer);
}

char	*for_abs_path(char *abs_path)
{
	char	*answer;

	answer = simmlilar_strdup(rel_path, simillar_strchr(rel_path, ' '));
	if (answer == NULL)
		error_message(malloc_failed);
	return (answer);
}

int	main(int argc, char *argv[], char *env[])
{
	t_c		c;
	int		idx;

	idx = -1;
	if (argc != 5)
		error_message(not_match_args);
	c.paths = give_paths(env);
	c.com_path = malloc(sizeof(char *) * 3);
	if (c.com_path == NULL)
		error_message(malloc_failed);
	c.com_path[2] = NULL;
	while (++idx < 2)
	{
		if (argv[idx + 2][0] != '/' && c.paths != NULL)
			c.com_path[idx] = make_comm(c.paths, argv[idx + 2]);
		else
			c.com_path[idx] = for_abs_path(argv[idx + 2]);
		if (c.com_path[idx] == NULL)
			error_message(malloc_failed);
	}
	c.argv = argv;
	c.infilefd = open_file(argv, infile, argc);
	c.outfilefd = open_file(argv, outfile, argc);
	pipex(c, env);
	free_all(&c);
}
