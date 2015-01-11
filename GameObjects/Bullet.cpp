/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:43 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 20:37:06 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <typeinfo>
# include "Bullet.hpp"
# include "Monster.hpp"
# include "../GameComponents/DisplayComponent.hpp"
# include "../GameComponents/MoveComponent.hpp"

Bullet::Bullet() : GameObject(),
	_owner( 0 )
{
	this->init( "-", * new Vector2f( 1, 0 ) );
	return ;
}

Bullet::Bullet( Player & owner, std::string const & display, Vector2f & velocity ) : GameObject(),
	_owner( &owner )
{
	this->init( display, velocity );
	return ;
}

void		Bullet::init( std::string const & display, Vector2f & velocity )
{
	DisplayComponent *	dc = new DisplayComponent( display );
	MoveComponent *	mc = new MoveComponent( 1 );
	mc->setVelocity( velocity );
	this->addComponent( *mc );
	this->addComponent( *dc );
}

Bullet::Bullet( Bullet const & src ) : GameObject( src )
{
	*this = src;
	return ;
}

Bullet::~Bullet()
{
	return ;
}

Bullet &	Bullet::operator=( Bullet const & rhs )
{
	GameObject::operator=( rhs );
	this->_owner = &rhs.getOwner();
	return ( *this );
}

Player &	Bullet::getOwner() const
{
	return ( *this->_owner );
}

void		Bullet::collideWhith( GameObject const & colided )
{
	if ( typeid(colided) == typeid(Monster) )
	{
		this->_owner->killAMonster();
	}
}
