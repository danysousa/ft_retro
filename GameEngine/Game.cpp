/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 17:09:43 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Game.hpp"

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
	}
	return ( *this );
}

GameObject &	Game::getRootObject()
{
	if ( !this->_root )
		this->_root = new GameObject();
	return ( *this->_root );
}

void	Game::input( float delta )
{
	(void)delta;
}

void	Game::update( float delta )
{
	(void)delta;
}

void	Game::render( float delta )
{
	(void)delta;
}

void	Game::addObject( GameObject & object )
{
	this->getRootObject().addChild( object );
}
