/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:47:11 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/18 19:47:12 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		draw_pixel(t_env *e, t_pixel p)
{
	if (p.x > 0 && p.x < e->scene->size.w && p.y > 0 && p.y < e->scene->size.h)
	{
        SDL_SetRenderDrawColor(e->renderer, p.color >> 16, p.color >> 8, p.color, 255);
        SDL_RenderDrawPoint(e->renderer, p.x, p.y);
	}
}

void		draw_image(t_env *e)
{
	raytrace(e);
    SDL_RenderPresent(e->renderer);
}
