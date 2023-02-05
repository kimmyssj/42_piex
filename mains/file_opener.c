/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:00:08 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/05 03:00:21 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
