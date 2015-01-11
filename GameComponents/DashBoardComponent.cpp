/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DashBoardComponent.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:44:43 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 20:58:14 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DashBoardComponent.hpp"
# include "../GameComponents/MoveComponent.hpp"
# include <sstream>

DashBoardComponent::DashBoardComponent() : GameComponent()
{
	return ;
}

DashBoardComponent::DashBoardComponent( Player & player ) : GameComponent(),
	_player( &player )
{
	return ;
}

DashBoardComponent::DashBoardComponent( DashBoardComponent const & src ) : GameComponent( src )
{
	*this = src;
	return ;
}

DashBoardComponent::~DashBoardComponent()
{
	return ;
}

DashBoardComponent &	DashBoardComponent::operator=( DashBoardComponent const & rhs )
{
	GameComponent::operator=( rhs );
	return ( *this );
}

void		DashBoardComponent::render( RenderEngine & renderEngine )
{
	for ( int i = 0; i < renderEngine.getWidth(); i++ )
	{
		mvwprintw( &renderEngine.getWindow(), renderEngine.getHeight(), i, "*" );
	}

	std::stringstream ss;

	ss << "You killed " << this->_player->getMonsterKilled() << " monster" << std::endl;
	ss << "     You have " << this->_player->getLives() << " lives";

	mvwprintw( &renderEngine.getWindow(), renderEngine.getHeight() + 2, 5, ss.str().c_str() );
}
