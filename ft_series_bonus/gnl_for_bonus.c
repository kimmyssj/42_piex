/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_for_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 06:09:04 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/16 14:29:05 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"
#include <unistd.h>
#include <stdbool.h>

char	*concat_size(char *dst, char *src, int src_size)
{
	int		len;
	char	*ret;
	int		idx;

	len = src_size;
	if (dst)
		len += ft_strlen(dst);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = 0;
	len = -1;
	if (dst)
		while (dst[++len])
			ret[len] = dst[len];
	idx = -1;
	if (len == -1)
		len = 0;
	while (++idx < src_size)
		ret[len + idx] = src[idx];
	free(dst);
	return (ret);
}

void	read_loop(t_gnl *gnl, int fd)
{
	while (true)
	{
		gnl->buff[gnl->size] = 0;
		gnl->str = concat_size(gnl->str, gnl->buff, gnl->size);
		gnl->endl = indexof(gnl->str, '\n');
		if (gnl->endl != -1)
			break ;
		gnl->size = read(fd, gnl->buff, BUFFER_SIZE);
		if (gnl->size <= 0)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*last;
	t_gnl		gnl;

	gnl.str = last;
	last = NULL;
	gnl.ret = NULL;
	gnl.size = 0;
	read_loop(&gnl, fd);
	gnl.size = ft_strlen(gnl.str);
	if (gnl.endl++ == -1)
		gnl.endl = gnl.size;
	else
		last = concat_size(NULL, gnl.str + gnl.endl,
				ft_strlen(gnl.str + gnl.endl));
	if (gnl.endl)
		gnl.ret = concat_size(NULL, gnl.str, gnl.endl);
	free(gnl.str);
	return (gnl.ret);
}
