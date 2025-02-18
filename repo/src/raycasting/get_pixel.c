/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:19:37 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 11:18:57 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	get_pixel_wall(t_data *data)
{
	data->r = data->tex->pixels[data->tex_y * data->tex->width * 4 + \
		data->tex_x * 4];
	data->g = data->tex->pixels[data->tex_y * data->tex->width * 4 + \
		data->tex_x * 4 + 1];
	data->b = data->tex->pixels[data->tex_y * data->tex->width * 4 + \
		data->tex_x * 4 + 2];
	data->pixel = data->r << 24 | data->g << 16 | data->b << 8 | 255;
}
