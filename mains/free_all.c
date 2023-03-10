/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:54:46 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/01 19:48:05 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_double_array(char **array)
{
	int	idx;

	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		idx ++;
	}
}

void	free_all(t_c *c)
{
	free_double_array(c->com_path);
	free(c->com_path);
	if (c->paths != NULL)
	{
		free_double_array(c->paths);
		free(c->paths);
	}
}
