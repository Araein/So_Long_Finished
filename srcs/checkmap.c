/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:21:00 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/07/26 15:23:47 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	checksquare(t_elem *elem)
{
	int	len;
	int	i;

	i = 0;
	if (elem->map[0])
		len = ft_strlen(elem->map[0]);
	else
		return (0);
	while (i < elem->mapsize)
	{
		if ((int)ft_strlen(elem->map[i]) != len)
			return (0);
		i++;
	}
	elem->maplen = len;
	return (1);
}

int	checkmywall(int i, char *string, t_elem *elem)
{
	int	j;

	j = 0;
	if (i == 0 || i == elem->mapsize - 1)
	{
		while (j < elem->maplen)
		{
			if (string[j] != '1')
				return (0);
			j++;
		}
	}
	if (string[0] != '1' || string[elem->maplen - 1] != '1')
		return (0);
	return (1);
}

int	checkmychar(char mychar, t_elem *elem)
{
	if (mychar == 'E')
	{
		elem->counte++;
		return (1);
	}
	if (mychar == 'C')
	{
		elem->countc++;
		return (1);
	}
	if (mychar == 'P')
	{
		elem->countp++;
		return (1);
	}
	if (mychar == '1' || mychar == '0')
		return (1);
	return (0);
}

int	checkcharac(t_elem *elem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < elem->mapsize)
	{
		if (!(checkmywall(i, elem->map[i], elem)))
			return (0);
		while (j < elem->maplen)
		{
			if (!(checkmychar(elem->map[i][j], elem)))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	checkmap(t_elem *elem)
{
	if (!(checksquare(elem)))
		return (0);
	if (!(checkcharac(elem)))
		return (0);
	if (elem->countc == 0 || elem->counte == 0 || elem->countp != 1)
		return (0);
	return (1);
}
