/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 03:51:17 by gromon            #+#    #+#             */
/*   Updated: 2016/11/06 21:45:14 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			flour_color(t_color *color)
{
	color->r = (color->r * 255 > 255) ? 255 : color->r * 255;
	color->g = (color->g * 255 > 255) ? 255 : color->g * 255;
	color->b = (color->b * 255 > 255) ? 255 : color->b * 255;
}

t_color			get_global_illuminated_color(t_color *c, t_color *ambient)
{
	t_color	color;

	color.r = c->r * ambient->r;
	color.g = c->g * ambient->g;
	color.b = c->b * ambient->b;
	return (color);
}
