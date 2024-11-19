/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:55:26 by qhauuy            #+#    #+#             */
/*   Updated: 2024/11/19 14:49:06 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "raycasting.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		mlx_set_instance_depth(&data->map_img->instances[0], \
			-data->map_img->instances[0].z);
		mlx_set_instance_depth(&data->rays->instances[0], \
			-data->rays->instances[0].z);
		mlx_set_instance_depth(&data->player->instances[0], \
			-data->player->instances[0].z);
	}
}

void	erase_image(mlx_image_t *image)
{
	ft_bzero(image->pixels, image->width * image->height * sizeof(uint32_t));
}

void	check_movement_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
}

void	check_rotation_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(data);
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	// draw_ray(data, -1, 0x00000000);
	// draw_ray(data, 0, 0x00000000);
	// draw_ray(data, 1, 0x00000000);
	draw_vision(data, 0);
	erase_image(data->walls);
	check_movement_keys(data);
	check_rotation_keys(data);
	draw_vision(data, 0x00FF00FF);
	// draw_ray(data, -1, 0x00FF00FF);
	// draw_ray(data, 0, 0x00FF00FF);
	// draw_ray(data, 1, 0x00FF00FF);
	dda(data);
}
