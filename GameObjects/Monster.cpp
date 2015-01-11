/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 15:00:36 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 16:26:11 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.hpp"
# include "../GameComponents/DisplayComponent.hpp"
# include "../GameComponents/MoveIAComponent.hpp"
#include <cstdlib>
#include <ctime>


Monster::Monster( void ) : GameObject()
{
	std::srand(std::time(0));
	this->init( "Monster" );

	return ;
}

Monster::Monster( std::string const & display ) : GameObject()
{
	this->init( display );

	return ;
}

Monster::Monster( Monster & cpy ) : GameObject( cpy )
{
	*this = cpy;
}

Monster::~Monster( void )
{
	return ;
}

Monster &		Monster::operator=( Monster & rhs )
{
	GameObject::operator=( rhs );
	return ( *this );
}

void			Monster::init( std::string const & display )
{
	// int					y = ( std::rand() % this->getParent()->getHeight() ) * - 1;

	// this->setPos( Vector2f( this->getParent()->getWidth(), y ) );

	DisplayComponent *	dc = new DisplayComponent( display );
	// MoveIAComponent *	mkc = new MoveIAComponent( ( 4 / 60 ) );

	// this->addComponent( *mkc );
	this->addComponent( *dc );
}
