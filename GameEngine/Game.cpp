/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 17:34:15 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Game.hpp"
# include "CoreEngine.hpp"

Game::Game() :
	_root( 0 )
{
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
	this->getRootObject().updateAll( delta );
}

void	Game::physic( float delta )
{
	this->getRootObject().physicAll( delta );
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
