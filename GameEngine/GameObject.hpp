/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 22:18:44 by rbenjami         ###   ########.fr       */
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
	GameObject &		getChildrens() const;
	int					getNbChildrens() const;
	GameComponent &		getComponents() const;
	int					getNbComponents() const;

protected:
	Vector2f *			_pos;
	GameObject *		_childrens;
	int					_nbChildrens;
	GameComponent *		_components;
	int					_nbComponents;

};

#endif
