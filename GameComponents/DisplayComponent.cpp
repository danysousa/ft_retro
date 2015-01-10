/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayComponent.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:41:48 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 22:40:53 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DisplayComponent.hpp"

DisplayComponent::DisplayComponent() : GameComponent()
{
	return ;
}

DisplayComponent::DisplayComponent( std::string const & display ) : GameComponent(),
	_display( display )
{
	return ;
}

DisplayComponent::DisplayComponent( DisplayComponent const & src ) : GameComponent()
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

void				DisplayComponent::render( RenderEngine & renderEngine )
{
	printw("pok");
	(void)renderEngine;
	// mvwprintw( &renderEngine.getWindow(), 0, 0, this->_display.c_str() );
}
