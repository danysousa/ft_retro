/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:19:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 20:23:38 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
# include "../GameComponents/MapLimit.hpp"

Map::Map( void ) : GameObject()
{
	MapLimit *		limit = new MapLimit();
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
