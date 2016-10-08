/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:56 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 17:47:02 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

static void	print_mode(t_bool mode)
{
	if (mode == MODE_NULL)
		ft_putendl("Mode : Null");
	else if (mode == MODE_CAMERA)
		ft_putendl("Mode : Camera");
	else if (mode == MODE_SELECT)
		ft_putendl("Mode : Selections");
}

static void	change_mode(t_env *e, int mode)
{
	if (mode == MODE_CAMERA && e->options.mode != MODE_CAMERA)
		e->options.mode = MODE_CAMERA;
	else if (mode == MODE_SELECT && e->options.mode != MODE_SELECT)
		e->options.mode = MODE_SELECT;
	else if (mode == MODE_CAMERA && e->options.mode == MODE_CAMERA)
		e->options.mode = MODE_NULL;
	else if (mode == MODE_SELECT && e->options.mode == MODE_SELECT)
		e->options.mode = MODE_NULL;
	print_mode(e->options.mode);
}

void	key_hook(t_env *e)
{
	if (e->inputs.escape)
		e->options.quit = TRUE;

	// Modes
	if (e->inputs.key_1)
		change_mode(e, MODE_CAMERA);
	if (e->inputs.key_2)
		change_mode(e, MODE_SELECT);

	// Fullscreen
	if (e->inputs.key_f)
		toggle_fullscreen(e);

	// Moves
	if (e->inputs.key_left)
		move_left(e);
	if (e->inputs.key_right)
		move_right(e);
	if (e->inputs.key_up)
		move_up(e);
	if (e->inputs.key_down)
		move_down(e);
	if (e->inputs.key_forward)
		move_forward(e);
	if (e->inputs.key_backward)
		move_backward(e);
}

void	mouse_hook(t_env *e)
{
	t_ray	*ray;

	if (e->inputs.mouse_left)
	{
		ray = create_ray(&e->scene->cam->pos, (t_vec3)
		{
			e->inputs.mouse_x - (e->scene->size.w / 2),
			e->inputs.mouse_y - (e->scene->size.h / 2),
			0
		}, 1);
		e->scene->selected = throw_ray(e, ray, e->inputs.mouse_x, e->inputs.mouse_y);
		if (e->scene->selected->shape_type == SPHERE)
			ft_putendl("Sphere selected");
		else if (e->scene->selected->shape_type == CYLINDER)
			ft_putendl("Cylinder selected");
		else if (e->scene->selected->shape_type == CONE)
			ft_putendl("Cone selected");
		else if (e->scene->selected->shape_type == PLANE)
			ft_putendl("Plane selected");
		free(ray);
	}
}
