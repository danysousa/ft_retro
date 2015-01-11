/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 18:09:30 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Game.hpp"
# include "CoreEngine.hpp"
# include "../GameObjects/Monster.hpp"
#include <cstdlib>
#include <ctime>

Game::Game() :
	_root( 0 )
{
	std::srand(std::time(0));
	return ;
}

Game::Game( Game const & src ) :
	_root( 0 )
{
	*this = src;
	return ;
}

Game::~Game()
{
	std::srand(std::time(0));
	return ;
}

Game &	Game::operator=( Game const & rhs )
{
	if ( this != &rhs )
	{
		this->_root = &rhs.getRoot();
	}
	return ( *this );
}

GameObject &	Game::getRoot() const
{
	return ( *this->_root );
}

GameObject &	Game::getRootObject()
{
	if ( !this->_root )
		this->_root = new GameObject();
	return ( *this->_root );
}

void	Game::input( float delta )
{
	this->getRootObject().inputAll( delta );
}

void	Game::update( float delta )
{
	this->logicGamePlay();
	this->getRootObject().updateAll( delta );
}

void	Game::render( RenderEngine & renderEngine )
{
	this->getRootObject().renderAll( renderEngine );
}

void	Game::addObject( GameObject & object )
{
	this->getRootObject().addChild( object );
}

void	Game::setEngine( CoreEngine & engine )
{
	this->getRootObject().setCoreEngine( engine );
}

void	Game::logicGamePlay( void )
{
	if ( std::rand() % 60 == 42 )
	{
		GameObject *	x = new Monster("X");

		addObject( *x );
	}
}
