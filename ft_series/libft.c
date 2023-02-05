/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:06:18 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/30 08:25:58 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	return (idx);
}

size_t	ft_strlen1(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] && str[idx] != ' ')
		idx ++;
	return (idx);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*answer;
	size_t	idx0;
	size_t	idx1;

	answer = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen1(s2) + 1));
	if (answer == NULL)
		return (NULL);
	idx0 = 0;
	idx1 = 0;
	while (idx0 < ft_strlen(s1))
	{
		answer[idx0] = s1[idx0];
		idx0 ++;
	}
	while (idx1 < ft_strlen1(s2))
	{
		answer[idx0 + idx1] = s2[idx1];
		idx1 ++;
	}
	answer[idx0 + idx1] = '\0';
	return (answer);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (s1[idx] && s1[idx] == s2[idx] && idx < n)
		idx ++;
	if (idx == n)
		return (0);
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

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
