/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtRetroGame.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 19:15:21 by dsousa           ###   ########.fr       */
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

	GameObject *	o = new Player(">");

	addObject( *o );

	// END INIT
	return ( true );
}
