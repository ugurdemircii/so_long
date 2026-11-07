/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:31:18 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/09 20:08:54 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->maps->map[++i])
	{
		j = -1;
		while (game->maps->map[i][++j])
		{
			if (game->maps->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
				game->maps->p_count += 1;
			}
			else if (game->maps->map[i][j] == 'C')
				game->maps->c_count += 1;
			else if (game->maps->map[i][j] == 'E')
				game->maps->e_count += 1;
		}
	}
	if (game->maps->p_count != 1
		|| game->maps->e_count != 1 || game->maps->c_count < 1)
		return (0);
	return (1);
}

void	check_map_is_valid(t_game *game)
{
	if (!is_map_valid(game->maps->map))
		ft_free(game, "Error\nUndefined char on map\n", 1);
	else if (!wall_control_up_and_down(game)
		|| !wall_control_right_and_left(game))
		ft_free(game, "Error\nMap is not surroundered by walls\n", 1);
	else if (!count_elements(game))
		ft_free(game, "Error\nNumber of elements is invalid\n", 1);
	zero_map(game);
	dfs(game, game->player_y, game->player_x);
	if (!(game->maps->c_count == game->maps->dfs_c_count
			&&game->maps->dfs_e_count == game->maps->e_count
			&& game->maps->p_count == game->maps->dfs_p_count))
	{
		ft_free_map_dfs(game);
		ft_free(game, "Error\nDfs detected an error\n", 1);
	}
	else
		ft_free_map_dfs(game);
}

int	check_lines(char **map, int row)
{
	int	i;
	int	temp;
	int	length;

	length = -1;
	i = 0;
	temp = 0;
	while (map[i])
	{
		temp = ft_strlen(map[i]);
		if (length == -1)
			length = temp;
		if ((i == row - 1) && temp != length - 1)
			return (0);
		else if (i != row -1 && temp != length)
			return (0);
		i++;
	}
	return (1);
}
