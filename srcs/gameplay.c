/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:19 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 14:39:15 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	movebaba(t_elem *elem)
{
	void	*checkbaba;

	checkbaba = mlx_xpm_file_to_image (elem->mlxptr, BABA,
			&(elem->mapsize), &(elem->maplen));
	if (checkbaba == 0)
	{
		ft_putstr_fd("\nError : something happened with your .xpm files !\n", 2);
		shutwindow(elem);
	}
	else
		mlx_destroy_image(elem->mlxptr, checkbaba);
	writemove(elem);
	elem->map[elem->babapos[1]][elem->babapos[0]] = '0';
	if (elem->map[elem->destination[1]][elem->destination[0]] == 'E'
		&& elem->countc == 0)
		return (winfunc(elem));
	elem->map[elem->destination[1]][elem->destination[0]] = 'P';
	elem->babapos[0] = elem->destination[0];
	elem->babapos[1] = elem->destination[1];
	mlx_clear_window(elem->mlxptr, elem->windowptr);
	putassets(elem);
	return (1);
}

int	babamoveleft(t_elem *elem)
{
	elem->destination[0] = elem->babapos[0] - 1;
	elem->destination[1] = elem->babapos[1];
	if (canbabamove(elem))
		movebaba(elem);
	return (1);
}

int	babamoveright(t_elem *elem)
{
	elem->destination[0] = elem->babapos[0] + 1;
	elem->destination[1] = elem->babapos[1];
	if (canbabamove(elem))
		movebaba(elem);
	return (1);
}

int	babamoveup(t_elem *elem)
{
	elem->destination[0] = elem->babapos[0];
	elem->destination[1] = elem->babapos[1] - 1;
	if (canbabamove(elem))
		movebaba(elem);
	return (1);
}

int	babamovedown(t_elem *elem)
{
	elem->destination[0] = elem->babapos[0];
	elem->destination[1] = elem->babapos[1] + 1;
	if (canbabamove(elem))
		movebaba(elem);
	return (1);
}
