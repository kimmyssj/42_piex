/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_env_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:08:13 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/27 18:01:16 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

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
	idx = -1;
	return (paths);
}

void	initialize(t_struct *i, int argc, int flag)
{
	i->answer = malloc(sizeof(char *) * (argc - 1));
	if (i->answer == 0)
		error_message(malloc_failed);
	i->answer[argc - 1] = NULL;
	i->idx = 1 + flag;
	i->idx2 = 0;
}

char	**make_comm(char **paths, char *argv[], int argc, int flag)
{
	t_struct	i;

	initialize(&i, argc, flag);
	while (argv[++i.idx + 1] != NULL)
	{
		i.idx1 = -1;
		while (paths[++i.idx1] != NULL)
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
