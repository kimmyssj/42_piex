/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_env_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:08:13 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/05 23:17:46 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	**give_paths(char *env[], t_c c)
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
	if (env[idx] == NULL)
		return (NULL);
	paths = ft_split_slash(env[idx] + 5, ':');
	if (paths == NULL)
		error_message(malloc_failed, c.buff);
	return (paths);
}

char	*for_null(char *argv, t_c c)
{
	char	*answer;

	answer = ft_strdup(argv);
	if (answer == NULL)
		error_message(malloc_failed, c.buff);
	return (answer);
}

char	*for_command(char **paths, char *argv, t_c c)
{
	int		idx;
	char	*answer;

	idx = 0;
	if (paths == NULL)
		return (for_null(argv, c));
	while (paths[idx] != NULL)
	{
		answer = ft_strjoin(paths[idx], argv);
		if (answer == NULL)
			error_message(malloc_failed, c.buff);
		if (access(answer, X_OK) == 0)
			break ;
		free(answer);
		answer = NULL;
		idx ++;
	}
	if (paths[idx] == NULL)
		return (for_null(argv, c));
	return (answer);
}

char	*for_abs_path(char *abs_path, t_c c)
{
	char	*answer;

	answer = simmlilar_strdup(abs_path, simillar_strchr(abs_path, ' '));
	if (answer == NULL)
		error_message(malloc_failed, c.buff);
	return (answer);
}

char	**make_comm(char **paths, char *argv[], int argc, t_c c)
{
	int		idx;
	char	**answer;

	answer = malloc(sizeof(char *) * argc - c.flag - 2);
	if (answer == NULL)
		error_message(malloc_failed, c.buff);
	idx = 0;
	while (idx < argc - 2 - c.flag)
	{
		if (argv[idx + 2 + c.flag][0] == '/')
			answer[idx] = for_abs_path(argv[idx + 2 + c.flag], c);
		else
			answer[idx] = for_command(paths, argv[idx + 2 + c.flag], c);
		idx ++;
	}
	answer[idx] = NULL;
	return (answer);
}
