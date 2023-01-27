/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:01:30 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/26 16:05:11 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_message1(int flag)
{
	if (flag == open_failed)
	{
		perror("Open failed");
		exit(0);
	}
	else if (flag == open1_failed)
		perror("Open failed");
	else if (flag == dup_failed)
	{
		perror("dup2 failed");
		exit(0);
	}
}

void	error_message(int flag)
{
	if (flag == not_match_args)
	{
		perror("Not match args");
		exit(0);
	}
	else if (flag == malloc_failed)
	{
		perror("Malloc failed");
		exit(0);
	}
	else if (flag == not_a_valid_argument)
	{
		perror("Not a valid argument");
		exit(0);
	}
	else if (flag == pipe_failed)
	{
		perror("Pipe failed");
		exit(0);
	}
	else if (flag == fork_failed)
	{
		perror("Fork failed");
		exit(0);
	}
}
