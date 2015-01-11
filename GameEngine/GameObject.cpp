/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:54:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 11:49:35 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
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
		// this->_childrens = &rhs.getChildrens();
		this->_nbChildrens = rhs.getNbChildrens();
		// this->_components = &rhs.getComponents();
		this->_nbComponents = rhs.getNbComponents();
	}
	return ( *this );
}

void			GameObject::addChild( GameObject & child )
{
	this->_childrens[this->_nbChildrens] = &child;
	this->_nbChildrens++;
}

void			GameObject::addComponent( GameComponent & component )
{
	this->_components[this->_nbComponents] = &component;
	this->_components[this->_nbComponents]->setParent( *this );
	this->_nbComponents++;
}

void 			GameObject::renderAll( RenderEngine & renderEngine )
{
	render( renderEngine );

	for ( int i = 0; i < this->_nbChildrens; i++ )
		this->_childrens[i]->renderAll( renderEngine );
}

void			GameObject::render( RenderEngine & renderEngine )
{
	for ( int i = 0; i < this->_nbComponents; i++ )
	{
		this->_components[i]->render( renderEngine );
	}
}

void 			GameObject::inputAll( float delta )
{
	input( delta );

	for ( int i = 0; i < this->_nbChildrens; i++ )
		this->_childrens[i]->inputAll( delta );
}

void			GameObject::input( float delta )
{
	for ( int i = 0; i < this->_nbComponents; i++ )
	{
		this->_components[i]->input( delta );
	}
}

void 			GameObject::updateAll( float delta )
{
	update( delta );

	for ( int i = 0; i < this->_nbChildrens; i++ )
		this->_childrens[i]->updateAll( delta );
}

void			GameObject::update( float delta )
{
	for ( int i = 0; i < this->_nbComponents; i++ )
	{
		this->_components[i]->update( delta );
	}
}

Vector2f &			GameObject::getPos() const
{
	return ( *this->_pos );
}

// GameObject &		GameObject::getChildrens() const
// {
// 	return ( *this->_childrens );
// }

int					GameObject::getNbChildrens() const
{
	return ( this->_nbChildrens );
}

// GameComponent &		GameObject::getComponents() const
// {
// 	return ( *this->_components );
// }

int					GameObject::getNbComponents() const
{
	return ( this->_nbComponents );
}

