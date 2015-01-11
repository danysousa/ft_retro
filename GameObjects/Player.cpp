/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:43 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 15:56:29 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Player.hpp"
# include "../GameComponents/DisplayComponent.hpp"
# include "../GameComponents/MoveKeyComponent.hpp"
# include <ncurses.h>

Player::Player() : GameObject()
{
	this->init( "player" );
	return ;
}

Player::Player( std::string const & display ) : GameObject()
{
	this->init( display );
	return ;
}

void		Player::init( std::string const & display )
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
