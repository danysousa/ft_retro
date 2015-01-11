/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 11:40:36 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT
# define GAME_OBJECT
# include "Vector2f.hpp"
# include "GameComponent.hpp"
# include "RenderEngine.hpp"

class GameObject
{
public:
	GameObject( void );
	GameObject( GameObject const & src );
	virtual ~GameObject( void );

	GameObject &		operator=( GameObject const & rhs );

	Vector2f &			getPos() const;

	virtual void		addChild( GameObject & child );
	virtual void		addComponent( GameComponent & component );
	virtual void		renderAll( RenderEngine & renderEngine );
	virtual void		render( RenderEngine & renderEngine );
	virtual void		inputAll( float delta );
	virtual void		input( float delta );
	virtual void		updateAll( float delta );
	virtual void		update( float delta );
	// GameObject &		getChildrens() const;
	int					getNbChildrens() const;
	// GameComponent &		getComponents() const;
	int					getNbComponents() const;

protected:
	Vector2f *			_pos;
	GameObject *		_childrens[256];
	int					_nbChildrens;
	GameComponent *		_components[256];
	int					_nbComponents;

};

#endif