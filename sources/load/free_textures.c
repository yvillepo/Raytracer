/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:49:14 by dcognata          #+#    #+#             */
/*   Updated: 2016/04/18 19:49:15 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		free_textures(t_env *e)
{
	SDL_FreeSurface(e->textures.marble);
	SDL_DestroyTexture(e->interface.background);
	SDL_DestroyTexture(e->interface.checkbox);
}
