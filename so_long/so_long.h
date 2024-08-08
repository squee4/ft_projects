/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:18:27 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/08/07 19:21:01 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_images
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*coin;
	mlx_image_t		*exit;
	mlx_image_t		*door;
}	t_images;

typedef struct s_data
{
	mlx_t			*window;
	char			**map;
	int				height;
	int				width;
	int				moves;
	int				coins;
	int				size;
	t_point			player;
	t_images		images;
}	t_data;

//FUNciones
char		**ft_read_map(char *map_name);
int			ft_is_square(t_data *data);
int			ft_valid_format(char *map_name);
int			ft_contains_one(t_data *data, char c);
int			ft_contains_multi(t_data *data, char c);
int			ft_valid_chars(t_data *data, char *set);
int			ft_surrounded(t_data *data);
int			ft_map_valid(t_data *data, char *map_name);
void		ft_dimension_player(t_data *data);
void		ft_fill(char **map, int width, int height, t_point cur);
void		ft_open_window(t_data *data);
void		ft_error(char *message, t_data *data);
void		ft_draw_tile(char c, int x, int y, t_data *data);
mlx_image_t	*ft_load_image(char *img_name, t_data *data);
void		ft_draw_map(t_data *data);
void		ft_draw_rest(t_data *data);
void		ft_free_images(t_data *data);
void		ft_start_images(t_data *data);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		ft_move_up(t_data *data);
void		ft_move_left(t_data *data);
void		ft_move_down(t_data *data);
void		ft_move_right(t_data *data);
void		ft_redraw_coins(t_data *data);
void		ft_print(char *message, int num);
void		ft_redraw_player(t_data *data);
void		ft_move_handler(t_data *data, char dest);
int			ft_double_break(char *str);

#endif
