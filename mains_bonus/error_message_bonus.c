/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:01:30 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/06 00:25:38 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	unlinkit(char *name)
{
	if (unlink(name) == -1)
		perror("Unlink failed");
	exit(1);
}

void	error_message1(int flag, char *name)
{
	if (flag != unlink_failed && name != NULL)
		unlinkit(name);
	if (flag == open_failed)
	{
		perror("Open failed");
		exit(1);
	}
	else if (flag == open1_failed)
		perror("Open failed");
	else if (flag == dup_failed)
	{
		perror("Failed dup2");
		exit(1);
	}
	else if (flag == fork_failed)
	{
		perror("Fork failed");
		exit(1);
	}
	else
	{
		perror("Unlink failed");
		exit(1);
	}
}

void	error_message(int flag, char *name)
{
	if (name != NULL)
		unlinkit(name);
	if (flag == not_match_args)
	{
		perror("Not match args");
		exit(1);
	}
	else if (flag == malloc_failed)
	{
		perror("Malloc failed");
		exit(1);
	}
	else if (flag == not_a_valid_argument)
	{
		perror("Not a valid argument");
		exit(1);
	}
	else
	{
		perror("Pipe failed");
		exit(1);
	}
}
