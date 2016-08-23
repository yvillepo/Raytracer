/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 05:01:29 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/20 05:01:30 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	malloc_counts(t_scene *s)
{
	if (s->n_light)
		if (!(s->lights =
			(t_light *)malloc(sizeof(t_light) * s->n_light)))
			error(-9, "Unable to create lights.");
	if (s->n_sphere)
		if (!(s->spheres =
			(t_sphere *)malloc(sizeof(t_sphere) * s->n_sphere)))
			error(-10, "Unable to create spheres.");
	if (s->n_cylinder)
		if (!(s->cylinders =
			(t_cylinder *)malloc(sizeof(t_cylinder) * s->n_cylinder)))
			error(-11, "Unable to create cylinders.");
	if (s->n_cone)
		if (!(s->cones =
			(t_cone *)malloc(sizeof(t_cone) * s->n_cone)))
			error(-12, "Unable to create cones.");
	if (s->n_plane)
		if (!(s->planes =
			(t_plane *)malloc(sizeof(t_plane) * s->n_plane)))
			error(-13, "Unable to create planes.");
}

void		fill_counts_data(t_scene *s, char *data)
{
	s->n_light = read_int_data(data, "config.counts.lights");
	s->n_sphere = read_int_data(data, "config.counts.spheres");
	s->n_cylinder = read_int_data(data, "config.counts.cylinders");
	s->n_cone = read_int_data(data, "config.counts.cones");
	s->n_plane = read_int_data(data, "config.counts.planes");
	s->n_light = s->n_light < 0 ? 0 : s->n_light;
	s->n_sphere = s->n_sphere < 0 ? 0 : s->n_sphere;
	s->n_cylinder = s->n_cylinder < 0 ? 0 : s->n_cylinder;
	s->n_cone = s->n_cone < 0 ? 0 : s->n_cone;
	s->n_plane = s->n_plane < 0 ? 0 : s->n_plane;
	ft_putnbr_endl(s->n_light);
	ft_putnbr_endl(s->n_sphere);
	ft_putnbr_endl(s->n_cylinder);
	ft_putnbr_endl(s->n_cone);
	ft_putnbr_endl(s->n_plane);
	malloc_counts(s);
}

void		fill_screen_data(t_scene *s, char *data)
{
	int		sw;
	int		sh;

	sw = read_int_data(data, "config.screen.width");
	sh = read_int_data(data, "config.screen.height");
	s->screen_w = sw >= MIN_SCREEN_W && sw <= MAX_SCREEN_W ? sw : SCREEN_W;
	s->screen_h = sh >= MIN_SCREEN_H && sh <= MAX_SCREEN_H ? sh : SCREEN_H;
}