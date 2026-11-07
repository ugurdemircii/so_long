/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 02:42:39 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/09 20:08:33 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map_dfs(t_game *game)
{
	int	i;

	i = 0;
	if (game->maps->map_dfs)
	{
		while (game->maps->map_dfs[i])
		{
			free(game->maps->map_dfs[i]);
			i++;
		}	
		free(game->maps->map_dfs);
	}
}

static void	ft_free_destroy(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->tp)
		mlx_destroy_image(game->mlx, game->tp);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

void	ft_free(t_game *game, char *message, int flg)
{
	int	i;

	i = 0;
	if (game->maps->map)
	{
		while (game->maps->map[i])
		{
			free(game->maps->map[i]);
			i++;
		}
		free(game->maps->map);
	}
	free(game->maps);
	ft_free_destroy(game);
	free(game->mlx);
	free(game->path);
	free(game);
	ft_printf("%s", message);
	exit(flg);
}
