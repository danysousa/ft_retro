/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 10:59:24 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 11:23:15 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>
# include <sstream>
# include "CoreEngine.hpp"
# include "Input.hpp"

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
	if ( !this->_isRunning )
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
		startTime = getTime();
		clear();
		Input::update();
		if ( Input::isKeyDown( KEY_LEFT ) )
			this->stop();
		this->_game->input( _framerate );
		this->_game->update( _framerate );
		this->_game->render( *this->_renderEngine );
		wrefresh( &getRenderEngine().getWindow() );
		// std::stringstream o;
		// o << ( endTime - startTime );
		// printw(o.str().c_str());
		refresh();
		endTime = getTime();
		usleep( ( 1000000 / this->_framerate ) - ( endTime - startTime ) );
	}
	delwin( &getRenderEngine().getWindow() );
	endwin();
	return (0);
}

/**
 * GETTER
 */
unsigned		CoreEngine::getTime()
{
	timeval curTime;
	gettimeofday(&curTime, 0);
	return ( (unsigned)curTime.tv_usec );
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
