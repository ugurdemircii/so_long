/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 03:45:33 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/09 20:05:21 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	screen_size(t_game *game)
{
	mlx_get_screen_size(game->mlx, &game->size_x, &game->size_y);
	if (game->maps->row * 64 > game->size_y
		|| game->maps->column * 64 > game->size_x)
		ft_free(game, "Error\nSize error\n", 1);
}

static void	put_image(int i, int j, char c, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, i, j);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor, i, j);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible, i, j);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->tp, i, j);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, i, j);
}

void	set_cordinate(t_game *game)
{
	int		i;
	int		j;
	int		x_point;
	int		y_point;
	char	c;

	y_point = 0;
	i = -1;
	while (game->maps->map[++i])
	{
		j = -1;
		x_point = 0;
		while (game->maps->map[i][++j])
		{
			c = game->maps->map[i][j];
			if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' )
				put_image(x_point, y_point, c, game);
			x_point += 64;
		}
		y_point += 64;
	}
}

void	render(t_game *game, int i, int j, int flg)
{
	if (flg == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			(game->player_x * 64) + (j * 64), (game->player_y * 64) + (i * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			game->player_x * 64, game->player_y * 64);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tp,
			(game->player_x * 64) + (j * 64), (game->player_y * 64) + (i * 64));
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			game->player_x * 64, game->player_y * 64);
	}
}
