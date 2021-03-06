/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:19:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 21:36:38 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
# include "../GameComponents/MapLimitComponent.hpp"

Map::Map( void ) : GameObject()
{
	MapLimitComponent *		limit = new MapLimitComponent();
	this->addComponent( *limit );

	return ;
}

Map::Map( Map & cpy ) : GameObject( cpy )
{
	*this = cpy;
}

Map::~Map( void )
{
	return ;
}

Map &		Map::operator=( Map & rhs )
{
	GameObject::operator=( rhs );
	return ( *this );
}
