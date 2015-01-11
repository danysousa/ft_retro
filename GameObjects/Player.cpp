/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:43 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 21:07:10 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Player.hpp"
# include "../GameComponents/DisplayComponent.hpp"
# include "../GameComponents/MoveKeyComponent.hpp"
# include "../GameComponents/DashBoardComponent.hpp"
# include "../GameEngine/Input.hpp"
# include "../GameEngine/CoreEngine.hpp"
# include "Bullet.hpp"
# include <sstream>

Player::Player() : GameObject(),
	_monsterKilled( 0 ),
	_lives( 3 )
{
	this->init( "player" );
	return ;
}

Player::Player( std::string const & display ) : GameObject(),
	_monsterKilled( 0 ),
	_lives( 3 )
{
	this->init( display );
	return ;
}

void		Player::init( std::string const & display )
{
	DisplayComponent *		dc = new DisplayComponent( display );
	MoveKeyComponent *		mkc = new MoveKeyComponent( KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, 0.7f );
	DashBoardComponent *	dbc = new DashBoardComponent( *this );

	this->addComponent( *dc );
	this->addComponent( *mkc );
	this->addComponent( *dbc );
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
		GameObject *	bullet = new Bullet( *this, "-", * new Vector2f( 1, 0 ) );
		bullet->setPos( *this->_pos );
		this->getCoreEngine().getGame().addObject( *bullet );
	}
	GameObject::input( delta );
}

void		Player::update( float delta )
{
	if ( this->_lives <= 0 )
		printw( "Game Over: press ESC to exit !" );
	else
		GameObject::update( delta );
}

void		Player::collideWhith( GameObject const & colided )
{
	// this->getParent().removeChild( *this );
	this->_lives--;
	(void)colided;
}

int			Player::getMonsterKilled() const
{
	return ( this->_monsterKilled );
}

void		Player::killAMonster()
{
	this->_monsterKilled++;
}

int			Player::getLives() const
{
	return ( this->_lives );
}

void		Player::setLives( int lives )
{
	this->_lives = lives;
}
