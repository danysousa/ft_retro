/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:54:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 18:51:38 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "GameObject.hpp"

GameObject::GameObject() :
	_pos( new Vector2f( 0, 0 ) ),
	_nbChildrens( 0 ),
	_nbComponents( 0 )
{
	return ;
}

GameObject::GameObject( GameObject const & src ) :
	_pos( new Vector2f( 0, 0 ) ),
	_nbChildrens( 0 ),
	_nbComponents( 0 )
{
	*this = src;
	return ;
}

GameObject::~GameObject()
{
	return ;
}

GameObject &	GameObject::operator=( GameObject const & rhs )
{
	if ( this != &rhs )
	{
		this->_pos = &rhs.getPos();
	}
	return ( *this );
}

void			GameObject::addChild( GameObject & child )
{
	if ( !this->_childrens )
		this->_childrens = new GameObject[256];
	this->_childrens[this->_nbChildrens] = child;
	this->_nbChildrens++;
}

void			GameObject::addComponent( GameComponent & component )
{
	if ( !this->_components )
		this->_components = new GameComponent[256];
	this->_components[this->_nbComponents] = component;
	this->_nbComponents++;
}

void 			GameObject::renderAll( RenderEngine & renderEngine )
{
	render( renderEngine );

	for ( int i = 0; i < this->_nbChildrens; ++i )
		this->_childrens[i].renderAll( renderEngine );
}

void			GameObject::render( RenderEngine & renderEngine )
{
	for ( int i = 0; i < this->_nbComponents; ++i )
		this->_components[i].render( renderEngine );
}

Vector2f &		GameObject::getPos() const
{
	return ( *this->_pos );
}
