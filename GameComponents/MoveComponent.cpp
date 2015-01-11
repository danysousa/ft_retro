/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveComponent.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 12:13:15 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 15:55:26 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MoveComponent.hpp"
#include "../GameEngine/GameObject.hpp"

MoveComponent::MoveComponent( void ) : GameComponent(), _velocity( new Vector2f( 0, 0 ) ), _speed( 0 )
{
	return ;
}

MoveComponent::MoveComponent( float speed ) : GameComponent(), _velocity( new Vector2f( 0, 0 ) ), _speed( speed )
{
	return ;
}

MoveComponent::MoveComponent( MoveComponent const & src ) : GameComponent( src )
{
	*this = src;
}

MoveComponent::~MoveComponent( void )
{
	return ;
}

MoveComponent &		MoveComponent::MoveComponent::operator=( MoveComponent const & rhs )
{
	this->_velocity = rhs.getVelocity();
	this->_speed = rhs.getSpeed();

	return ( *this );
}

Vector2f			*MoveComponent::getVelocity( void ) const
{
	return ( this->_velocity );
}

float				MoveComponent::getSpeed( void ) const
{
	return ( this->_speed );
}

void				MoveComponent::setVelocity( Vector2f *value )
{
	this->_velocity = value;

	return ;
}

void				MoveComponent::setSpeed( float value )
{
	this->_speed = value;

	return ;
}

void				MoveComponent::update( float delta )
{
	(void)delta;
	Vector2f *		current_pos = &this->getParent().getPos();

	this->getParent().setPos(*current_pos + *this->_velocity);

	return ;
}
