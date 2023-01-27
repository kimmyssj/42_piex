/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:09:38 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/27 17:59:53 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		idx;
	char	*result;

	idx = 0;
	while (s1[idx])
		idx ++;
	result = (char *)malloc(sizeof(char) * idx + 1);
	if (result == NULL)
		return (NULL);
	while (idx != -1)
	{
		result[idx] = s1[idx];
		idx --;
	}
	return (result);
}
