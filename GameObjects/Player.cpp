/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:43 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 22:30:37 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Player.hpp"
# include "../GameComponents/DisplayComponent.hpp"

Player::Player() : GameObject()
{
	return ;
}

Player::Player( std::string const & display ) : GameObject()
{
	DisplayComponent *	dc = new DisplayComponent( display );
	this->addComponent( *dc );

	return ;
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
