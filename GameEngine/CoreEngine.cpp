/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 10:59:24 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 18:10:37 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "CoreEngine.hpp"

CoreEngine::CoreEngine( double framerate, Game & game ) :
	_frameTime( 1 / framerate ),
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
		this->_frameTime = rhs.getFrameTime();
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
	double		lastTime = getTime();
	double		frameCounter = 0;
	double		unprocessedTime = 0;
	int			frames = 0;

	this->_game->init();
	while ( this->_isRunning )
	{
		bool		render = false;
		double		startTime = getTime();
		double		passedTime = startTime - lastTime;

		clear();

		lastTime = startTime;
		unprocessedTime += passedTime;
		frameCounter += passedTime;

		if ( frameCounter >= 1.0 )
		{
			frames = 0;
			frameCounter = 0;
		}
		while ( unprocessedTime > _frameTime )
		{
			// Input::update();

			mvwprintw( &getRenderEngine().getWindow(), 0, 0, "+" );

			render = true;
			unprocessedTime -= _frameTime;
		}
		if ( render )
		{
			this->_game->render( _frameTime );
			wrefresh( &getRenderEngine().getWindow() );
			frames++;
		}
		else
		{
			sleep( 1 );
		}
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

double			CoreEngine::getFrameTime() const
{
	return ( this->_frameTime );
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
