/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:57:25 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:52:26 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET
# define BULLET
# include "../GameEngine/GameObject.hpp"
# include "../GameEngine/Vector2f.hpp"
# include "Player.hpp"

class Bullet : public GameObject
{
public:
	Bullet( void );
	Bullet( Player & owner, std::string const & display, Vector2f & velocity );
	Bullet( Bullet const & src );
	virtual ~Bullet( void );

	Bullet &		operator=( Bullet const & rhs );

	void			init( std::string const & display, Vector2f & velocity );
	Player &		getOwner() const;

	virtual void	collideWhith( GameObject const & colided );
	virtual void	update( float  delta );;

private:
	Player *		_owner;
};

#endif
