/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveKeyComponent.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:02:51 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 19:11:37 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MoveKeyComponent.hpp"
#include "../GameEngine/Input.hpp"
#include "../GameEngine/CoreEngine.hpp"
#include <ncurses.h>

MoveKeyComponent::MoveKeyComponent( void ) :
MoveComponent( 0 ),
_keyUp( KEY_UP ),
_keyDown( KEY_DOWN ),
_keyLeft( KEY_LEFT ),
_keyRight( KEY_RIGHT ),
_isKeyUp( false ),
_isKeyDown( false ),
_isKeyLeft( false ),
_isKeyRight( false )
{
	return ;
}

MoveKeyComponent::MoveKeyComponent( int up, int down, int left, int right, float speed ) :
MoveComponent( speed ),
_keyUp( up ),
_keyDown( down ),
_keyLeft( left ),
_keyRight( right ),
_isKeyUp( false ),
_isKeyDown( false ),
_isKeyLeft( false ),
_isKeyRight( false )
{
	return ;
}

MoveKeyComponent::MoveKeyComponent( MoveKeyComponent const & src ) : MoveComponent( src )
{
	*this = src;
}

MoveKeyComponent::~MoveKeyComponent( void )
{
	return ;
}

/*
** OPERATOR
*/

MoveKeyComponent &		MoveKeyComponent::operator=( MoveKeyComponent const & rhs )
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

void		MoveKeyComponent::setKeyUp( int key )
{
	this->_keyUp = key;
}

void		MoveKeyComponent::setKeyDown( int key )
{
	this->_keyDown = key;
}

void		MoveKeyComponent::setKeyLeft( int key )
{
	this->_keyLeft = key;
}

void		MoveKeyComponent::setKeyRight( int key )
{
	this->_keyRight = key;
}

int			MoveKeyComponent::getKeyUp( void ) const
{
	return (this->_keyUp);
}

int			MoveKeyComponent::getKeyDown( void ) const
{
	return (this->_keyDown);
}

int			MoveKeyComponent::getKeyLeft( void ) const
{
	return (this->_keyLeft);
}

int			MoveKeyComponent::getKeyRight( void ) const
{
	return (this->_keyRight);
}

/*
** METHOD
*/

void		MoveKeyComponent::input( float delta )
{
	this->up( delta );
	this->down( delta );
	this->left( delta );
	this->right( delta );

	return ;
}

void		MoveKeyComponent::up( float delta )
{
	(void)delta;

	if ( Input::isKeyDown(this->_keyUp) && this->_isKeyUp == false )
	{
		*this->_velocity = *this->_velocity + ( Vector2f( 0, -1 ) * this->_speed );
		this->_isKeyUp = true;
	}
	else if ( !Input::isKeyDown(this->_keyUp) && this->_isKeyUp == true )
	{
		*this->_velocity = *this->_velocity * 0;
		this->_isKeyUp = false;
	}

	return ;
}

void		MoveKeyComponent::down( float delta )
{
	(void)delta;
	// Vector2f *test = new Vector2f( 0, 1 );

	if ( Input::isKeyDown(this->_keyDown) && this->_isKeyDown == false )
	{
		*this->_velocity = *this->_velocity + ( Vector2f( 0, 1 ) * this->_speed );
		this->_isKeyDown = true;
	}
	else if ( !Input::isKeyDown(this->_keyDown) && this->_isKeyDown == true )
	{
		*this->_velocity = *this->_velocity * 0;
		this->_isKeyDown = false;
	}

	return ;
}

void		MoveKeyComponent::left( float delta )
{
	(void)delta;

	if ( Input::isKeyDown(this->_keyLeft) && this->_isKeyLeft == false )
	{
		*this->_velocity = *this->_velocity + ( Vector2f( -2, 0 ) * this->_speed );
		if ( this->getParent().getPos().getX() <= 0 )
			this->_velocity->setX( 0 );

		this->_isKeyLeft = true;
	}
	else if ( !Input::isKeyDown(this->_keyLeft) && this->_isKeyLeft == true )
	{
		*this->_velocity = *this->_velocity * 0;
		this->_isKeyLeft = false;
	}

	return ;
}

void		MoveKeyComponent::right( float delta )
{
	(void)delta;

	if ( Input::isKeyDown(this->_keyRight) && this->_isKeyRight == false )
	{
		*this->_velocity = *this->_velocity + ( Vector2f( 2, 0 ) * this->_speed );
		if ( this->getParent().getPos().getX() + 2 >= this->getParent().getCoreEngine().getRenderEngine().getWidth() )
			this->_velocity->setX( 0 );

		this->_isKeyRight = true;
	}
	else if ( !Input::isKeyDown(this->_keyRight) && this->_isKeyRight == true )
	{
		*this->_velocity = *this->_velocity * 0;
		this->_isKeyRight = false;
	}

	return ;
}
