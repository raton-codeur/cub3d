/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:55:26 by qhauuy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/19 18:51:33 by qhauuy           ###   ########.fr       */
=======
/*   Updated: 2024/12/19 18:55:26 by qhauuy           ###   ########.fr       */
>>>>>>> 24a2f47 (blabla)
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "raycasting.h"

static void	check_movement_keys(t_data *data)
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

static void	check_rotation_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_x(data, STEP_ROTATE_X);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_x(data, -STEP_ROTATE_X);
}

void	render_minimap(t_data *data)
{
	erase_image(data->minimap);
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	if (data->mlx->delta_time < 0.01667)
		return ;
	check_movement_keys(data);
	check_rotation_keys(data);
	dda(data);
	if (data->depth_config == 2)
		render_minimap(data);
}
