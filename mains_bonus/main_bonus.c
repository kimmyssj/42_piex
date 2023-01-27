/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:07:44 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/27 18:12:12 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	initialize_initialize(t_hd *h)
{
	h->idx = 0;
	h->buff = malloc(sizeof(char));
	if (h->buff == NULL)
		error_message(malloc_failed);
	h->buff[0] = '\0';
}

char	*initialize_here_doc(int *fd)
{
	t_hd	h;

	initialize_initialize(&h);
	while (1)
	{
		if (h.buff == NULL)
			error_message(malloc_failed);
		h.name = ft_strjoin(h.buff, "1");
		if (h.name == NULL)
			error_message(malloc_failed);
		*fd = open(h.name, O_RDWR | O_APPEND | O_CREAT, 0777);
		if (*fd != -1)
			break ;
		free(h.name);
		h.buff1 = ft_strdup(h.buff);
		if (h.buff1 == NULL)
			error_message(malloc_failed);
		free(h.buff);
		h.buff = ft_strjoin(h.buff1, "1");
		free(h.buff1);
	}
	free(h.buff);
	return (h.name);
}

char	*here_doc(char *argv[], t_c *c)
{
	char	*str;
	char	*name;

	name = initialize_here_doc(&c->infilefd);
	while (1)
	{
		write(1, "heredoc> ", 9);
		str = get_next_line(0);
		if (str == NULL)
			error_message(malloc_failed);
		if (ft_strncmp1(str, argv[2], ft_strlen(argv[2])) == 0)
			break ;
		write(c->infilefd, str, ft_strlen(str));
		free(str);
	}
	free(str);
	return (name);
}

void	open_file(char **argv, int flag, int argc, t_c *c)
{
	if (flag == none)
	{
		c->infilefd = open(argv[1], O_RDONLY);
		if (c->infilefd == -1)
			error_message1(open1_failed);
		c->outfilefd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (c->outfilefd == -1)
			error_message1(open_failed);
	}
	else
	{
		c->outfilefd = open(argv[argc - 1],
				O_WRONLY | O_APPEND | O_CREAT, 0777);
		if (c->outfilefd == -1)
			error_message1(open_failed);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_c		c;

	c.buff = NULL;
	c.flag = 0;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		c.flag = 1;
	if (ft_strncmp(argv[1], "here_doc", 9) != 0 && argc < 5)
		error_message(not_match_args);
	else if (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 6)
		error_message(not_match_args);
	c.paths = give_paths(env);
	c.com_path = make_comm(c.paths, argv, argc, c.flag);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		c.buff = here_doc(argv, &c);
		if (c.buff == NULL)
			error_message(malloc_failed);
		open_file(argv, here_docs, argc, &c);
	}
	else
		open_file(argv, none, argc, &c);
	if (c.outfilefd == -1)
		error_message1(open_failed);
	pipex(c, env, argv);
	free_all(&c);
}
