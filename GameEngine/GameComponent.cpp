/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameComponent.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:46:45 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 22:41:24 by rbenjami         ###   ########.fr       */
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
		// this->_parent = &rhs.getParent();
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
	// printw("pok");
	(void)renderEngine;
}

// GameObject &	GameComponent::getParent() const
// {
// 	return ( *this->_parent );
// }
