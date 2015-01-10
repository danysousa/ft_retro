/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 09:46:01 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 14:14:16 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "CoreEngine.hpp"

int		main( void )
{
	Game *game = new Game();
	CoreEngine *engine = new CoreEngine( 60, *game );

	engine->createWindow();
	engine->start();

	delete engine;
	return ( 0 );
}
