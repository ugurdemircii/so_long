/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:32:12 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/09 20:39:25 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->player_w, &game->player_h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->player_w, &game->player_h);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->player_w, &game->player_h);
	game->tp = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->player_w, &game->player_h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->player_w, &game->player_h);
	if (!game->player || !game->wall
		|| !game->collectible || !game->tp || !game->floor)
	{
		ft_free(game, "Error\nXpm file error\n", 1);
	}
}

void	get_rows(t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(game->path, O_RDONLY);
	if (fd < 0)
		ft_free(game, "Error\nfd error\n", 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->maps->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	game->maps->map[i] = NULL;
	close(fd);
}

static void	re_write_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

int	close_window(t_game *game)
{
	ft_free(game, "", 0);
	return (0);
}

void	run_game(t_game *game)
{
	is_empty_check(game, game->path);
	read_map(game);
	get_rows(game);
	if (!check_lines(game->maps->map, game->maps->row))
		ft_free(game, "Error\nMap is not valid\n", 1);
	re_write_map(game->maps->map);
	game->maps->column = ft_strlen(game->maps->map[0]);
	if (game->maps->column > 60)
		ft_free(game, "Error\nSize error\n", 1);
	check_map_is_valid(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_free(game, "Error\nmlx was not created\n", 1);
	screen_size(game);
	load_images(game);
	game->win = mlx_new_window (game->mlx, game->maps->column * 64,
			game->maps->row * 64, "so_long");
	if (!game->win)
		ft_free(game, "Error\nWin was not created\n", 1);
	set_cordinate(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
}
