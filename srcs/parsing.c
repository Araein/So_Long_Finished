/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:40 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 17:13:17 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

int	checkber(int len, char *string)
{
	int		i;
	char	*ref;

	ref = ft_strdup(".ber");
	if (ref == NULL)
		return (0);
	i = 3;
	while (i != -1 && ref[i] == string[len - 1])
	{
		len--;
		i--;
	}
	free(ref);
	if (i >= 0)
		return (0);
	return (1);
}

int	checkarg(int argc, char **argv)
{
	int	len;	

	if (argc >= 3)
		return (0);
	if (argc < 2)
		return (0);
	len = ft_strlen(argv[1]);
	if (len < 5 || !(checkber(len, argv[1])))
		return (0);
	return (1);
}

int	parsing(int argc, char **argv, t_elem *elem)
{
	if (!(checkarg(argc, argv)))
		return (0);
	elem->d = 5;
	return (1);
}
