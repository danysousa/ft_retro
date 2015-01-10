/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2f.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:45:04 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/10 14:25:06 by dsousa           ###   ########.fr       */
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
** METHODE
*/

float			Vector2f::length( void )
{
	return ( sqrt( this->_x * this->_x + this->_y * this->_y ) );
}

// Vector2f		Vector2f::rotate( float angle )
// {
// 	double		rad = angle / 180 * this->_pi;

// }


/*
** OPERATOR
*/

Vector2f &		Vector2f::operator=( Vector2f & rhs )
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();

	return ( *this );
}

Vector2f &		Vector2f::operator+( Vector2f & rhs ) const
{
	float	x = this->_x + rhs.getX();
	float	y = this->_y + rhs.getY();

	Vector2f *tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator-( Vector2f & rhs ) const
{
	float	x = rhs.getX() - this->_x;
	float	y = rhs.getY() - this->_y;

	Vector2f *tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator*( float rhs ) const
{
	float	x = this->_x * rhs;
	float	y = this->_y * rhs;

	Vector2f *tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator*( int rhs ) const
{
	float	x = this->_x * (float)rhs;
	float	y = this->_y * (float)rhs;

	Vector2f *tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator*( Vector2f & rhs ) const
{
	float	x = this->_x * rhs.getX();
	float	y = this->_y * rhs.getY();

	Vector2f *tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator/( float rhs ) const
{
	float	x = this->_x / rhs;
	float	y = this->_y / rhs;

	Vector2f *tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator/( int rhs ) const
{
	float	x = this->_x / (float)rhs;
	float	y = this->_y / (float)rhs;

	Vector2f *tmp = new Vector2f( x, y );

	return ( *tmp );
}

Vector2f &		Vector2f::operator/( Vector2f & rhs ) const
{
	float	x = this->_x / rhs.getX();
	float	y = this->_y / rhs.getY();

	Vector2f *tmp = new Vector2f( x, y );

	return ( *tmp );
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
