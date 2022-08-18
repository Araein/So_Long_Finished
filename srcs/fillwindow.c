/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillwindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:11 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 17:16:33 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	canbabamove(t_elem *elem)
{
	if (elem->map[elem->destination[1]][elem->destination[0]] == '1')
		return (0);
	if (elem->map[elem->destination[1]][elem->destination[0]] == 'C')
		--elem->countc;
	if (elem->map[elem->destination[1]][elem->destination[0]] == 'E'
		&& elem->countc > 0)
		return (0);
	return (1);
}

void	putscreen(int i, int j, t_elem *elem)
{
	if (elem->map[i][j] == 'P')
	{
		mlx_put_image_to_window (elem->mlxptr, elem->windowptr,
			elem->baba, elem->x, elem->y);
		elem->babapos[0] = j;
		elem->babapos[1] = i;
	}
	if (elem->map[i][j] == 'C')
		mlx_put_image_to_window (elem->mlxptr, elem->windowptr,
			elem->key, elem->x, elem->y);
	if (elem->map[i][j] == 'E')
		mlx_put_image_to_window (elem->mlxptr, elem->windowptr,
			elem->door, elem->x, elem->y);
	if (elem->map[i][j] == '1')
		mlx_put_image_to_window (elem->mlxptr, elem->windowptr,
			elem->rock, elem->x, elem->y);
}

int	key_hook(int keycode, t_elem *elem)
{
	if (keycode == FORWARD)
		babamoveup(elem);
	if (keycode == BACK)
		babamovedown(elem);
	if (keycode == LEFT)
		babamoveleft(elem);
	if (keycode == RIGHT)
		babamoveright(elem);
	if (keycode == 65307)
	{
		mlx_destroy_image (elem->mlxptr, elem->baba);
		mlx_destroy_image (elem->mlxptr, elem->key);
		mlx_destroy_image (elem->mlxptr, elem->door);
		mlx_destroy_image (elem->mlxptr, elem->rock);
		mlx_clear_window (elem->mlxptr, elem->windowptr);
		mlx_destroy_window (elem->mlxptr, elem->windowptr);
		freetab(elem->map, elem);
		mlx_destroy_display(elem->mlxptr);
		free(elem->mlxptr);
		ft_putstr_fd("Goodbye !\n", 1);
		exit(1);
	}
	return (0);
}

int	putimage(t_elem *elem)
{
	int	size1;
	int	size2;

	size1 = elem->mapsize;
	size2 = elem->maplen;
	elem->baba = mlx_xpm_file_to_image (elem->mlxptr, BABA, &size1, &size2);
	if (elem->baba == 0)
		return (0);
	elem->key = mlx_xpm_file_to_image (elem->mlxptr, KEY, &size1, &size2);
	if (elem->key == 0)
	{
		mlx_destroy_image (elem->mlxptr, elem->baba);
		return (0);
	}
	elem->door = mlx_xpm_file_to_image (elem->mlxptr, DOOR, &size1, &size2);
	if (elem->key == 0)
		return (errorxpm(elem, 2));
	elem->rock = mlx_xpm_file_to_image (elem->mlxptr, ROCK, &size1, &size2);
	if (elem->rock == (void *)0)
		return (errorxpm(elem, 3));
	if (putassets(elem) == 0)
		return (0);
	return (1);
}
