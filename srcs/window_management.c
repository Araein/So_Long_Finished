/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:50:22 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 17:24:58 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	putassets(t_elem *elem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	elem->y = 0;
	elem->x = 0;
	while (elem->map[i])
	{
		while (elem->map[i][j])
		{
			putscreen(i, j, elem);
			elem->x += 55;
			j++;
		}
		elem->x = 0;
		elem->y += 55;
		j = 0;
		i++;
	}
	return (1);
}

int	zeroimage(t_elem *elem, int type)
{
	if (type == 1)
	{
		mlx_clear_window (elem->mlxptr, elem->windowptr);
		mlx_destroy_window (elem->mlxptr, elem->windowptr);
		elem->error = 4;
		freetab(elem->map, elem);
		mlx_destroy_display(elem->mlxptr);
		free(elem->mlxptr);
	}
	if (type == 2)
	{
		freetab(elem->map, elem);
		mlx_destroy_display(elem->mlxptr);
		free(elem->mlxptr);
	}
	if (type == 3)
	{
		elem->error = 3;
		freetab(elem->map, elem);
		mlx_destroy_display(elem->mlxptr);
		free(elem->mlxptr);
	}
	if (type == 4)
		freetab(elem->map, elem);
	return (0);
}

int	windowinit(t_elem *elem)
{
	char	*tempo;

	elem->mlxptr = mlx_init();
	if (elem->mlxptr == NULL)
		return (zeroimage(elem, 4));
	mlx_get_screen_size(elem->mlxptr, &elem->screenx, &elem->screeny);
	if ((55 * elem->mapsize) >= elem->screeny || (55 * elem->maplen)
		>= elem->screenx)
		return (zeroimage(elem, 3));
	elem->windowptr = mlx_new_window(elem->mlxptr, 55 * elem->maplen,
			55 * elem->mapsize, "so_long");
	if (elem->windowptr == NULL)
		return (zeroimage(elem, 2));
	if (putimage(elem) == 0)
		return (zeroimage(elem, 1));
	ft_putstr("\nNumber of moves : ");
	tempo = ft_itoa(elem->playermove);
	ft_putstr(tempo);
	free(tempo);
	tempo = NULL;
	ft_putstr("\n");
	mlx_hook(elem->windowptr, 2, 1l << 0, key_hook, elem);
	mlx_hook(elem->windowptr, 33, 1L << 5, shutwindow, elem);
	mlx_loop(elem->mlxptr);
	return (1);
}
