/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtRetroGame.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 20:20:15 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FtRetroGame.hpp"
# include "GameObjects/Player.hpp"
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

	Player *	player = new Player(">");

	addObject( *player );

	// END INIT
	return ( true );
}
