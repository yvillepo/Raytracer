/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:25:27 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/27 16:25:28 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_scene *s, char *filename)
{
	if (s && filename)
		return ;
	// int		fd;

	// if ((fd = open(filename, O_RDONLY)) == -1)
	// 	error(3, "Unable to open the file. Check path.");
	// parse_counts(s, fd);
	// parse_lights(s, fd);
	// parse_spheres(s, fd);
	// parse_cylinders(s, fd);
	// parse_cones(s, fd);
	// parse_planes(s, fd);
	// close(fd);
}
