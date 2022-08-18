/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:33 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 14:51:39 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	mainerror(t_elem *elem)
{
	ft_putstr_fd("Error\nYour map file can't be used\n", 2);
	if (elem->temp)
		free(elem->temp);
	return (0);
}

int	errorxpm(t_elem *elem, int d)
{
	if (d == 3)
	{
		mlx_destroy_image (elem->mlxptr, elem->baba);
		mlx_destroy_image (elem->mlxptr, elem->key);
		mlx_destroy_image (elem->mlxptr, elem->door);
	}
	if (d == 2)
	{
		mlx_destroy_image (elem->mlxptr, elem->baba);
		mlx_destroy_image (elem->mlxptr, elem->key);
	}
	return (0);
}

void	writemove(t_elem *elem)
{
	char	*tempo;

	elem->playermove++;
	ft_putstr("\nNumber of moves : ");
	tempo = ft_itoa(elem->playermove);
	ft_putstr(tempo);
	free(tempo);
	ft_putstr("\n");
}
