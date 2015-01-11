/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:43 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 20:56:04 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Player.hpp"
# include "../GameComponents/DisplayComponent.hpp"
# include "../GameComponents/MoveKeyComponent.hpp"
# include "../GameEngine/Input.hpp"
# include "../GameEngine/CoreEngine.hpp"
# include "Bullet.hpp"
# include <sstream>

Player::Player() : GameObject()
{
	this->initConstructor( "player" );
	return ;
}

Player::Player( std::string const & display ) : GameObject()
{
	this->initConstructor( display );
	return ;
}
void		Player::init( CoreEngine & coreEngine )
{
	this->getPos().setY( coreEngine.getRenderEngine().getHeight() / 2 );

	return ;
}

void		Player::initConstructor( std::string const & display )
{
	DisplayComponent *	dc = new DisplayComponent( display );
	MoveKeyComponent *	mkc = new MoveKeyComponent( KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, 0.7f );
	this->addComponent( *mkc );
	this->addComponent( *dc );
}

Player::Player( Player const & src ) : GameObject( src )
{
	*this = src;
	return ;
}

Player::~Player()
{
	return ;
}

Player &	Player::operator=( Player const & rhs )
{
	GameObject::operator=( rhs );
	return ( *this );
}

void		Player::input( float delta )
{
	if ( Input::isKeyDown( ' ' ) )
	{
		GameObject *	bullet = new Bullet( "-", * new Vector2f( 1, 0 ) );
		bullet->setPos( *this->_pos );
		this->getCoreEngine().getGame().addObject( *bullet );
	}
	GameObject::input( delta );
}

void		Player::collideWhith( GameObject const & colided )
{
	this->getParent().removeChild( *this );
	(void)colided;
}
