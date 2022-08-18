/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:52:25 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 17:29:31 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	checkxpm4(t_elem *elem)
{
	void	*test;

	test = mlx_xpm_file_to_image (elem->mlxptr, ROCK,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	test = mlx_xpm_file_to_image (elem->mlxptr, ROCK1,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	test = mlx_xpm_file_to_image (elem->mlxptr, ROCK2,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	return (1);
}

int	checkxpm3(t_elem *elem)
{
	void	*test;

	test = mlx_xpm_file_to_image (elem->mlxptr, KEY,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	test = mlx_xpm_file_to_image (elem->mlxptr, KEY1,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	test = mlx_xpm_file_to_image (elem->mlxptr, KEY2,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	return (1);
}

int	checkxpm2(t_elem *elem)
{
	void	*test;

	test = mlx_xpm_file_to_image (elem->mlxptr, DOOR,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	test = mlx_xpm_file_to_image (elem->mlxptr, DOOR1,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	test = mlx_xpm_file_to_image (elem->mlxptr, DOOR2,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	return (1);
}

int	checkxpm1(t_elem *elem)
{
	void	*test;

	test = mlx_xpm_file_to_image (elem->mlxptr, BABA,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	test = mlx_xpm_file_to_image (elem->mlxptr, BABA1,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	test = mlx_xpm_file_to_image (elem->mlxptr, BABA2,
			&elem->mapsize, &elem->maplen);
	if (test == (void *)0)
		return (0);
	else
		mlx_destroy_image (elem->mlxptr, test);
	return (1);
}

int	checkxpm(t_elem *elem)
{
	if (checkxpm1(elem) == 0 || checkxpm2(elem) == 0)
		return (0);
	if (checkxpm3(elem) == 0 || checkxpm4(elem) == 0)
		return (0);
	return (1);
}
