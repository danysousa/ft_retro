/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:54:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 19:17:10 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
# include "GameObject.hpp"

GameObject::GameObject() :
	_pos( new Vector2f( 0, 0 ) ),
	_nbChildrens( 0 ),
	_nbComponents( 0 ),
	_coreEngine( 0 )
{
	return ;
}

GameObject::GameObject( GameObject const & src ) :
	_pos( new Vector2f( 0, 0 ) ),
	_nbChildrens( 0 ),
	_nbComponents( 0 ),
	_coreEngine( 0 )
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
		this->_coreEngine = &rhs.getCoreEngine();
	}
	return ( *this );
}

void			GameObject::addChild( GameObject & child )
{
	this->_childrens[this->_nbChildrens] = &child;
	this->_childrens[this->_nbChildrens]->setCoreEngine( *this->_coreEngine );
	this->_childrens[this->_nbChildrens]->init( *this->_coreEngine );
	this->_childrens[this->_nbChildrens]->_index = this->_nbChildrens;
	this->_childrens[this->_nbChildrens]->_parent = this;
	this->_nbChildrens++;
}

void			GameObject::removeChild( GameObject & child )
{
	// delete this->_childrens[child._index];
	// this->_childrens[child._index] = 0;
	this->_childrens[child._index]->_dead = true;
}

void			GameObject::addComponent( GameComponent & component )
{
	this->_components[this->_nbComponents] = &component;
	this->_components[this->_nbComponents]->setParent( *this );
	this->_nbComponents++;
}

void			GameObject::init( CoreEngine & coreEngine )
{
	(void)coreEngine;
	return ;
}

void 			GameObject::renderAll( RenderEngine & renderEngine )
{
	render( renderEngine );

	for ( int i = 0; i < this->_nbChildrens; i++ )
	{
		if ( this->_childrens[i] && !this->_childrens[i]->_dead )
			this->_childrens[i]->renderAll( renderEngine );
	}
}

void			GameObject::render( RenderEngine & renderEngine )
{
	for ( int i = 0; i < this->_nbComponents; i++ )
	{
		this->_components[i]->render( renderEngine );
	}
}

# include <sstream>

void 			GameObject::physicAll( float delta )
{
	(void)delta;
	// int		nbChildrens = this->getNbOfAllChildrens();
	// GameObject * childrens = this->getAllChildrens();
	int		nbChildrens = this->_nbChildrens;
	// GameObject * childrens = *this->_childrens;

	for ( int i = 0; i < nbChildrens; i++ )
	{
		if ( this->_childrens[i] && !this->_childrens[i]->_dead )
		{
			for (int j = i + 1; j < nbChildrens; ++j)
			{
				if ( this->_childrens[j] && !this->_childrens[j]->_dead )
				{
					if ( this->collide( *this->_childrens[i], *this->_childrens[j] ) )
					{
						this->_childrens[i]->collideWhith( *this->_childrens[j] );
						this->_childrens[j]->collideWhith( *this->_childrens[i] );
					}
				}
			}
		}
	}
}

void			GameObject::collideWhith( GameObject const & colided )
{
	(void)colided;
}

bool			GameObject::collide( GameObject & a , GameObject & b ) const
{
		// std::stringstream ss;
		// ss << (int)a.getPos().getX() << std::endl;
		// ss << (int)b.getPos().getX() << std::endl;
		// printw(ss.str().c_str());
	if ( (int)a.getPos().getX() == (int)b.getPos().getX() &&
		 (int)a.getPos().getY() == (int)b.getPos().getY() )
	{
		return ( true );
	}
	return ( false );
}

void 			GameObject::inputAll( float delta )
{
	input( delta );

	for ( int i = 0; i < this->_nbChildrens; i++ )
	{
		if ( this->_childrens[i] && !this->_childrens[i]->_dead )
			this->_childrens[i]->inputAll( delta );
	}
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
	{
		if ( this->_childrens[i] && !this->_childrens[i]->_dead )
			this->_childrens[i]->updateAll( delta );
	}
}

void			GameObject::update( float delta )
{
	for ( int i = 0; i < this->_nbComponents; i++ )
	{
		this->_components[i]->update( delta );
	}
}

void			GameObject::setCoreEngine( CoreEngine & engine )
{
	if ( this->_coreEngine != &engine )
	{
		this->_coreEngine = &engine;
		for ( int i = 0; i < this->_nbChildrens; i++ )
		{
			if ( this->_childrens[i] && !this->_childrens[i]->_dead )
				this->_childrens[i]->setCoreEngine( engine );
		}
	}
}

void				GameObject::setPos( Vector2f & value )
{
	this->_pos = &value;

	return ;
}

Vector2f &			GameObject::getPos() const
{
	return ( *this->_pos );
}

GameObject &		GameObject::getParent() const
{
	return ( *this->_parent );
}

GameObject * const *		GameObject::getChildrens() const
{
	return ( this->_childrens );
}

int					GameObject::getNbChildrens() const
{
	return ( this->_nbChildrens );
}


// GameObject *		GameObject::getAllChildrens() const
// {
// 	int		size = this->getNbOfAllChildrens();

// 	GameObject *	res = GameObject[size];

// 	int		added = 0;

// 	this->storeGameObject( res, &added );

// 	return ( res );
// }

// int					GameObject::storeGameObject( GameObject & array, int * pos ) const
// {
// 	int		added = 0;

// 	for ( int i = 0; i < this->_nbChildrens; i++ )
// 	{
// 		added += this->_childrens[i]->storeGameObject( array, pos );
// 		array[added + pos] = this;
// 	}
// }

int					GameObject::getNbOfAllChildrens() const
{
	int		res;

	for ( int i = 0; i < this->_nbChildrens; i++ )
	{
		if ( this->_childrens[i] && !this->_childrens[i]->_dead )
			res += this->_childrens[i]->getNbOfAllChildrens();
	}

	res += this->_nbChildrens;

	return ( res );
}

// GameComponent &		GameObject::getComponents() const
// {
// 	return ( *this->_components );
// }

int					GameObject::getNbComponents() const
{
	return ( this->_nbComponents );
}


CoreEngine &		GameObject::getCoreEngine() const
{
	return ( *this->_coreEngine );
}
