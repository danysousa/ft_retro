/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 19:15:17 by rbenjami         ###   ########.fr       */
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

	GameObject &			operator=( GameObject const & rhs );

	Vector2f &				getPos() const;

	virtual void			addChild( GameObject & child );
	virtual void			removeChild( GameObject & child );
	virtual void			addComponent( GameComponent & component );
	virtual void			renderAll( RenderEngine & renderEngine );
	virtual void			render( RenderEngine & renderEngine );
	virtual void			inputAll( float delta );
	virtual void			input( float delta );
	virtual void			updateAll( float delta );
	virtual void			update( float delta );
	virtual void			physicAll( float delta );
	virtual void			init( CoreEngine & coreEngine );
	virtual void			collideWhith( GameObject const & colided );

	GameObject * const *	getChildrens() const;
	int						getNbChildrens() const;
	int						getNbOfAllChildrens() const;
	// GameComponent &		getComponents() const;
	int						getNbComponents() const;
	CoreEngine &			getCoreEngine() const;
	GameObject &			getParent() const;
	void					setPos( Vector2f & value );
	void					setCoreEngine( CoreEngine & engine );
	// GameObject *			getAllChildrens() const;

protected:
	Vector2f *				_pos;
	GameObject *			_childrens[256];
	int						_nbChildrens;
	GameComponent *			_components[256];
	int						_nbComponents;
	CoreEngine *			_coreEngine;

private:
	// int					storeGameObject( GameObject & array, int * pos ) const;
	bool					collide( GameObject & a , GameObject & b ) const;
	int						_index;
	GameObject *			_parent;
	bool					_dead;
};

#endif
