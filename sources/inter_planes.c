/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_planes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:35:39 by dcognata          #+#    #+#             */
/*   Updated: 2016/09/17 13:57:20 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static int	test_hit(t_ray *ray, t_plane *p)
{
	if (ray && p)
		return (0);
	return (0);
}

int			inter_planes(t_env *e, t_ray *ray)
{
	int		i;

	i = 0;
	while (i < e->scene->n_plane)
	{
		if (test_hit(ray, &e->scene->planes[i]))
		{
			draw_pixel(e, (t_pixel){ray->origin.x, ray->origin.y, 0x000000});
			return (1);
		}
		++i;
	}
	return (0);
}