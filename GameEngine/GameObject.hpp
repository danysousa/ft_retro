/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 19:16:54 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT
# define GAME_OBJECT
# include "Vector2f.hpp"
# include "GameComponent.hpp"
# include "RenderEngine.hpp"

class CoreEngine;

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
	virtual void		init( CoreEngine & coreEngine );
	// GameObject &		getChildrens() const;
	int					getNbChildrens() const;
	// GameComponent &		getComponents() const;
	int					getNbComponents() const;
	CoreEngine &		getCoreEngine() const;
	void				setPos( Vector2f & value );
	void				setCoreEngine( CoreEngine & engine );

protected:
	Vector2f *			_pos;
	GameObject *		_childrens[256];
	int					_nbChildrens;
	GameComponent *		_components[256];
	int					_nbComponents;
	CoreEngine *		_coreEngine;
};

#endif
