/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameComponent.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:38:44 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 22:34:58 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_COMPONENT
# define GAME_COMPONENT
# include "RenderEngine.hpp"
// # include "GameObject.hpp"

class GameComponent
{
public:
	GameComponent( void );
	GameComponent( GameComponent const & src );
	virtual ~GameComponent( void );

	virtual void	input( float delta );
	virtual void	update( float delta );
	virtual void	render( RenderEngine & renderEngine );

	// GameObject &			getParent() const;

	GameComponent &			operator=( GameComponent const & rhs );

private:
	// GameObject *			_parent;
};

#endif
