/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_interface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:56 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/31 22:41:13 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	interface_mode_switch(t_env *e)
{
	if ((e->inputs.mouse_x >= 28 && e->inputs.mouse_x <= 45)
		&& (e->inputs.mouse_y >= 364 && e->inputs.mouse_y <= 381))
		e->options.mode = MODE_SELECT;
	else if ((e->inputs.mouse_x >= 28 && e->inputs.mouse_x <= 45)
		&& (e->inputs.mouse_y >= 395 && e->inputs.mouse_y <= 412))
		e->options.mode = MODE_CAMERA;
	else if ((e->inputs.mouse_x >= 28 && e->inputs.mouse_x <= 45)
		&& (e->inputs.mouse_y >= 427 && e->inputs.mouse_y <= 445))
		e->options.mode = MODE_CAMERA_ROT;
	else
		return (0);
	return (1);
}

static int	interface_mode_draw(t_env *e)
{
	if ((e->inputs.mouse_x >= 28 && e->inputs.mouse_x <= 45)
		&& (e->inputs.mouse_y >= 500 && e->inputs.mouse_y <= 516))
		e->options.mode = MODE_TEXTURES;
	else if ((e->inputs.mouse_x >= 28 && e->inputs.mouse_x <= 45)
		&& (e->inputs.mouse_y >= 532 && e->inputs.mouse_y <= 548))
		e->options.mode = MODE_BUMPMAPPING;
	else
		return (0);
	return (1);
}

static int	interface_move(t_env *e)
{
	if ((e->inputs.mouse_x >= 180 && e->inputs.mouse_x <= 225)
		&& (e->inputs.mouse_y >= 157 && e->inputs.mouse_y <= 202))
		move_forward(e);
	else if ((e->inputs.mouse_x >= 227 && e->inputs.mouse_x <= 272)
		&& (e->inputs.mouse_y >= 217 && e->inputs.mouse_y <= 260))
		move_backward(e);
	else if ((e->inputs.mouse_x >= 26 && e->inputs.mouse_x <= 70)
		&& (e->inputs.mouse_y >= 250 && e->inputs.mouse_y <= 295))
		move_left(e);
	else if ((e->inputs.mouse_x >= 80 && e->inputs.mouse_x <= 125)
		&& (e->inputs.mouse_y >= 195 && e->inputs.mouse_y <= 239))
		move_up(e);
	else if ((e->inputs.mouse_x >= 79 && e->inputs.mouse_x <= 126)
		&& (e->inputs.mouse_y >= 250 && e->inputs.mouse_y <= 295))
		move_down(e);
	else if ((e->inputs.mouse_x >= 135 && e->inputs.mouse_x <= 182)
		&& (e->inputs.mouse_y >= 250 && e->inputs.mouse_y <= 295))
		move_right(e);
	else
		return (0);
	return (1);
}

void		mouse_interface(t_env *e)
{
	if ((e->inputs.mouse_x >= 257 && e->inputs.mouse_x <= 287)
		&& (e->inputs.mouse_y >= 17 && e->inputs.mouse_y <= 47))
		take_screenshoot(e);
	if (interface_move(e))
	{
		e->options.need_redraw_sub = FALSE;
		e->options.need_redraw = TRUE;
	}
	if (interface_mode_draw(e))
	{
		e->options.need_redraw_sub = TRUE;
		e->options.need_redraw = FALSE;
	}
	if (interface_mode_switch(e))
	{
		e->options.need_redraw_sub = TRUE;
		e->options.need_redraw = FALSE;
	}
}
