/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monster.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 15:00:36 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 20:19:42 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monster.hpp"
#include "../GameComponents/DisplayComponent.hpp"
#include "../GameComponents/MoveIAComponent.hpp"
#include "../GameEngine/CoreEngine.hpp"
#include <cstdlib>
#include <ctime>

Monster::Monster( void ) : GameObject()
{
	std::srand(std::time(0));
	this->initConstructor( "Monster" );

	return ;
}

Monster::Monster( std::string const & display ) : GameObject()
{
	this->initConstructor( display );

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

void			Monster::init( CoreEngine & coreEngine )
{
	int			y = ( std::rand() % coreEngine.getRenderEngine().getHeight() ) - 1;

	this->setPos( * new Vector2f( coreEngine.getRenderEngine().getWidth() - 1, y ) );
}

void			Monster::initConstructor( std::string const & display )
{
	DisplayComponent *	dc = new DisplayComponent( display );
	MoveIAComponent *	mkc = new MoveIAComponent( 0.5f, "random" );

	this->addComponent( *mkc );
	this->addComponent( *dc );
}
