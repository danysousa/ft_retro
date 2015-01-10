/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtRetroGame.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:36:20 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 17:36:39 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_GAME
# define FT_RETRO_GAME
# include "GameEngine/Game.hpp"

class FtRetroGame : public Game
{
public:
	FtRetroGame( void );
	FtRetroGame( FtRetroGame const & src );
	virtual ~FtRetroGame( void );

	virtual bool	init( void );

	FtRetroGame &			operator=( FtRetroGame const & rhs );

};

#endif
