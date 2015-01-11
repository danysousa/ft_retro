/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveIAComponent.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 15:32:44 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 18:06:44 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MoveIAComponent.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>

MoveIAComponent::MoveIAComponent( void ) : MoveComponent( 0 ), _deplacement( "random" )
{
	return ;
}

MoveIAComponent::MoveIAComponent( float speed, std::string deplacement ) : MoveComponent( speed ), _deplacement( deplacement )
{
	return ;
}

MoveIAComponent::MoveIAComponent( MoveIAComponent const & src ) : MoveComponent( src )
{
	*this = src;
}

MoveIAComponent::~MoveIAComponent( void )
{
	return ;
}

/*
** OPERATOR
*/

MoveIAComponent &		MoveIAComponent::operator=( MoveIAComponent const & rhs )
{
	MoveComponent::operator=( rhs );

	return (*this);
}

/*
** GET & SET
*/

void			MoveIAComponent::setDeplacement( std::string value )
{
	this->_deplacement = value;

	return ;
}

std::string		MoveIAComponent::getDeplacement( void )
{
	return ( this->_deplacement );
}

/*
** METHOD
*/

void			MoveIAComponent::input( float delta )
{
	this->random( delta );
	return ;
}


void			MoveIAComponent::random( float delta )
{
	float		y = sin( std::rand() );

	(void)delta;

	*this->_velocity = *this->_velocity * 0;
	*this->_velocity = *this->_velocity + ( Vector2f( -1.0f, y ) * this->_speed);
	return ;
}
