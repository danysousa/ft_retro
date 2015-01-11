/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackgroundFileComponent.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 21:39:55 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 23:40:19 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BackgroundFileComponent.hpp"
# include "../GameEngine/GameObject.hpp"
# include "../GameEngine/CoreEngine.hpp"
# include <fstream>
# include <string>
// # include <algorithm>

BackgroundFileComponent::BackgroundFileComponent( void ) : GameComponent(),
_frame( 0 ),
_rank( 0 )
{
	return ;
}

BackgroundFileComponent::BackgroundFileComponent( BackgroundFileComponent const & src ) : GameComponent( src )
{
	*this = src;
	return ;
}

BackgroundFileComponent::~BackgroundFileComponent()
{
	return ;
}

BackgroundFileComponent &	BackgroundFileComponent::operator=( BackgroundFileComponent const & rhs )
{
	(void)rhs;
	return ( *this );
}

void				BackgroundFileComponent::render( RenderEngine & renderEngine )
{
	std::ifstream		file("1.background");
	std::string			str;
	int					i = this->getParent().getCoreEngine().getRenderEngine().getHeight() - 2;

	while ( std::getline( file, str ) && i > 1 )
	{
		if ( this->_rank == str.length() )
		this->_rank = this->_rank % str.length();
		mvwprintw( &renderEngine.getWindow(), i, this->getParent().getCoreEngine().getRenderEngine().getWidth() - this->_rank, str.c_str() );
		i--;
	}
	this->_frame++;
	this->_rank++;
	return ;
}
