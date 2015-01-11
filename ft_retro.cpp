/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 09:46:01 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 16:44:29 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "GameEngine/CoreEngine.hpp"
# include "FtRetroGame.hpp"

int		main( void )
{
	Game *game = new FtRetroGame();
	CoreEngine *engine = new CoreEngine( 60, *game );

	engine->createWindow();
	engine->start();

	delete engine;
	return ( 0 );
}
