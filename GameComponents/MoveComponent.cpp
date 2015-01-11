/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveComponent.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:02:51 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 11:51:55 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MoveComponent.hpp"
#include <ncurses.h>

MoveComponent::MoveComponent( void ) :
GameComponent(),
_keyUp( KEY_UP ),
_keyDown( KEY_DOWN ),
_keyLeft( KEY_LEFT ),
_keyRight( KEY_RIGHT )
{
	return ;
}

MoveComponent::MoveComponent( int up, int down, int left, int right ) :
GameComponent(),
_keyUp( up ),
_keyDown( down ),
_keyLeft( left ),
_keyRight( right )
{
	return ;
}

MoveComponent::MoveComponent( MoveComponent const & src ) :
GameComponent( src )
{
	*this = src;
}

MoveComponent::~MoveComponent( void )
{
	return ;
}

/*
** OPERATOR
*/

MoveComponent &		MoveComponent::operator=( MoveComponent const & rhs )
{
	this->_keyUp = rhs.getKeyUp();
	this->_keyDown = rhs.getKeyDown();
	this->_keyLeft = rhs.getKeyLeft();
	this->_keyRight = rhs.getKeyRight();

	return (*this);
}

/*
** SET & GET
*/

void		MoveComponent::setKeyUp( int key )
{
	this->_keyUp = key;
}

void		MoveComponent::setKeyDown( int key )
{
	this->_keyDown = key;
}

void		MoveComponent::setKeyLeft( int key )
{
	this->_keyLeft = key;
}

void		MoveComponent::setKeyRight( int key )
{
	this->_keyRight = key;
}

int			MoveComponent::getKeyUp( void ) const
{
	return (this->_keyUp);
}

int			MoveComponent::getKeyDown( void ) const
{
	return (this->_keyDown);
}

int			MoveComponent::getKeyLeft( void ) const
{
	return (this->_keyLeft);
}

int			MoveComponent::getKeyRight( void ) const
{
	return (this->_keyRight);
}

/*
** METHOD
*/

// void		MoveComponent::up( void )
// {

// }
