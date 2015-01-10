/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:36:20 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 17:06:34 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME
# define GAME
# include "GameObject.hpp"

class Game
{
public:
	Game( void );
	Game( Game const & src );
	virtual ~Game( void );

	GameObject &	getRootObject();

	virtual void	input( float delta );
	virtual void	update( float delta );
	virtual void	render( float delta );
	virtual void	addObject( GameObject & object );

	virtual bool	init( void ) = 0;

	Game &			operator=( Game const & rhs );

private:
	GameObject *	_root;
};

#endif
