/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:43 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 16:07:25 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bullet.hpp"
# include "../GameComponents/DisplayComponent.hpp"
# include "../GameComponents/MoveComponent.hpp"

Bullet::Bullet() : GameObject()
{
	this->init( "-", * new Vector2f( 1, 0 ) );
	return ;
}

Bullet::Bullet( std::string const & display, Vector2f & velocity ) : GameObject()
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
	return ( *this );
}
