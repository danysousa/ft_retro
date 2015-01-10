/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2f.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:45:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/10 12:01:05 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2f.hpp"

/*
** CONSTRUCT & DESTRUCT
*/

Vector2f::Vector2f( void ) : _x( 0 ), _y( 0 )
{

}

Vector2f::Vector2f( int x, int y ) : _x( x ), _y( y )
{

}

Vector2f::Vector2f( Vector2f & cpy )
{
	*this = cpy;

	return ;
}

Vector2f::~Vector2f( void )
{
	return ;
}

/*
** OPERATOR
*/

Vector2f		& Vector2f::operator=( Vector2f & lhs )
{
	this->_x = lhs.getX();
	this->_y = lhs.getY();

	return ( *this );
}

/*
** GETTER & SETTER
*/

float			Vector2f::getX( void ) const
{
	return ( this->_x );
}

float			Vector2f::getY( void ) const
{
	return ( this->_y );
}

void			Vector2f::setX( float x )
{
	this->_x = x;

	return ;
}

void			Vector2f::setY( float y )
{
	this->_y = y;

	return ;
}
