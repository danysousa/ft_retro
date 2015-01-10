/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:36:20 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/10 13:55:41 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME
# define GAME

class Game
{
public:
	Game( void );
	Game( Game const & src );
	virtual ~Game( void );

	virtual bool	init( void );

	Game &			operator=( Game const & rhs );

};

#endif
