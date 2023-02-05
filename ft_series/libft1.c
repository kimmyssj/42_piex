/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:12:40 by seungjki          #+#    #+#             */
/*   Updated: 2023/02/05 02:53:08 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	simillar_strchr(const char *s, char c)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == c)
			return (idx);
		idx++;
	}
	return (idx);
}

char	*simmlilar_strdup(const char *s1, int ftschr)
{
	int		idx;
	char	*result;

	idx = 0;
	result = (char *)malloc(sizeof(char) * ftschr + 1);
	if (result == NULL)
		return (NULL);
	while (idx < ftschr)
	{
		result[idx] = s1[idx];
		idx ++;
	}
	result[ftschr] = '\0';
	return (result);
}
