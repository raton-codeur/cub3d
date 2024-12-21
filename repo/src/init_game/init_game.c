/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 10:48:16 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

void	init_game(t_data *data)
{
	data->mlx = mlx_init(1, 1, "Cub3D", false);
	if (data->mlx == NULL)
		mlx_perror_exit(data);
	init_dimensions(data);
	init_background(data);
	init_game_img(data);
	init_map(data);
	init_map_rays(data);
	init_map_player(data);
	init_minimap(data);
	init_minimap_player(data);
	data->mini_w_2 = data->minimap->width / 2;
	data->mini_w_22 = data->mini_w_2 * data->mini_w_2;
	data->mini_box_size = data->minimap->width / 10;
	data->ray_dir_ratio = 3.0 / data->box_size;
}
