/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:52:19 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/06 00:28:24 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_double_array(char **array)
{
	int	idx;

	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		idx ++;
	}
	free(array);
}

void	free_all(t_c *c)
{
	if (c->paths != NULL)
		free_double_array(c->paths);
	free_double_array(c->com_path);
	close(c->infilefd);
	close(c->outfilefd);
	if (c->buff != NULL)
	{
		if (unlink(c->buff) == -1)
			error_message1(unlink_failed, c->buff);
		free(c->buff);
	}
}
