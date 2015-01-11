/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderEngine.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 16:44:59 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RenderEngine.hpp"

RenderEngine::RenderEngine()
{
	initscr();
	start_color();
	noecho();
	curs_set( false );
	getmaxyx( stdscr, this->_height, this->_width );
	this->_window = stdscr;
	nodelay( stdscr, true );
	keypad( stdscr, true );
	return ;
}

RenderEngine::RenderEngine( RenderEngine const & src )
{
	*this = src;
	return ;
}

RenderEngine::~RenderEngine()
{
	return ;
}

RenderEngine &	RenderEngine::operator=( RenderEngine const & rhs )
{
	if ( this != &rhs )
	{
	}
	return ( *this );
}

WINDOW &		RenderEngine::getWindow() const
{
	return ( *this->_window );
}

int				RenderEngine::getWidth() const
{
	return ( this->_width );
}

int				RenderEngine::getHeight() const
{
	return ( this->_height );
}
