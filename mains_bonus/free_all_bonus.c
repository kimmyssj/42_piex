/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:52:19 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/27 15:56:03 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_double_array(char ***array)
{
	int	idx;

	idx = 0;
	while (array[0][idx])
	{
		free(array[0][idx]);
		idx ++;
	}
	free(*array);
}

void	free_all(t_c *c)
{
	free_double_array(&c->paths);
	free_double_array(&c->com_path);
	if (c->buff != NULL)
		free(c->buff);
}
