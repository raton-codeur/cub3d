/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:16:24 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/23 16:27:06 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_background(t_data *data)
{
	data->background = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (data->background == NULL)
		return (mlx_perror_exit(data));
	if (mlx_image_to_window(data->mlx, data->background, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->background), mlx_perror_exit(data));
	fill_zone(data->background, (t_u_points){W_WIDTH / 2, 0, W_WIDTH, W_HEIGHT / 2}, CEIL_COLOR);
	fill_zone(data->background, (t_u_points){W_WIDTH / 2, W_HEIGHT / 2, W_WIDTH, W_HEIGHT}, FLOOR_COLOR);
}
