/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:26:49 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/09 19:06:39 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->path, O_RDONLY);
	if (fd < 0)
		ft_free(game, "Error\nfd error\n", 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		game->maps->row++;
		if (game->maps->row > 33)
		{
			free(line);
			ft_free(game, "Error\nSize error\n", 1);
		}
	}
	game->maps->map = (char **)ft_calloc(game->maps->row + 1, sizeof(char *));
	if (!game->maps->map)
		ft_free(game, "Error\nft_calloc error\n", 1);
	close(fd);
}

int	check_and_get_file_path(t_game *game, char *path)
{
	int	len;
	int	i;

	i = 0;
	if (ft_strlen(path) < 5)
		return (0);
	len = ft_strlen(path);
	if ((path[len -1] != 'r' || path[len -2] != 'e' || path[len -3] != 'b'
			|| path[len - 4] != '.') || path[len - 5] == '/')
	{
		return (0);
	}
	game->path = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (!game->path)
		ft_free(game, "Error\nft_calloc error\n", 1);
	while (path[i])
	{
		game->path[i] = path[i];
		i++;
	}
	game->path[i] = '\0';
	return (1);
}

void	init_variables(t_game *game)
{
	game->maps->map = NULL;
	game->maps->map_dfs = NULL;
	game->collectible = NULL;
	game->floor = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->tp = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->path = NULL;
	game->mv_count = 0;
	game->maps->c_count = 0;
	game->maps->column = 0;
	game->maps->e_count = 0;
	game->maps->p_count = 0;
	game->maps->row = 0;
	game->maps->dfs_c_count = 0;
	game->maps->dfs_p_count = 0;
	game->maps->dfs_e_count = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = (t_game *)ft_calloc(1, sizeof(t_game));
		game->maps = (t_map *)ft_calloc(1, sizeof(t_map));
		init_variables(game);
		if (!game || !game->maps)
			ft_free(game, "Error\nft_calloc Error\n", 1);
		if (!check_and_get_file_path(game, argv[1]))
			ft_free(game, "Error\nPath is no valid\n", 1);
		run_game(game);
	}
	else
	{
		ft_printf("Error\nNumber of arguments is invalid\n");
		return (1);
	}
}
