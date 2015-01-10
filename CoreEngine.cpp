/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 10:59:24 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 14:20:31 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "CoreEngine.hpp"

CoreEngine::CoreEngine( double framerate, Game & game ) :
	_framerate( framerate ),
	_game( &game ),
	_isRunning( false )
{
	return ;
}

CoreEngine::CoreEngine( CoreEngine const & src )
{
	*this = src;
}

CoreEngine::~CoreEngine()
{
	return ;
}

CoreEngine &	CoreEngine::operator=( CoreEngine const & rhs )
{
	if ( this != &rhs )
	{
		this->_framerate = rhs.getFramerate();
		this->_game = &rhs.getGame();
		this->_isRunning = rhs.isRunning();
		this->_renderEngine = &rhs.getRenderEngine();
	}
	return ( *this );
}

bool			CoreEngine::createWindow()
{
	this->_renderEngine = new RenderEngine();
	return ( true );
}

bool			CoreEngine::start()
{
	if ( this->_isRunning )
		return ( false );
	this->_isRunning = true;
	this->run();
	return ( true );
}

bool			CoreEngine::stop()
{
	if ( this->_isRunning )
		return ( false );
	this->_isRunning = false;
	return ( true );
}

int				CoreEngine::run()
{
	unsigned	startTime;
	unsigned	endTime;

	this->_game->init();
	while ( this->_isRunning )
	{
		startTime = CoreEngine::getTime();
		clear();
		// this->_game->inputGame();
		// this->_game->updateGame();
		// this->_game->renderGame();
		refresh();
		endTime = CoreEngine::getTime();
		usleep( ( 60 / this->_framerate ) - ( endTime - startTime ) );
	}
	return (0);
}

/**
 * GETTER
 */
unsigned		CoreEngine::getTime()
{
	return ( (unsigned)time( NULL ) );
}

double			CoreEngine::getFramerate() const
{
	return ( this->_framerate );
}

Game &			CoreEngine::getGame() const
{
	return ( *this->_game );
}

RenderEngine &	CoreEngine::getRenderEngine() const
{
	return ( *this->_renderEngine );
}

bool			CoreEngine::isRunning() const
{
	return ( this->_isRunning );
}
