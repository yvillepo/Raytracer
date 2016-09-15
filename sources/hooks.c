/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:56 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/18 19:46:59 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		expose_hook(t_env *e)
{
    draw_background(e);
	draw_image(e);
	return (0);
}

int		key_hook(int k, t_env *e)
{
    if (k == SDLK_ESCAPE)
        e->options.quit = TRUE;
    if (k == SDLK_f && e->options.fullscreen == FALSE)
    {
        e->options.fullscreen = TRUE;
        SDL_SetWindowFullscreen(e->win, SDL_WINDOW_FULLSCREEN);
    }
    else if (k == SDLK_f && e->options.fullscreen == TRUE)
    {
        e->options.fullscreen = FALSE;
        SDL_SetWindowFullscreen(e->win, 0);
    }
	return (0);
}
