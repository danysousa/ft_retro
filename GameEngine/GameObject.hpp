/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 18:45:32 by rbenjami         ###   ########.fr       */
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

	void				addChild( GameObject & child );
	void				addComponent( GameComponent & component );
	void				renderAll( RenderEngine & renderEngine );
	void				render( RenderEngine & renderEngine );

private:
	Vector2f *			_pos;
	GameObject *		_childrens;
	int					_nbChildrens;
	GameComponent *		_components;
	int					_nbComponents;

};

#endif
