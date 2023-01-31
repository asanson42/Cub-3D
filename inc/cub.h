/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:12:17 by asanson           #+#    #+#             */
/*   Updated: 2022/06/07 15:24:48 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../mlx_linux/mlx.h"

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W_Z	119
# define BACK_S_S	115
# define RIGHT_D_D	100
# define LEFT_A_Q	97
# define BUFFER_SIZE	4096

typedef struct s_texture
{
	int		texdir;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
}				t_texture;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	int			x;
	int			texture;
}				t_ray;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	int			*addr;
	int			bpp;
	int			linelen;
	int			endian;

	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	int			scale;
	int			width;
	int			height;
	void		*img2;
	int			*addr2;
}				t_mlx;

typedef struct s_data
{
	int			rx;
	int			ry;
	int			i;
	int			f;
	int			c;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			nbline;
	int			sizeline;
	char		**map;
	char		start;
	int			dx;
	int			dy;
	int			indicator;
	int			indicator2;
	int			indicator3;
	int			save;
	int			screenx;
	int			screeny;
	int			error;
	int			emptyline;
	int			multiplayer;
	int			insidemap;
	int			count;
	int			count2;
	int			wrongmapchar;
	t_mlx		texture[4];
	t_mlx		mlx;
	t_ray		ray;
	t_texture	t;
}				t_data;

//LIBFT
int		ft_strlen(char *str);
int		ft_strlen2(char *str);
char	*ft_strdup(char const *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t n);
int		ft_charinstr(char *str, char c);
int		ft_nb_virgule(const char *str);
void	ft_atoi3_check(const char *str, t_data *data);
int		ft_strlen(char *str);
char	*ft_subbuf(char *buff, int start, int len);
int		ft_check(char *str);
int		ft_copy(char **line, char **buff);
int		ft_eof(int ret, char **buff, char **line);
int		ft_free_buff(char **buff, t_data *data);
int		get_next_line(int fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);

//PARSER
int		check_borders(t_data *map);
int		check_all(t_data *map);
int		full_rgb(char *line);
int		ft_start(char c, t_data *data, int i, int j);
void	ft_init(t_data *data);
void	ft_init_more(t_data *data);
void	ft_init_dir(t_data *data);
void	ft_init_more3(t_data *data);
int		ft_emptyline(char *str);
int		ft_path_texture(char *str, char **texture, t_data *data, int j);
void	ft_texture(char *str, t_data *data);
void	ft_color_res(char **str, t_data *data);
int		ft_dupmap(char *str, t_data *data);
int		ft_is_map(char *str, t_data *data);
void	ft_map(char *str, t_data *data);
int		ft_parsing_map(char *file, t_data *data);
void	ft_parsing(char *file, t_data *data);

//ERRORS
void	free_data(t_data *data, char *str);
void	ft_verify_errors(t_data *data);
void	ft_error2(t_data *data);
void	ft_error(t_data *data, char *str);
int		ft_exit(t_data *data);

//RAYCASTER
int		ft_keypress(int keycode, t_data *data);
int		ft_keyrelease(int keycode, t_data *data);
int		display_column(t_data *data);
void	display_textures(t_data *data, int x, int y);
void	get_textures_addr(t_data *data);
void	get_textures(t_data *data);
int		ft_raycasting(t_data *data);
int		ft_mlx(t_data *data);
void	ft_init2(t_data *data);
void	ft_init3(t_data *data);
void	ft_init_textures(t_data *data);
void	ft_launch(t_data *data);
void	ft_forward_back(t_data *data);
void	ft_left_right(t_data *data);
void	ft_rotate(t_data *data);
void	ft_rotate_left(t_data *data);
void	ft_stepsidedist(t_data *data);
void	ft_increment_ray(t_data *data);
void	ft_startend(t_data *data);
void	ft_swap(t_data *data);

#endif
