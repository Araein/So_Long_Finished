/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:52:25 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 14:06:49 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	counter(t_elem *elem)
{
	char	*tempostring;

	tempostring = ft_itoa(elem->playermove);
	if (tempostring == NULL)
	{
		error(2, elem);
		return (0);
	}
	mlx_string_put (elem->mlxptr, elem->windowptr, 22, 22, 555, tempostring);
	free(tempostring);
	return (1);
}

int	putassets(t_elem *elem)
{
	int		i;
	int		j;

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
	if (counter(elem) == 0)
		return (shutwindow(elem));
	return (1);
}

int	secure_window(t_elem *elem)
{
	if (elem->windowptr == NULL)
	{
		freetab(elem->map, elem);
		mlx_destroy_display(elem->mlxptr);
		free(elem->mlxptr);
		return (0);
	}
	if (checkxpm(elem) == 0 || putimage(elem) == 0)
	{
		mlx_clear_window (elem->mlxptr, elem->windowptr);
		mlx_destroy_window (elem->mlxptr, elem->windowptr);
		elem->error = 4;
		freetab(elem->map, elem);
		mlx_destroy_display(elem->mlxptr);
		free(elem->mlxptr);
		return (0);
	}
	return (1);
}

int	init_screen(t_elem *elem)
{
	elem->mlxptr = mlx_init();
	if (elem->mlxptr == NULL)
	{
		freetab(elem->map, elem);
		return (0);
	}
	mlx_get_screen_size(elem->mlxptr, &elem->screenx, &elem->screeny);
	if ((elem->mapsize * 55) >= elem->screeny
		|| (elem->maplen * 55) >= elem->screenx)
	{
		elem->error = 3;
		freetab(elem->map, elem);
		mlx_destroy_display(elem->mlxptr);
		free(elem->mlxptr);
		return (0);
	}
	elem->windowptr = mlx_new_window(elem->mlxptr,
			55 * elem->maplen, elem->mapsize * 55, "so_long");
	return (1);
}

int	windowinit(t_elem *elem)
{
	char	*tempostring;
	char	*tempo;

	if (init_screen(elem) == 0 || secure_window(elem) == 0)
		return (0);
	mlx_hook(elem->windowptr, 2, 1l << 0, key_hook, elem);
	mlx_hook(elem->windowptr, 33, 1L << 5, shutwindow, elem);
	tempostring = ft_itoa(elem->playermove);
	if (tempostring == NULL)
	{
		error(2, elem);
		return (shutwindow(elem));
	}
	ft_putstr("\nNumber of moves : ");
	tempo = ft_itoa(elem->playermove);
	ft_putstr(tempo);
	free(tempo);
	ft_putstr("\n");
	tempo = NULL;
	mlx_string_put (elem->mlxptr, elem->windowptr, 22, 22, 555, tempostring);
	free(tempostring);
	mlx_loop_hook (elem->mlxptr, ft_animations, elem);
	mlx_loop(elem->mlxptr);
	return (1);
}
