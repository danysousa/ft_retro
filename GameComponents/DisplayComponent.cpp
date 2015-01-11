/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayComponent.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:41:48 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 12:41:58 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DisplayComponent.hpp"
# include "../GameEngine/GameObject.hpp"

DisplayComponent::DisplayComponent() : GameComponent()
{
	return ;
}

DisplayComponent::DisplayComponent( std::string const & display ) : GameComponent(),
	_display( display )
{
	return ;
}

DisplayComponent::DisplayComponent( DisplayComponent const & src ) : GameComponent( src )
{
	*this = src;
	return ;
}

DisplayComponent::~DisplayComponent()
{
	return ;
}

DisplayComponent &	DisplayComponent::operator=( DisplayComponent const & rhs )
{
	if ( this != &rhs )
	{
		this->_display = rhs.getDisplay();
	}
	return ( *this );
}

std::string			DisplayComponent::getDisplay() const
{
	return ( this->_display );
}

void				DisplayComponent::input( float delta )
{
	(void)delta;
}

void				DisplayComponent::update( float delta )
{
	(void)delta;
}


void				DisplayComponent::render( RenderEngine & renderEngine )
{
	int		x = this->getParent().getPos().getX();
	int		y = this->getParent().getPos().getY();
	mvwprintw( &renderEngine.getWindow(), y, x, this->_display.c_str() );
}
