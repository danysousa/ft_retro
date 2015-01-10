/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 10:59:59 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 18:00:01 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE
# define CORE_ENGINE
# include <iostream>
# include <unistd.h>
# include "Game.hpp"
# include "RenderEngine.hpp"

class CoreEngine
{
public:
	CoreEngine( void );
	CoreEngine( CoreEngine const & src );
	CoreEngine( double framerate, Game & game );
	virtual ~CoreEngine( void );

	CoreEngine &	operator=( CoreEngine const & rhs );

	double			getFrameTime() const;
	Game &			getGame() const;
	bool			isRunning() const;
	RenderEngine &	getRenderEngine() const;

	bool			start();
	bool			stop();
	bool			createWindow();
	static unsigned	getTime();

private:
	int				run();

	double			_frameTime;
	Game *			_game;
	bool			_isRunning;
	RenderEngine *	_renderEngine;
};

#endif
