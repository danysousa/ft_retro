/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtRetroGame.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:02:00 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FtRetroGame.hpp"
# include "GameObjects/Background.hpp"
# include "GameObjects/Player.hpp"
# include "GameObjects/Map.hpp"
# include "GameComponents/DisplayComponent.hpp"
# include <iostream>

FtRetroGame::FtRetroGame() : Game()
{
	return ;
}

FtRetroGame::FtRetroGame( FtRetroGame const & src ) : Game()
{
	*this = src;
	return ;
}

FtRetroGame::~FtRetroGame()
{
	return ;
}

FtRetroGame &	FtRetroGame::operator=( FtRetroGame const & rhs )
{
	if ( this != &rhs )
	{
	}
	return ( *this );
}

bool			FtRetroGame::init()
{
	// START INIT

	Background *	background = new Background();
	addObject( *background );

	Player *	player = new Player(">");
	addObject( *player );

	Map *	map = new Map();
	addObject( *map );

	// END INIT
	return ( true );
}
