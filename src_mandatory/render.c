/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:30:41 by abziouzi          #+#    #+#             */
/*   Updated: 2022/06/20 13:53:47 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	destroy_window(t_obj *obj)
{
	mlx_destroy_window(obj->mlx, obj->win);
	free_all(obj);
	exit(0);
	return (1);
}

int	key_handler(int keycode, t_obj *obj)
{
	if (keycode == KEY_ESC)
		return (destroy_window(obj));
	if ((keycode >= KEY_LEFT && keycode <= KEY_RIGHT) || keycode == KEY_UP)
		movement(keycode, obj);
	return (1);
}

void	render(t_obj *obj)
{
	obj->mlx = mlx_init();
	obj->win = mlx_new_window(obj->mlx, \
	obj->width * 48, obj->height * 48, "abziouzi's So Long");
	load_images(obj);
	rendering(obj);
	mlx_hook(obj->win, 2, 0L, key_handler, obj);
	mlx_hook(obj->win, 17, 0L, destroy_window, obj);
	mlx_loop(obj->mlx);
}
