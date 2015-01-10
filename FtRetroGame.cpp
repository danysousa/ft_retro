/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtRetroGame.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 17:08:02 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FtRetroGame.hpp"
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

bool	FtRetroGame::init()
{
	// START INIT

	GameObject *o = new GameObject();

	addObject( *o );

	// END INIT
	return ( true );
}
