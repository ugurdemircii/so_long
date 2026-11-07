/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:44:19 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/09 21:05:46 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_zero_all(char **map_dfs, int column)
{
	int	i;
	int	j;

	i = 0;
	while (map_dfs[i])
	{
		j = 0;
		while (j < column)
		{
			map_dfs[i][j] = '0';
			j++;
		}
		map_dfs[i][j] = '\0';
		i++;
	}
}

void	zero_map(t_game *game)
{
	int	i;
	int	row;
	int	column;

	i = 0;
	row = game->maps->row;
	column = game->maps->column;
	game->maps->map_dfs = (char **)ft_calloc(1, sizeof(char *) * (row + 1));
	while (i < game->maps->row)
	{
		game->maps->map_dfs[i] = (char *)ft_calloc(1,
				sizeof(char) * (column + 1));
		i++;
	}
	game->maps->map_dfs[i] = NULL;
	set_zero_all(game->maps->map_dfs, column);
}

void	dfs(t_game *game, int row, int col)
{
	if (row < 1 || row >= game->maps->row - 1 || col < 1
		|| col >= game->maps->column -1
		|| game->maps->map[row][col] == '1'
		|| game->maps->map_dfs[row][col] == '1')
		return ;
	game->maps->map_dfs[row][col] = '1';
	if (game->maps->map[row][col] == 'E')
		game->maps->dfs_e_count++;
	if (game->maps->map[row][col] == 'C')
		game->maps->dfs_c_count++;
	if (game->maps->map[row][col] == 'P')
		game->maps->dfs_p_count++;
	dfs(game, row - 1, col);
	dfs(game, row + 1, col);
	dfs(game, row, col - 1);
	dfs(game, row, col + 1);
}
