/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 04:14:06 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/09 20:31:41 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	int		row;
	int		column;
	int		e_count;
	int		c_count;
	int		p_count;
	int		dfs_p_count;
	int		dfs_c_count;
	int		dfs_e_count;
	char	**map_dfs;
	char	**map;

}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*collectible;
	void	*floor;
	void	*tp;
	char	*path;
	int		size_x;
	int		size_y;
	int		player_x;
	int		player_y;
	int		player_h;
	int		player_w;
	int		mv_count;
	t_map	*maps;
}	t_game;

void	screen_size(t_game *game);
void	ft_free_map_dfs(t_game *game);
void	dfs(t_game *game, int row, int col);
void	zero_map(t_game *game);
void	ft_free(t_game *game, char *message, int flg);
void	set_cordinate(t_game *game);
int		key_hook(int keycode, t_game *game);
void	render(t_game *game, int i, int j, int flg);
void	is_empty_check(t_game *game, char *path);
void	run_game(t_game *game);
void	read_map(t_game *game);
int		is_map_valid(char **map);
int		wall_control_up_and_down(t_game *game);
int		wall_control_right_and_left(t_game *game);
int		check_lines(char **map, int row);
void	check_map_is_valid(t_game *game);
#endif