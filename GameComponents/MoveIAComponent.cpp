/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveIAComponent.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 15:32:44 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 16:44:01 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MoveIAComponent.hpp"
#include <cstdlib>
#include <ctime>

MoveIAComponent::MoveIAComponent( void ) : MoveComponent( 0 ), _deplacement( "random" )
{
	std::srand(std::time(0));
	return ;
}

MoveIAComponent::MoveIAComponent( float speed, std::string deplacement ) : MoveComponent( speed ), _deplacement( deplacement )
{
	std::srand(std::time(0));
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

void			MoveIAComponent::render( float delta )
{
	this->random( delta );
	return ;
}


void			MoveIAComponent::random( float delta )
{
	int			x = ( std::rand() % 2 ) * - 1;
	int			y = ( std::rand() % 2 ) * - 1;

	(void)delta;

	*this->_velocity = *this->_velocity * 0;
	*this->_velocity = *this->_velocity + ( Vector2f( x, y ) * this->_speed );
	return ;
}
