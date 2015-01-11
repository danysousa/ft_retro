/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:57:25 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 15:08:30 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET
# define BULLET
# include "../GameEngine/GameObject.hpp"
# include "../GameEngine/Vector2f.hpp"

class Bullet : public GameObject
{
public:
	Bullet( void );
	Bullet( std::string const & display, Vector2f & velocity );
	Bullet( Bullet const & src );
	virtual ~Bullet( void );

	Bullet &		operator=( Bullet const & rhs );

	void			init( std::string const & display, Vector2f & velocity );

};

#endif
