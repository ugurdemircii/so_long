/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 03:30:55 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/09 17:09:25 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_x_y(t_game *game, int a, int b, int flg)
{
	game->player_y += a;
	game->player_x += b;
	game->mv_count += 1;
	ft_printf("player moves count = %d\n", game->mv_count);
	render(game, -a, -b, flg);
}

void	all_moves(t_game *game, int a, int b)
{
	char		next_char;
	static int	flg = 0;

	next_char = game->maps->map[game->player_y + a][game->player_x + b];
	if (next_char != '1' && next_char != 'E')
	{
		if (next_char == 'C')
		{
			game->maps->map[game->player_y + a][game->player_x + b] = '0';
			game->maps->c_count -= 1;
		}
		set_player_x_y(game, a, b, flg);
	}
	else if (next_char == '1')
		return ;
	else if (next_char == 'E')
	{
		set_player_x_y(game, a, b, flg);
		if (game->maps->c_count != 0)
			flg = 1;
		else
			ft_free(game, "", 0);
	}
	if (next_char != 'E' && flg == 1)
		flg = 0;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_free(game, "", 0);
	else if (keycode == 119)
		all_moves(game, -1, 0);
	else if (keycode == 97)
		all_moves(game, 0, -1);
	else if (keycode == 115)
		all_moves(game, 1, 0);
	else if (keycode == 100)
		all_moves(game, 0, 1);
	return (0);
}
