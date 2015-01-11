/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameComponent.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:46:45 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 15:32:03 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "GameComponent.hpp"

GameComponent::GameComponent()
{
	return ;
}

GameComponent::GameComponent( GameComponent const & src )
{
	*this = src;
	return ;
}

GameComponent::~GameComponent()
{
	return ;
}

GameComponent &	GameComponent::operator=( GameComponent const & rhs )
{
	if ( this != &rhs )
	{
		this->_parent = &rhs.getParent();
	}
	return ( *this );
}

void			GameComponent::input( float delta )
{
	(void)delta;
}

void			GameComponent::update( float delta )
{
	(void)delta;
}

void			GameComponent::render( RenderEngine & renderEngine )
{
	(void)renderEngine;
}

GameObject &	GameComponent::getParent() const
{
	return ( *this->_parent );
}

void			GameComponent::setParent( GameObject & parent )
{
	this->_parent = &parent;
}
