/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveComponent.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 12:13:21 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/11 15:55:37 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVECOMPONENT
# define MOVECOMPONENT
# include "../GameEngine/GameComponent.hpp"
# include "../GameEngine/Vector2f.hpp"

class MoveComponent : public GameComponent
{
	public:
		MoveComponent( void );
		MoveComponent( float speed );
		MoveComponent( MoveComponent const & src );
		virtual ~MoveComponent( void );

		MoveComponent &		operator=( MoveComponent const & rhs );

		virtual void		update( float delta );
		Vector2f *			getVelocity( void ) const;
		float				getSpeed( void ) const;
		void				setVelocity( Vector2f *value );
		void				setSpeed( float value );

	protected:
		Vector2f *			_velocity;
		float				_speed;

};

#endif
