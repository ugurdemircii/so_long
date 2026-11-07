/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:25:50 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/09 17:17:54 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_empty_check(t_game *game, char *path)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_free(game, "Error\n.ber file cannot find or fd error\n", 1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		ft_free(game, "Error\nEmpty file\n", 1);
	}
	close (fd);
	free(line);
}

int	is_map_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == '1' || map[i][j] == 'E'
				|| map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == '0'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	wall_control_up_and_down(t_game *game)
{
	int	j;

	j = 0;
	while (game->maps->map[0][j])
	{
		if (game->maps->map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (game->maps->map[game->maps->row -1][j])
	{
		if (game->maps->map[game->maps->row -1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	wall_control_right_and_left(t_game *game)
{
	int	i;

	i = 0;
	while (game->maps->map[i])
	{
		if (game->maps->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (game->maps->map[i])
	{
		if (game->maps->map[i][game->maps->column -1] != '1')
			return (0);
		i++;
	}
	return (1);
}
