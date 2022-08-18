/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:44:28 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 17:26:27 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

typedef struct s_elem
{
	char	**map;
	char	*temp;
	int		d;
	int		mapsize;
	int		maplen;
	int		counte;
	int		countc;
	int		countp;
	int		playermove;
	int		screenx;
	int		screeny;
	void	*mlxptr;
	void	*windowptr;
	void	*baba;
	void	*door;
	void	*rock;
	void	*key;
	void	*floor;
	int		x;
	int		y;
	int		count;
	int		duo;
	int		clean;
	int		error;
	int		babapos[2];
	int		destination[2];
}				t_elem;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# define ROCK "./images/ROCK0.xpm"
# define ROCK1 "./images/ROCK1.xpm"
# define ROCK2 "./images/ROCK2.xpm"
# define BABA "./images/baba0.xpm"
# define BABA1 "./images/baba1.xpm"
# define BABA2 "./images/baba2.xpm"
# define DOOR "./images/DOOR0.xpm"
# define DOOR1 "./images/DOOR1.xpm"
# define DOOR2 "./images/DOOR2.xpm"
# define KEY "./images/KEY0.xpm"
# define KEY1 "./images/KEY1.xpm"
# define KEY2 "./images/KEY2.xpm"
# define FORWARD	119
# define BACK		115
# define LEFT		97
# define RIGHT		100

//gnl
void	*ft_calloc(size_t count, size_t size);
char	*mallocstock(int fd, char *stock);
char	*ft_strchr(const char *str, int searched);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const*s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *str);
char	*get_line(char *str, char **line, int r);
char	*read_line(char *str, int fd, int *r, char *tmp);
int		test2( int **r, char *buf, char *str, int fd);
int		test( int **r, char *buf);
//parsing
void	ft_putstr(char const *s);
void	ft_putchar(char c);
int		parsing(int argc, char **argv, t_elem *elem);
int		checkarg(int argc, char **argv);
int		checkber(int len, char *string);
//main
int		error(int type, t_elem *elem);
void	structinit(t_elem *elem);
int		writemap(char **argv, int fd, t_elem *elem);
int		createmap(char **argv, t_elem *elem, int fd);
//checkmap
int		checkmap(t_elem *elem);
int		checksquare(t_elem *elem);
int		checkcharac(t_elem *elem);
int		checkmywall(int i, char *string, t_elem *elem);
int		checkmychar(char mychar, t_elem *elem);
//window
void	freetab(char **tab, t_elem *elem);
int		shutwindow(t_elem *elem);
int		winfunc(t_elem *elem);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
int		zeroimage(t_elem *elem, int type);
//fillwindow
int		putimage(t_elem *elem);
int		putassets(t_elem *elem);
void	putscreen(int i, int j, t_elem *elem);
int		canbabamove(t_elem *elem);
int		key_hook(int keycode, t_elem *elem);
//gameplay
int		babamoveup(t_elem *elem);
int		babamovedown(t_elem *elem);
int		babamoveleft(t_elem *elem);
int		babamoveright(t_elem *elem);
int		movebaba(t_elem *elem);
//ft_itoa
char	*ft_itoa(long long n);
int		itoanega(long long *n, long long *negative);
void	itoalen(long long *tmpn, long long *len);
//error
int		mainerror(t_elem *elem);
int		errorxpm(t_elem *elem, int d);
void	writemove(t_elem *elem);
//check_xpm_bonus
int		checkxpm1(t_elem *elem);
int		checkxpm2(t_elem *elem);
int		checkxpm3(t_elem *elem);
int		checkxpm4(t_elem *elem);
int		checkxpm(t_elem *elem);
//animation_bonus
int		ft_animations(t_elem *elem);
void	baba_animation(t_elem *elem);
void	baba_animation2(t_elem *elem);
void	map_animation(t_elem *elem);
void	map_animation_zero(t_elem *elem);
//window_init_bonus
int		windowinit(t_elem *elem);
int		secure_window(t_elem *elem);
int		init_screen(t_elem *elem);
int		putassets(t_elem *elem);
#endif