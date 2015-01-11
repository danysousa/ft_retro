/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:19:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 21:36:38 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Background.hpp"
# include "../GameComponents/BackgroundFileComponent.hpp"

Background::Background( void ) : GameObject()
{
	BackgroundFileComponent *		limit = new BackgroundFileComponent();
	this->addComponent( *limit );

	return ;
}

Background::Background( Background & cpy ) : GameObject( cpy )
{
	*this = cpy;
}

Background::~Background( void )
{
	return ;
}

Background &		Background::operator=( Background & rhs )
{
	GameObject::operator=( rhs );
	return ( *this );
}
