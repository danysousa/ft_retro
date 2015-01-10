/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 14:06:31 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Game.hpp"

Game::Game()
{
	return ;
}

Game::Game( Game const & src )
{
	*this = src;
	return ;
}

Game::~Game()
{
	return ;
}

Game &	Game::operator=( Game const & rhs )
{
	if ( this != &rhs )
	{
	}
	return ( *this );
}

bool	Game::init()
{
	return ( true );
}
