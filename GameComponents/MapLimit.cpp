/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapLimit.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:27:42 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 21:15:34 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MapLimit.hpp"
# include "../GameEngine/GameObject.hpp"
# include "../GameEngine/CoreEngine.hpp"

MapLimit::MapLimit( void ) : GameComponent(),
_first( "=" ),
_second( "_" ),
_rank( 0 ),
_frame( 0 )
{
	this->update( 0 );
	return ;
}

MapLimit::MapLimit( MapLimit const & src ) : GameComponent( src )
{
	*this = src;
	return ;
}

MapLimit::~MapLimit()
{
	return ;
}

MapLimit &	MapLimit::operator=( MapLimit const & rhs )
{
	this->_first = rhs.getFirst();
	this->_second = rhs.getSecond();
	this->_rank = rhs.getRank();
	this->_display = rhs.getDisplay();

	return ( *this );
}

std::string				MapLimit::getFirst( void ) const
{
	return (this->_first);
}

std::string				MapLimit::getSecond( void ) const
{
	return (this->_second);
}

int						MapLimit::getRank( void ) const
{
	return (this->_rank);
}

std::string				MapLimit::getDisplay( void ) const
{
	return (this->_display);
}

void					MapLimit::setFirst( std::string value )
{
	this->_first = value;

	return ;
}

void					MapLimit::setSecond( std::string value )
{
	this->_second = value;

	return ;
}

void				MapLimit::input( float delta )
{
	int			i = 0;
	int			size = this->getParent().getCoreEngine().getRenderEngine().getWidth();
	int			first = this->_rank;

	if ( this->_frame != 0 )
	{
		this->_frame = ( this->_frame + 1 ) % 7;
		return ;
	}
	this->_display = "";
	while ( i++ < size )
	{
		if ( this->_rank )
			this->_display += this->_first;
		else
			this->_display += this->_second;

		this->_rank = ( this->_rank + 1 ) % 2;
	}

	this->_frame = ( this->_frame + 1 ) % 7;
	this->_rank = ( first + 1 ) % 2;
	(void)delta;
}


void				MapLimit::render( RenderEngine & renderEngine )
{
	mvwprintw( &renderEngine.getWindow(), 0, 0, this->_display.c_str() );
	mvwprintw( &renderEngine.getWindow(), this->getParent().getCoreEngine().getRenderEngine().getHeight() - 1, 0, this->_display.c_str() );
}
