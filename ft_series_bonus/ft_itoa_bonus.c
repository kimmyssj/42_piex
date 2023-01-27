/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjki <seungjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:03:51 by seungjki          #+#    #+#             */
/*   Updated: 2023/01/17 14:36:37 by seungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	itoa_maker(long long n, char *itoa_str)
{
	int			idx;
	long long	ten_num;
	long long	flag;

	idx = 0;
	ten_num = 1000000000;
	flag = n;
	if (n < 0)
	{
		n = n * -1;
		idx ++;
	}
	while (ten_num)
	{
		if (flag / ten_num)
			break ;
		ten_num = ten_num / 10;
	}
	while (ten_num > 0)
	{
		itoa_str[idx] = n / ten_num + '0';
		n = n % ten_num;
		ten_num = ten_num / 10;
		idx ++;
	}
}

char	*itoa_str_maker(long long n, int deci_numb, char *itoa_str)
{
	if (n < 0)
	{
		itoa_str = (char *)malloc(sizeof(char) * deci_numb + 2);
		if (itoa_str == NULL)
			return (NULL);
		itoa_str[0] = '-';
		itoa_str[deci_numb + 1] = '\0';
	}
	else if (n > 0)
	{
		itoa_str = (char *)malloc(sizeof(char) * deci_numb + 1);
		if (itoa_str == NULL)
			return (NULL);
		itoa_str[deci_numb] = '\0';
	}
	else
	{
		itoa_str = (char *)malloc(sizeof(char) * 2);
		if (itoa_str == NULL)
			return (NULL);
		itoa_str[0] = '0';
		itoa_str[1] = '\0';
	}
	return (itoa_str);
}

char	*ft_itoa(int n)
{
	long long	container;
	int			deci_numb;
	char		*itoa_str;

	container = n;
	deci_numb = 0;
	itoa_str = NULL;
	while (container != 0)
	{
		container = container / 10;
		deci_numb ++;
	}
	itoa_str = itoa_str_maker(n, deci_numb, itoa_str);
	if (itoa_str == NULL)
		return (NULL);
	if (n == 0)
		return (itoa_str);
	itoa_maker(n, itoa_str);
	return (itoa_str);
}
