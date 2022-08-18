/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:52:31 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 17:29:16 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	baba_animation2(t_elem *elem)
{
	if (elem->count == 250 || elem->count == 750 || elem->count == 1250)
	{
		if (checkxpm1(elem) == 0)
		{
			ft_putstr_fd("\nError with your .xpm files !\n", 2);
			shutwindow(elem);
		}
		mlx_destroy_image (elem->mlxptr, elem->baba);
		elem->baba = mlx_xpm_file_to_image (elem->mlxptr, BABA1,
				&elem->mapsize, &elem->maplen);
		putassets(elem);
	}
}

void	baba_animation(t_elem *elem)
{
	if (elem->count == 0 || elem->count == 1000)
	{
		if (checkxpm(elem) == 0)
		{
			ft_putstr_fd("\nError with your .xpm files !\n", 2);
			shutwindow(elem);
		}
		mlx_destroy_image (elem->mlxptr, elem->baba);
		elem->baba = mlx_xpm_file_to_image (elem->mlxptr, BABA,
				&elem->mapsize, &elem->maplen);
		putassets(elem);
	}
	if (elem->count == 500 || elem->count == 1500)
	{
		if (checkxpm(elem) == 0)
		{
			ft_putstr_fd("\nError with your .xpm files !\n", 2);
			shutwindow(elem);
		}
		mlx_destroy_image (elem->mlxptr, elem->baba);
		elem->baba = mlx_xpm_file_to_image (elem->mlxptr, BABA2,
				&elem->mapsize, &elem->maplen);
		putassets(elem);
	}
}

void	map_animation_zero(t_elem *elem)
{
	if (elem->count == 0)
	{
		mlx_destroy_image (elem->mlxptr, elem->rock);
		mlx_destroy_image (elem->mlxptr, elem->door);
		mlx_destroy_image (elem->mlxptr, elem->key);
		elem->rock = mlx_xpm_file_to_image (elem->mlxptr, ROCK,
				&elem->mapsize, &elem->maplen);
		elem->key = mlx_xpm_file_to_image (elem->mlxptr, KEY,
				&elem->mapsize, &elem->maplen);
		elem->door = mlx_xpm_file_to_image (elem->mlxptr, DOOR,
				&elem->mapsize, &elem->maplen);
		putassets(elem);
	}
}

void	map_animation(t_elem *elem)
{
	map_animation_zero(elem);
	if (elem->count == 500)
	{
		mlx_destroy_image (elem->mlxptr, elem->rock);
		mlx_destroy_image (elem->mlxptr, elem->door);
		mlx_destroy_image (elem->mlxptr, elem->key);
		elem->rock = mlx_xpm_file_to_image (elem->mlxptr, ROCK1,
				&elem->mapsize, &elem->maplen);
		elem->key = mlx_xpm_file_to_image (elem->mlxptr, KEY1,
				&elem->mapsize, &elem->maplen);
		elem->door = mlx_xpm_file_to_image (elem->mlxptr, DOOR1,
				&elem->mapsize, &elem->maplen);
		putassets(elem);
	}
}

int	ft_animations(t_elem *elem)
{
	baba_animation(elem);
	map_animation(elem);
	if (elem->count == 1000)
	{
		mlx_destroy_image (elem->mlxptr, elem->rock);
		mlx_destroy_image (elem->mlxptr, elem->door);
		mlx_destroy_image (elem->mlxptr, elem->key);
		elem->rock = mlx_xpm_file_to_image (elem->mlxptr, ROCK2,
				&elem->mapsize, &elem->maplen);
		elem->key = mlx_xpm_file_to_image (elem->mlxptr, KEY2,
				&elem->mapsize, &elem->maplen);
		elem->door = mlx_xpm_file_to_image (elem->mlxptr, DOOR2,
				&elem->mapsize, &elem->maplen);
		putassets(elem);
	}
	if (elem->count == 1750)
		elem->count = 0;
	else if (elem->duo == 50)
	{
		elem->count++;
		elem->duo = 0;
	}
	else
		elem->duo++;
	return (1);
}
