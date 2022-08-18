/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:33 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 14:16:59 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	error(int type, t_elem *elem)
{
	ft_putstr_fd("Error\n", 2);
	if (type == 0)
		ft_putstr_fd("Something went wrong with your input\n", 2);
	if (type == 1)
	{
		freetab(elem->map, elem);
		ft_putstr_fd("Your map doesn't fit\n", 2);
	}
	if (type == 2)
	{	
		if (elem->error == 3)
			ft_putstr_fd("The map is too big for your screen\n", 2);
		else if (elem->error == 4)
			ft_putstr_fd("Something is wrong with your .xpm files\n", 2);
		else
			ft_putstr_fd("Window initialization failed\n", 2);
	}
	if (type == 3)
		ft_putstr_fd("Something went wrong with the memory allocation\n", 2);
	return (0);
}

void	structinit(t_elem *elem)
{
	elem->map = NULL;
	elem->mapsize = 0;
	elem->maplen = 0;
	elem->counte = 0;
	elem->countc = 0;
	elem->countp = 0;
	elem->temp = NULL;
	elem->x = 0;
	elem->y = 0;
	elem->count = 0;
	elem->playermove = 0;
	elem->duo = 0;
	elem->clean = 0;
	elem->error = 0;
}

int	createmap(char **argv, t_elem *elem, int fd)
{
	int	d;

	d = 0;
	fd = open(argv[1], O_RDONLY);
	elem->map = malloc (sizeof(char *) * (elem->mapsize + 1));
	if (elem->map == NULL)
		return (0);
	while (get_next_line(fd, &(elem->temp)) > 0)
	{
		elem->map[d] = ft_strdup(elem->temp);
		free(elem->temp);
		d++;
	}
	close(fd);
	if (elem->temp)
	{
		elem->map[d] = ft_strdup(elem->temp);
		free(elem->temp);
		if (elem->map[d] == NULL)
			return (0);
	}
	elem->map[d + 1] = NULL;
	return (1);
}

int	writemap(char **argv, int fd, t_elem *elem)
{
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &(elem->temp)))
	{
		elem->mapsize++;
		free(elem->temp);
	}
	if (elem->temp)
	{
		elem->mapsize++;
		free(elem->temp);
	}
	elem->clean = elem->mapsize;
	close(fd);
	if (createmap(argv, elem, fd) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_elem	elem;
	int		fd;

	structinit(&elem);
	if (!(parsing(argc, argv, &elem)))
		return (error(0, &elem));
	fd = open(argv[1], O_RDONLY);
	if (get_next_line(fd, &(elem.temp)) == -1)
		return (mainerror(&elem));
	if (elem.temp)
		free(elem.temp);
	if (writemap(argv, fd, &elem) == 0)
	{
		freetab(elem.map, &elem);
		return (error(3, &elem));
	}
	if (elem.mapsize < 3 || !(checkmap(&elem)))
		return (error(1, &elem));
	if (!(windowinit(&elem)))
		return (error(2, &elem));
	return (0);
}
