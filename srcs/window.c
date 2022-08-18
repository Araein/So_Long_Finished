/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:45 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/12 20:29:19 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	freetab(char **tab, t_elem *elem)
{
	int	i;

	i = 0;
	while (i < elem->clean)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

int	winfunc(t_elem *elem)
{
	char	*tempo;

	mlx_destroy_image (elem->mlxptr, elem->baba);
	mlx_destroy_image (elem->mlxptr, elem->key);
	mlx_destroy_image (elem->mlxptr, elem->door);
	mlx_destroy_image (elem->mlxptr, elem->rock);
	mlx_clear_window (elem->mlxptr, elem->windowptr);
	mlx_destroy_window (elem->mlxptr, elem->windowptr);
	freetab (elem->map, elem);
	mlx_destroy_display (elem->mlxptr);
	free(elem->mlxptr);
	ft_putstr("\nGoodjob, you won the game ! Total number of moves : ");
	tempo = ft_itoa(elem->playermove);
	ft_putstr(tempo);
	free(tempo);
	ft_putstr("\n");
	exit(1);
	return (1);
}

int	shutwindow(t_elem *elem)
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
	ft_putstr("Goodbye !\n");
	exit(1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
